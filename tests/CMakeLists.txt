cmake_minimum_required(VERSION 4.0)
project(moses-test C)

set(CMAKE_C_STANDARD 23)

add_executable(test_mem test_mem.c)
target_include_directories(test_mem PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(test_mem PUBLIC moses-core)

add_test(NAME TestMem COMMAND test_mem)