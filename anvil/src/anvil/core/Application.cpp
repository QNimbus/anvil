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
  }

  void Application::Run()
  {
    AV_CORE_TRACE("Starting {0}...", this->m_AppName);
    while (m_Running) {
      
    }
  }

  void Application::Close()
  {
    AV_CORE_TRACE("Stopping {0}...", this->m_AppName);

    m_Running = false;
  }
}

