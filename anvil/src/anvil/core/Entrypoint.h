#pragma once

#include "avpch.h"

#include "anvil/core/Application.h"

int main(int argc, char* argv[]) {
  std::cout << "Entrypoint" << std::endl;

  auto app = Anvil::Create();

  app->run();

  return 0;
}
