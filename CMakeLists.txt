cmake_minimum_required(VERSION 3.6)
project(STL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Functor.cpp)
add_executable(STL ${SOURCE_FILES})