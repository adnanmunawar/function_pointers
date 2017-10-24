# This is a CMake example for Python
cmake_minimum_required(VERSION 3.0)


INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(pointer_test src/pointer_test.cpp)
