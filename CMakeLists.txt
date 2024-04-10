cmake_minimum_required(VERSION 3.27)
project(Intercorso1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Intercorso1 main.cpp
        container/dictionary.cpp
        vector/vector.hpp
        container/linear.hpp)
