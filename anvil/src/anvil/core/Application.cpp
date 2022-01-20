#include "avpch.h"
#include "Application.h"

#include "anvil/core/Window.h"
#include "anvil/event/Event.h"
#include "anvil/event/ApplicationEvent.h"

namespace Anvil
{

    Application* Application::s_Instance = nullptr;

    /*
    * Constructor
    */
    Application::Application(const std::string& name)
        : m_AppName(name), m_EventBus(EventBus::instance()) {
        AV_CORE_ASSERT(s_Instance == nullptr, "Application already instantiated");

        s_Instance = this;
    }

    void Application::Initialize() {
        AV_CORE_TRACE("Initializing: {0}", this->m_AppName);

        // Subscribe application to events on the eventbus
        m_EventBus.Subscribe(this, &Application::onWindowClose);
        m_EventBus.Subscribe(this, &Application::onWindowResize);

        // Create application window
        m_Window = Window::Create({ m_AppName, 1600, 900 });
 
        // Route all incoming events to our application event handler Application::onEvent
        m_Window->SetEventCallback([this](const Event& event) { onEvent(event); });
    }

    void Application::Run() {
        AV_CORE_TRACE("Application loop start: {0}", this->m_AppName);

        while (m_Running) {
            // Update application window
            m_Window->onUpdate();

            // Update layers from back to front
            std::for_each(m_LayerStack.rbegin(), m_LayerStack.rend(), [](Layer* layer) {
                // Call layer onUpdate event handler
                layer->onUpdate();
                          });
        }

        AV_CORE_TRACE("Application loop stop: {0}", this->m_AppName);
    }

    void Application::Shutdown() {
        AV_CORE_TRACE("Shutdown: {0}", this->m_AppName);

        m_Running = false;
    }

    template <typename EventType>
    void Application::onEvent(const EventType& event) {
        // Publish event on the event bus
         m_EventBus.Publish(event);

        // Propagate event to application layers if not yet handled
        if (!event.handled)
            for (auto layer : m_LayerStack) {
                layer->onEvent(event);
            }
    }

    void Application::PushLayer(Layer* layer) {
        m_LayerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer* layer) {
        m_LayerStack.PushOverlay(layer);
    }
}

