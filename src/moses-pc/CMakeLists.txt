cmake_minimum_required(VERSION 4.0)
project(moses-pc C)

set(CMAKE_C_STANDARD 23)

option(SDL_VENDORED "Use vendored SDL3" ON)
if(SDL_VENDORED)
    add_subdirectory(external/SDL EXCLUDE_FROM_ALL)
else()
    find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
endif()

if(BUILD_SHARED_LIBS)
    add_library(moses-client SHARED)
else()
    add_library(moses-client STATIC)
endif()

target_include_directories(moses-client
        PUBLIC
        "${CMAKE_SOURCE_DIR}/include"
        ./external/SDL/include
)
target_sources(moses-client
        PRIVATE
        debug.c
        video.c
        client.c
)
target_link_libraries(moses-client
        PRIVATE
        SDL3::SDL3
)

target_link_libraries(moses
        PRIVATE
        moses-client
)
