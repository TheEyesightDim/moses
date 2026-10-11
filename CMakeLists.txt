cmake_minimum_required(VERSION 4.0)
project(moses LANGUAGES C VERSION 0.0.0.0)

set(CMAKE_C_STANDARD 23)
set(CLIENT_PLATFORM "sdl3" CACHE STRING "The client to compile with the emulator (only sdl3 is available at the moment)")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_compile_definitions(MOSES_VER="${CMAKE_PROJECT_VERSION}")

# Add emulator core executable
add_subdirectory(src/emu)

# Add and link moses-client based on platform
if(CLIENT_PLATFORM STREQUAL "sdl3")
    add_subdirectory(src/moses-pc)
else()
    message(WARNING "specified client not recognized")
endif()

target_link_libraries(moses
        PRIVATE
        moses-client
)

# Add tests
enable_testing()
add_subdirectory(tests)
