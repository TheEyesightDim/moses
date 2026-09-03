cmake_minimum_required(VERSION 4.0)
project(moses-pc C)

set(CMAKE_C_STANDARD 23)

add_executable(MosES)
target_sources(MosES
    PRIVATE
        main.c
)
target_link_libraries(MosES
    PRIVATE
        MosesCore
)
