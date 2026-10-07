cmake_minimum_required(VERSION 4.0)
project(moses-pc C)

set(CMAKE_C_STANDARD 23)

add_library(moses-client STATIC)
add_subdirectory(external/SDL EXCLUDE_FROM_ALL)

target_include_directories(moses-client
        PUBLIC
        "${CMAKE_SOURCE_DIR}/include"
        ./external/SDL/include
)
target_sources(moses-client
        PRIVATE
        debug.c
        video.c
        events.c
)
target_link_libraries(moses
        PRIVATE
        moses-client
        SDL3::SDL3
)
