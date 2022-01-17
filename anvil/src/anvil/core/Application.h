#pragma once

#include "Anvil.h"

namespace Anvil
{
  class Application
  {
  public:
    // Constructors & Destructor
    virtual ~Application() = default;

    // Disable copy and move
    Application(const Application& other) = delete;
    Application(Application&& other)      = delete;
    Application& operator=(const Application&) = delete;
    Application& operator=(Application&&)      = delete;

    // Member methods
    void run();
    void close();

  protected:
    Application(const std::string& name = "Anvil app");

  private:
    std::string m_AppName;
    bool m_Running = true;

    static Application* s_Instance;
  };

  // The method Anvil::Create() needs to be implemented by the client code
  Application* Create();
}


