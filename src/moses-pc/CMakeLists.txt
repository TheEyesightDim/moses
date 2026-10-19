cmake_minimum_required(VERSION 4.0)
project(moses-pc C)

set(CMAKE_C_STANDARD 23)

add_executable(moses)

# Link SDL3
option(SDL_VENDORED "Use vendored SDL3" ON)
if(SDL_VENDORED)
    add_subdirectory(external/SDL EXCLUDE_FROM_ALL)
else()
    find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
endif()
target_link_libraries(moses
        PRIVATE
        SDL3::SDL3
        moses-core
)

target_include_directories(moses
        PUBLIC
        "${CMAKE_SOURCE_DIR}/include"
        ./external/SDL/include
)
target_sources(moses
        PRIVATE
        debug.c
        video.c
        client.c
)
