cmake_minimum_required(VERSION 3.3)
project(icpc6150)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES icpc6150.cpp)
add_executable(icpc6150 ${SOURCE_FILES})