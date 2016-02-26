cmake_minimum_required(VERSION 3.3)
project(icpc4232)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES icpc4232.cpp)
add_executable(icpc4232 ${SOURCE_FILES})