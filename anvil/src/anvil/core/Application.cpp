#include "avpch.h"
#include "Application.h"

#include "anvil/event/Event.h"
#include "anvil/event/ApplicationEvent.h"

namespace Anvil
{

    Application* Application::s_Instance = nullptr;

    /*
    * Constructor
    */
    Application::Application(const std::string& name)
        : m_AppName(name) {
        AV_CORE_ASSERT(s_Instance == nullptr, "Application already instantiated");

        s_Instance = this;
    }

    void Application::Initialize() {
        AV_CORE_TRACE("Initialize - {0}", this->m_AppName);

        // Register event handlers
        EventBus::instance().Subscribe(this, &Application::onWindowClose);
        //EventBus::instance().Subscribe(this, &Application::onEvent);
    }

    void Application::Run() {
        AV_CORE_TRACE("Starting application loop - {0}", this->m_AppName);

        while (m_Running) {
          // Update layers from back to front
            std::for_each(m_LayerStack.rbegin(), m_LayerStack.rend(), [](Layer* layer) {
                // Call layer onUpdate event handler
                layer->onUpdate();
                          });

            // Publish application update event
            EventBus::instance().Publish(Events::AppUpdateEvent({ 0.016f }));
        }

        AV_CORE_TRACE("Stopping application loop - {0}", this->m_AppName);
    }

    void Application::Shutdown() {
        AV_CORE_TRACE("Shutdown - {0}", this->m_AppName);

        m_Running = false;

        // Publish shutdown event
        EventBus::instance().Publish(Events::AppShutdownEvent({}));
    }

    void Application::onEvent(const Event& event) {
        // Propagate events to layers
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

