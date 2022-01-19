#pragma once

#include "anvil/core/Core.h"
#include "anvil/core/Layer.h"
#include "anvil/core/LayerStack.h"
#include "anvil/event/EventBus.h"
#include "anvil/event/WindowEvent.h"

namespace Anvil
{
    using namespace Events;

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

        static Application* Get() { return s_Instance; }

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        // Event handlers{};
        void onEvent(const Event& event);
        void onWindowClose(const WindowCloseEvent& event) { event.handled = true; m_Running = false; };

    protected:
        // Disable direct instantiation
        Application(const std::string& name = "Anvil app");

    private:
        std::string m_AppName;
        bool m_Running = true;

        // Overlay and regular layers
        LayerStack m_LayerStack;

        // Only one application instance allowed
        static Application* s_Instance;
    };

    // The method Anvil::Create() needs to be implemented by the client code
    Application* Create();
}


