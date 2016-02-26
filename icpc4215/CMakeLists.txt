cmake_minimum_required(VERSION 3.3)
project(icpc4215)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES icpc4215.cpp)
add_executable(icpc4215 ${SOURCE_FILES})