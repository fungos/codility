cmake_minimum_required(VERSION 2.8)

project(codility)

list(APPEND CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
add_executable(codility codility.cpp)
