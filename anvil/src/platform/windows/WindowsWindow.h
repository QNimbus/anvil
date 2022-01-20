#pragma once

#include "anvil/core/Window.h"
#include "anvil/renderer/GraphicsContext.h"

// Forward declaration of GLFWwindow, GLFWMonitor
struct GLFWwindow;
struct GLFWmonitor;

namespace Anvil
{

    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(const WindowProperties& properties);

        // Inherited via Window
        virtual void        Close() const override;
        virtual uint32_t    GetWidth() const override { return m_Data.width; };
        virtual uint32_t    GetHeight() const override { return m_Data.height; };
        virtual void*       GetNativeWindow() const override;

        virtual void        SetEventCallback(const EventCallbackFn& callback) override { m_Data.eventCallback = callback; };

        void EnableVSync(bool enabled);

        // Event hooks
        virtual void onUpdate() const override;

    private:
        void RegisterEventCallbacks();

    private:
        struct WindowData
        {
            uint32_t width, height;
            GLFWmonitor* primaryMonitor;
            EventCallbackFn eventCallback;
            bool vSync;
            bool fullScreen;

            std::string title;

            WindowData(uint32_t width, uint32_t height, bool vSync, bool fullScreen, std::string title)
                : width(width), height(height), vSync(vSync), fullScreen(fullScreen), primaryMonitor(nullptr) {};
        };

    private:
        WindowData m_Data;
        Scope<GraphicsContext> m_Context;

        GLFWwindow* m_Window;

        static bool s_Initialized;
    };

}
