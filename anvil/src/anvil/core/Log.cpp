#include "avpch.h"
#include "Log.h"

namespace Anvil
{
  std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
  std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

  void Log::initialize()
  {
    // Setup formatting (see: https://github.com/gabime/spdlog/wiki/3.-Custom-formatting)
    spdlog::set_pattern("%^[%T]:%n:%-8l| %v%$");

    Log::s_CoreLogger = spdlog::stdout_color_mt("ANVIL");
    Log::s_CoreLogger->set_level(spdlog::level::trace);

    Log::s_ClientLogger = spdlog::stdout_color_mt("APP");
    Log::s_ClientLogger->set_level(spdlog::level::trace);
  }
}
