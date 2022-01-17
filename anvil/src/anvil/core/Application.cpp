#include "avpch.h"
#include "Application.h"

namespace Anvil
{

  Application* Application::s_Instance = nullptr;

  /*
  * Constructor
  */
  Application::Application(const std::string& name)
    : m_AppName(name)
  {
    AV_CORE_ASSERT(s_Instance == nullptr, "Application already instantiated");

    s_Instance = this;
  }

  void Application::Initialize()
  {
    AV_CORE_TRACE("Initializing - {0}", this->m_AppName);
  }

  void Application::Run()
  {
    AV_CORE_TRACE("Starting application loop - {0}", this->m_AppName);

    while (m_Running) {
      // Update layers from back to front
      std::for_each(m_LayerStack.rbegin(), m_LayerStack.rend(), [](const Layer* layer) {
        layer->OnUpdate();
        });
    }

    AV_CORE_TRACE("Stopping application loop - {0}", this->m_AppName);
  }

  void Application::Close()
  {
    AV_CORE_TRACE("Stopping - {0}", this->m_AppName);

    m_Running = false;
  }

  void Application::PushLayer(Layer* layer)
  {
    m_LayerStack.PushLayer(layer);
  }

  void Application::PushOverlay(Layer* layer)
  {
    m_LayerStack.PushOverlay(layer);
  }
}

