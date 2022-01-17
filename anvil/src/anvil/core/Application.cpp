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
    s_Instance = this;
  }

  void Application::run()
  {
    while (m_Running) {
      
    }
  }

  void Application::close()
  {
    m_Running = false;
  }
}

