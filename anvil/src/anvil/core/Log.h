#pragma once

#pragma warning(push, 0) 
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#pragma warning(pop)

namespace Anvil
{

  class Log
  {
  public:
    static void initialize();

    static std::shared_ptr<spdlog::logger>& GetCoreLogger()   { return s_CoreLogger; }
    static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

  private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
  };
}

// Core logging macros
#define AV_CORE_TRACE(...)    ::Anvil::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AV_CORE_INFO(...)     ::Anvil::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AV_CORE_WARN(...)     ::Anvil::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AV_CORE_ERROR(...)    ::Anvil::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AV_CORE_CRITICAL(...) ::Anvil::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client logging macros
#define AV_TRACE(...)         ::Anvil::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AV_INFO(...)          ::Anvil::Log::GetClientLogger()->info(__VA_ARGS__)
#define AV_WARN(...)          ::Anvil::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AV_ERROR(...)         ::Anvil::Log::GetClientLogger()->error(__VA_ARGS__)
#define AV_CRITICAL(...)      ::Anvil::Log::GetClientLogger()->critical(__VA_ARGS__)
