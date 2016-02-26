cmake_minimum_required(VERSION 3.3)
project(icpc2019)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES icpc2019.cpp)
add_executable(icpc2019 ${SOURCE_FILES})