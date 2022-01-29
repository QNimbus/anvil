#pragma once

#if defined(DEBUG)
# if defined(AV_PLATFORM_WINDOWS)
#   define AV_DEBUGBREAK() __debugbreak()
# elif defined(AV_PLATFORM_LINUX)
#   include <signal.h>
#    if defined(SIGTRAP)
#      define AV_DEBUGBREAK() raise(SIGTRAP)
#    else
#      define AV_DEBUGBREAK() raise(SIGABRT)
#    endif
# elif defined(AV_PLATFORM_DARWIN)
#   error "Platform doesn't support debugbreak() yet!"
# else
#   error "Platform doesn't support debugbreak() yet!"
# endif
#endif
