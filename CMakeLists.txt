cmake_minimum_required(VERSION 3.29)
project(poo)

set(CMAKE_CXX_STANDARD 26)

add_library(poo STATIC library.cpp
        library.h)
