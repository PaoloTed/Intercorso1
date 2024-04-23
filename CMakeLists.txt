cmake_minimum_required(VERSION 3.27)
project(lasd)

set(CMAKE_CXX_STANDARD 17)

add_executable(lasd main.cpp
        container/dictionary.cpp
        vector/vector.hpp
        container/linear.hpp
        container/linear.cpp)
