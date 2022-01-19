#pragma once

extern Anvil::Application* ::Anvil::Create();

int main(int argc, char* argv[])
{
  // Initialize logger class
  ::Anvil::Log::initialize();

  // Create heap allocated application object
  auto app = ::Anvil::Create();

  // Run application initialization
  app->Initialize();

  // Main application loop
  app->Run();

  // Application shutdown
  app->Shutdown();

  // Destroy heap allocated application object
  delete app;

  return 0;
}
