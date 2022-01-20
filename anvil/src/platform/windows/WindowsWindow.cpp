#include "avpch.h"
#include "WindowsWindow.h"

#include "anvil/event/EventBus.h"
#include "anvil/event/WindowEvent.h"

#include <GLFW/glfw3.h>

namespace Anvil
{
    // Static variable to track window count
    bool WindowsWindow::s_Initialized = false;

    Ref<Window> Window::Create(const WindowProperties& properties) {
        return std::make_shared<WindowsWindow>(properties);
    }

    WindowsWindow::WindowsWindow(const WindowProperties& properties)
        : m_Data({ properties.width, properties.height, properties.vSync, properties.fullScreen, properties.title }) {
        // First time initialization?
        if (!s_Initialized) {
            uint32_t success = glfwInit();

            if (success != GLFW_TRUE) {
                AV_CORE_ASSERT(false, "Unable to initialize GLFW");

                glfwTerminate();

                s_Initialized = false;
            } else {
                s_Initialized = true;
            }
        }

        if (m_Data.fullScreen) {
            m_Data.primaryMonitor = glfwGetPrimaryMonitor();
        }

        // Create window
        m_Window = glfwCreateWindow(m_Data.width, m_Data.height, m_Data.title.c_str(), m_Data.primaryMonitor, nullptr);

        // Set GLFW user pointer
        glfwSetWindowUserPointer(m_Window, &m_Data);
        
        // Create API context
        m_Context = GraphicsContext::Create(m_Window);
        m_Context->Init();

        EnableVSync(m_Data.vSync);

        // Register event callbacks
        RegisterEventCallbacks();
    }

    void* WindowsWindow::GetNativeWindow() const {
        return nullptr;
    }

    void WindowsWindow::EnableVSync(bool enabled) {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.vSync = enabled;
    }

    void WindowsWindow::onUpdate() const {
        glfwPollEvents();
        m_Context->SwapBuffers();
    };

    void WindowsWindow::Close() const {
        glfwDestroyWindow(m_Window);
    }

    void WindowsWindow::RegisterEventCallbacks() {// Access window user data
        /*
        * Window closed
        */
        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
            // Access window user data
            WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            // Construct event
            Events::WindowCloseEvent event;

            // Invoke callback with the constructed event
            data->eventCallback(event);
        });

        /*
        * Window resized
        */
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
            // Access window user data
            WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            // Construct event
            Events::WindowResizeEvent event { static_cast<uint32_t>(width), static_cast<uint32_t>(height) };

            // Invoke callback with the constructed event
            data->eventCallback(event);
        });

        /*
        * Window focus
        */
        glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused) {
            // Access window user data
            WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            Events::Event* event;

            if (focused == GLFW_TRUE)
                event = &Events::WindowFocusEvent();
            else
                event = &Events::WindowFocusLostEvent();

            // Invoke callback with the constructed event
            data->eventCallback(*event);
        });
    }
}
