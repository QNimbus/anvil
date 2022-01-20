-- anvil/vendor/glad/premake5.lua

project "glad"

  kind "StaticLib"                                                  -- https://premake.github.io/docs/kind
  staticruntime "off"                                               -- https://premake.github.io/docs/staticruntime

  language "C"                                                      -- https://premake.github.io/docs/language

  targetdir ("%{wks.location}/_bin/" .. outputdir .. "/%{prj.name}")
  objdir    ("%{wks.location}/_obj/" .. outputdir .. "/%{prj.name}")

  links                                                             -- https://premake.github.io/docs/links
  {

  }

  files                                                             -- https://premake.github.io/docs/files
  {
    "**.h",
    "**.c",
  }

  includedirs                                                       -- https://premake.github.io/docs/includedirs
  {
    "include"
  }

  defines                                                           -- https://premake.github.io/docs/defines
  {

  }

  -- https://premake.github.io/docs/filter/
  filter { "system:windows" }
    defines { }

  filter { "system:linux"}
    defines { }

  filter { "configurations:Debug" }
    defines { }
    symbols "on"                                                    -- https://premake.github.io/docs/symbols/
    runtime "Debug"                                                 -- https://premake.github.io/docs/runtime

  filter { "configurations:Release" }
    defines { }
    optimize "on"                                                   -- https://premake.github.io/docs/optimize
    runtime "Release"                                               -- https://premake.github.io/docs/runtime

  filter { "configurations:Dist" }
    defines { }
    optimize "full"                                                 -- https://premake.github.io/docs/optimize
    runtime "Release"                                               -- https://premake.github.io/docs/runtime

  filter {} -- Reset
