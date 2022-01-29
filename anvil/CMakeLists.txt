# Find a package (usually provided by something external to the project), and load its package-specific details.
# See: https://cmake.org/cmake/help/latest/command/find_package.html
find_package(spdlog)

set(
    source_list
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Anvil.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/anvil/core/Log.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/anvil/core/Application.cpp)

# Add executable target
# See: https://cmake.org/cmake/help/latest/command/add_library.html
add_library(anvil STATIC ${source_list})

target_include_directories(anvil PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/anvil
)

# Create the source groups for source tree with root at CMAKE_CURRENT_SOURCE_DIR.
# source_group("Source"           REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/[^/]*([.]c|[.]cpp)")
# source_group("Source\\Headers"  REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/[^/]*([.]h|[.]hpp)")
# source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" PREFIX "Implementation")

# See: https://cmake.org/cmake/help/latest/command/target_link_libraries.html
target_link_libraries(
  anvil
  PUBLIC  fmt::fmt
          spdlog::spdlog
  PRIVATE project_options)
