#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "core/Utilities.h"

#if defined(DEBUG)
// Define CORE log macro's

# define _AV_LOG_ARGS(fmt_string, ...)          fmt::format(fmt_string __VA_OPT__(,) __VA_ARGS__)
# define _AV_CORE_LOG_ARGS(fmt_string, ...)     fmt::format(fmt_string __VA_OPT__(,) __VA_ARGS__)
# define _AV_THROW_RUNTIME_EXC(fmt_string, ...) throw new std::runtime_error(fmt::format(fmt_string __VA_OPT__(,) __VA_ARGS__))

// TODO: Make this a constexpr that evaluates at compile time
// TODO: Make a __FILE__ macro that shows filename without full path
# define AV_TRACE(...)      ::Anvil::Log::GetClientLogger()->trace(_AV_LOG_ARGS(__VA_ARGS__))
# define AV_DEBUG(...)      ::Anvil::Log::GetClientLogger()->debug(_AV_LOG_ARGS(__VA_ARGS__)); AV_DEBUGBREAK()
# define AV_INFO(...)       ::Anvil::Log::GetClientLogger()->info(_AV_LOG_ARGS(__VA_ARGS__))
# define AV_WARN(...)       ::Anvil::Log::GetClientLogger()->warn(_AV_LOG_ARGS(__VA_ARGS__))
# define AV_ERROR(...)      ::Anvil::Log::GetClientLogger()->error(_AV_LOG_ARGS(__VA_ARGS__))
# define AV_CRIT(...)       ::Anvil::Log::GetClientLogger()->critical(_AV_LOG_ARGS(__VA_ARGS__)); _AV_THROW_RUNTIME_EXC(__VA_ARGS__)

# define AV_CORE_TRACE(...) ::Anvil::Log::GetCoreLogger()->trace(_AV_CORE_LOG_ARGS(__VA_ARGS__))
# define AV_CORE_DEBUG(...) ::Anvil::Log::GetCoreLogger()->debug(_AV_CORE_LOG_ARGS(__VA_ARGS__)); AV_DEBUGBREAK()
# define AV_CORE_INFO(...)  ::Anvil::Log::GetCoreLogger()->info(_AV_CORE_LOG_ARGS(__VA_ARGS__))
# define AV_CORE_WARN(...)  ::Anvil::Log::GetCoreLogger()->warn(_AV_CORE_LOG_ARGS(__VA_ARGS__))
# define AV_CORE_ERROR(...) ::Anvil::Log::GetCoreLogger()->error(_AV_CORE_LOG_ARGS(__VA_ARGS__))
# define AV_CORE_CRIT(...)  ::Anvil::Log::GetCoreLogger()->critical(_AV_CORE_LOG_ARGS(__VA_ARGS__)); _AV_THROW_RUNTIME_EXC(__VA_ARGS__)
#else
# define AV_TRACE(...)
# define AV_DEBUG(...)
# define AV_INFO(...)
# define AV_WARN(...)
# define AV_ERROR(...)
# define AV_CRIT(...)

# define AV_CORE_TRACE(...)
# define AV_CORE_DEBUG(...)
# define AV_CORE_INFO(...)
# define AV_CORE_WARN(...)
# define AV_CORE_ERROR(...)
# define AV_CORE_CRIT(...)
#endif

namespace Anvil
{
  class Log
  {
  public:
    static void Init();

    static std::shared_ptr<spdlog::logger> GetCoreLogger()   { return Log::s_CoreLogger; }
    static std::shared_ptr<spdlog::logger> GetClientLogger() { return Log::s_ClientLogger; }
     
  private:
    Log();
    ~Log() = default;

  private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
  };
}
