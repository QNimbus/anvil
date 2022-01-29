#include "Anvil.h"

Anvil::Application* Create() {
  AV_TRACE("Creating application 'Sandbox'");

  return new Anvil::Application("Sandbox");
}
