#pragma once

#include "anvil/core/Core.h"
#include "anvil/core/Layer.h"
#include "anvil/core/Window.h"
#include "anvil/core/LayerStack.h"
#include "anvil/event/EventBus.h"
#include "anvil/event/WindowEvent.h"

namespace Anvil
{

    class Application
    {
    public:
        // Constructors & Destructor
        virtual ~Application() = default;

        // Disable copy and move
        Application(const Application& other) = delete;
        Application(Application&& other) = delete;
        Application& operator=(const Application&) = delete;
        Application& operator=(Application&&) = delete;

        // Member methods
        void Initialize();
        void Run();
        void Shutdown();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        static Application* Get() { return s_Instance; }

        // Cached access to event bus
        const Events::EventBus& GetEventBus() { return m_EventBus; }

        // Event handlers{};
        template <typename EventType>
        void onEvent(const EventType& event);
        void onWindowClose(const Events::WindowCloseEvent& event) { event.handled = true; m_Running = false; };
        void onWindowResize(const Events::WindowResizeEvent& event) { event.handled = true; };

    protected:
        // Disable direct instantiation
        Application(const std::string& name = "Anvil app");

    private:
        std::string m_AppName;
        bool m_Running = true;

        // Reference counted pointer to Window object
        Ref<Window> m_Window;

        // Overlay and regular layers
        LayerStack m_LayerStack;

        // Cached access to event bus
        EventBus& m_EventBus;

        // Only one application instance allowed
        static Application* s_Instance;
    };

    // The method Anvil::Create() needs to be implemented by the client code
    Application* Create();
}


