#include "core/Application.h"

namespace Anvil {

  Application* Application::s_Instance = nullptr;

  Application::Application(std::string_view name /* = "Anvil application" */) : m_Name(name) {

    // Application can only be instantiated once
    if (Application::s_Instance != nullptr) {
      AV_CORE_CRIT("Application already instantiated");
    }

    Application::s_Instance = this;
  };

  void Application::Run() { std::cin.get(); }

  void Application::Close() { fmt::print("Application::Close()\n"); }

} // namespace Anvil
