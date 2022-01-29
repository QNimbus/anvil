set(
    source_list
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Main.cpp
)

# Add executable target
# See: https://cmake.org/cmake/help/latest/command/add_executable.html
add_executable(sandbox ${source_list})

target_include_directories(sandbox PRIVATE
  ${PROJECT_SOURCE_DIR}/anvil/src
  ${CMAKE_CURRENT_SOURCE_DIR}/src/include
)

# Create the source groups for source tree with root at CMAKE_CURRENT_SOURCE_DIR.
# source_group("Source"           REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/[^/]*([.]c|[.]cpp)")
# source_group("Source\\Headers"  REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/[^/]*([.]h|[.]hpp)")
# source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" PREFIX "Implementation")

# See: https://cmake.org/cmake/help/latest/command/target_link_libraries.html
target_link_libraries(
  sandbox
  PRIVATE project_options
          anvil)
