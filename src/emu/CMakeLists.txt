cmake_minimum_required(VERSION 4.0)
project(moses-core C)

add_library(MosesCore SHARED)
target_include_directories(MosesCore PUBLIC ../../include)
target_sources(MosesCore
    PRIVATE
        cpu.c
)
