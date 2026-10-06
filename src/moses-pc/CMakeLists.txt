cmake_minimum_required(VERSION 4.0)
project(moses-pc C)

set(CMAKE_C_STANDARD 23)

add_library(moses-client STATIC)

target_include_directories(moses-client
        PUBLIC ../../include
)
target_sources(moses-client
        PRIVATE
        debug.c
)
target_link_libraries(moses
        PRIVATE
        moses-client
)
