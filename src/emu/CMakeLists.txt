cmake_minimum_required(VERSION 4.0)
project(moses-core C)

add_library(moses-core)

add_executable(moses main.c)
target_include_directories(moses-core PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_sources(moses-core
        PRIVATE
        emu.c
        mem.c
)
target_link_libraries(moses
        PRIVATE
        moses-client
        moses-core
)
