#pragma once

#include "core/Application.h"

extern Anvil::Application* Create();

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
  // Initialize logger
  Anvil::Log::Init();

  // Get application pointer from the client
  Anvil::Application* app = Create();

  // Application main loop
  app->Run();

  // Application exit
  app->Close();

  return 0;
}

