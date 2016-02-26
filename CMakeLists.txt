cmake_minimum_required(VERSION 3.3)
project(ACM_ICPC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    2006/icpc2006.cpp)

add_executable(ACM_ICPC ${SOURCE_FILES})