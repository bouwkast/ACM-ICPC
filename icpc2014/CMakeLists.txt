cmake_minimum_required(VERSION 3.3)
project(icpc2014)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES icpc2014.cpp)
add_executable(icpc2014 ${SOURCE_FILES})