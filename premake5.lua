-- premake5.lua

include "./vendor/premake/customization/solution_items.lua"
include "./vendor/premake/includes/dependencies.lua"

workspace "Anvil"
  architecture "x86_64"                                             -- https://premake.github.io/docs/architecture
  configurations { "Debug", "Release", "Dist" }                     -- https://premake.github.io/docs/configurations

  startproject "Sandbox"                                            -- https://premake.github.io/docs/startproject

  flags { "MultiProcessorCompile" }                                 -- https://premake.github.io/docs/flags

  solution_items
  {
    ".editorconfig"
  }

  -- e.g. Debug-Windows-x64
  outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"   -- https://premake.github.io/docs/Tokens/

  group "Dependencies"

    -- include "anvil/vendor/GLFW"

  group ""

include "anvil"
include "forge"
include "sandbox"
