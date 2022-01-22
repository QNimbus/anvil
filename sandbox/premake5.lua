-- sandbox/premake5.lua

project "Sandbox"

  kind "ConsoleApp"                                                 -- https://premake.github.io/docs/kind
  staticruntime "off"                                               -- https://premake.github.io/docs/staticruntime

  language "C++"                                                    -- https://premake.github.io/docs/language
  cppdialect "C++17"                                                -- https://premake.github.io/docs/cppdialect

  targetdir ("%{wks.location}/_bin/" .. outputdir .. "/%{prj.name}")
  objdir    ("%{wks.location}/_obj/" .. outputdir .. "/%{prj.name}")

  pchheader "sbpch.h"
  pchsource "%{prj.location}/src/sbpch.cpp"

  links                                                             -- https://premake.github.io/docs/links
  {
    "Anvil"
  }

  files                                                             -- https://premake.github.io/docs/files
  {
    "src/**.h",
    "src/**.cpp",
  }

  includedirs                                                       -- https://premake.github.io/docs/includedirs
  {
    "src/",
    "%{wks.location}/anvil/src",

    "%{IncludeDir.spdlog}/",
  }

  defines                                                           -- https://premake.github.io/docs/defines
  {

  }

  -- https://premake.github.io/docs/filter/
  filter { "system:windows" }
    defines { "AV_PLATFORM_WINDOWS" }
    buildoptions { "/permissive-" }

  filter { "system:linux"}
    defines { "AV_PLATFORM_LINUX" }
    buildoptions { "-Wpedantic" }

  filter { "configurations:Debug" }
    defines { "AV_DEBUG" }
    symbols "on"                                                    -- https://premake.github.io/docs/symbols/
    runtime "Debug"                                                 -- https://premake.github.io/docs/runtime

  filter { "configurations:Release" }
    defines { "AV_RELEASE" }
    optimize "on"                                                   -- https://premake.github.io/docs/optimize
    runtime "Release"                                               -- https://premake.github.io/docs/runtime

  filter { "configurations:Dist" }
    defines { "AV_DIST" }
    optimize "full"                                                 -- https://premake.github.io/docs/optimize
    runtime "Release"                                               -- https://premake.github.io/docs/runtime

  filter {} -- Reset
