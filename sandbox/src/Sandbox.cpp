#include "sbpch.h"

#include "anvil/core/Entrypoint.h"

namespace Anvil
{
  class SandboxApplication : public Anvil::Application
  {
  public:
    SandboxApplication(const std::string& name)
      : Application(name)
    {

    }

  private:
  };

  /*
  * This function gets called by the Anvil library entrypoint
  */
  Application* Create()
  {
    auto app = new SandboxApplication("Sandbox app");

    return app;
  }
}
