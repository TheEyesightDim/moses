cmake_minimum_required(VERSION 4.0)
project(moses LANGUAGES C VERSION 0.0.0.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_compile_definitions(MOSES_VER="${CMAKE_PROJECT_VERSION}")

add_subdirectory(src/emu)
add_subdirectory(src/moses-pc)
