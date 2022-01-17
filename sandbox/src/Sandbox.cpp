#include "sbpch.h"
// -- Entry Point ---------
#include <anvil/core/Entrypoint.h>
// -- Entry Point ---------

namespace Anvil
{
  class SandboxApplication : public Application
  {
  public:
    SandboxApplication(const std::string& name)
      : Application(name)
    {

    }

  private:
  };

  class SandboxLayer : public Layer
  {
  public:
    SandboxLayer()
      : Layer("Sandbox layer")
    { }

  private:
  };

  /*
  * This function gets called by the Anvil library entrypoint
  */
  Application* Create()
  {
    auto app = new SandboxApplication("Sandbox app");

    app->PushLayer(new SandboxLayer());

    return app;
  }
}
