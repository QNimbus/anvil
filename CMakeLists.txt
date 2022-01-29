# Sets the minimum required version of cmake for a project.
# See: https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html
cmake_minimum_required(VERSION 3.20...3.22)

# Uncomment to set a default CXX standard for the external tools like clang-tidy and cppcheck
# and the targets that do not specify a standard.
# If not set, the latest supported standard for your compiler is used
# You can later set fine-grained standards for each target using `target_compile_features`
set(CMAKE_CXX_STANDARD 20) # Set to '23' to have -std:c++latest as compiler flag (to prevent issue with c++20 and clang-tidy)

# Add project_options v0.1.1 - https://github.com/qnimbus/cpp-project-options
# See: https://cmake.org/cmake/help/latest/module/FetchContent.html
include(FetchContent)
FetchContent_Declare(_project_options URL https://github.com/QNimbus/cpp-project-options/archive/refs/tags/v0.1.3.zip)
FetchContent_MakeAvailable(_project_options)
include(${_project_options_SOURCE_DIR}/Index.cmake)

# ************************   CHANGE ME   ************************
# Set the project name and language
# See: https://cmake.org/cmake/help/latest/command/project.html
project(anvil
        HOMEPAGE_URL https://github.com/qnimbus/cpp-starter-project
        LANGUAGES CXX
        DESCRIPTION "Anvil game engine")
# ************************ / CHANGE ME   ************************

# Initialize project_options variable related to this project
# This overwrites `project_options` and sets `project_warnings`
# uncomment the options to enable them:
project_options(
      WARNINGS_AS_ERRORS
   #  ENABLE_CLANG_TIDY         # Does not work with compilers other than clang
      ENABLE_PCH
      ENABLE_CONAN
      PCH_HEADERS
        <memory>
        <string>
        <vector>
        <iostream>
        <core/Log.h>
        <fmt/format.h>
      # CONAN_OPTIONS
      )

# Enable experimental preprocessor for MSVC to enable support for __VA_OPT__
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/Zc:preprocessor>")

add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>")
add_compile_options("$<$<PLATFORM_ID:Windows>:-DAV_PLATFORM_WINDOWS>")
add_compile_options("$<$<PLATFORM_ID:Darwin>:-DAV_PLATFORM_DARWIN>")
add_compile_options("$<$<PLATFORM_ID:Linux>:-DAV_PLATFORM_LINUX>")

target_compile_features(project_options INTERFACE cxx_std_20)

# Make 'start' project the Visual Studio startup project
# See: https://cmake.org/cmake/help/latest/prop_dir/VS_STARTUP_PROJECT.html
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT sandbox)

# Adding the anvil folder ('Anvil' project):
# See: https://cmake.org/cmake/help/latest/command/add_subdirectory.html
add_subdirectory(anvil)

# Adding the anvil folder ('Sandbox' project):
# See: https://cmake.org/cmake/help/latest/command/add_subdirectory.html
add_subdirectory(sandbox)
