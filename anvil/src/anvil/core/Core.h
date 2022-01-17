#pragma once

#define BIT(x) (1 << x)

#ifdef AV_DEBUG
  #if defined(AV_PLATFORM_WINDOWS)
    #define AV_DEBUGBREAK() __debugbreak()
  #elif defined(AV_PLATFORM_LINUX)
    #include <signal.h>
    #define AV_DEBUGBREAK() raise(SIGTRAP)
  #else
    #error "Platform doesn't support debugbreak() yet!"
  #endif

  #define AV_ENABLE_ASSERTS

#else
  #define AV_DEBUGBREAK()
#endif

#include "anvil/core/Log.h"
#include "anvil/core/Assert.h"
