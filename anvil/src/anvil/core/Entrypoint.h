#pragma once

extern Anvil::Application* Anvil::Create();

int main(int argc, char* argv[])
{
  // Create heap allocated application object
  auto app = Anvil::Create();

  // Main application loop
  app->run();

  // Destroy heap allocated application object
  delete app;

  return 0;
}
