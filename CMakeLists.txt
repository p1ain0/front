cmake_minimum_required(VERSION 3.10)

project(compiler_front)
include_directories(include)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
add_executable(compiler_front src/main.cpp src/type.cpp)