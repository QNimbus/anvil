#include "Log.h"

namespace Anvil
{
  std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
  std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

  void Log::Init() {
    // Setup formatting (see: https://github.com/gabime/spdlog/wiki/3.-Custom-formatting)
    spdlog::set_pattern("%^[%T]:%-4n:%-8l| %v%$");

    Log::s_CoreLogger = spdlog::stderr_color_mt("CORE");
    Log::s_ClientLogger = spdlog::stderr_color_mt("APP");

    Log::s_CoreLogger->set_level(spdlog::level::trace);
    Log::s_ClientLogger->set_level(spdlog::level::trace);
  }
}
