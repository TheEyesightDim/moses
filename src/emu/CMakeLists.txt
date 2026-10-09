cmake_minimum_required(VERSION 4.0)
project(moses-core C)

add_executable(moses
        cpu.c
        ../../include/moses/instructions.h)
target_include_directories(moses PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_sources(moses
        PRIVATE
        emu.c
)
target_link_libraries(moses
        PRIVATE
        moses-client
)
