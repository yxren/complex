cmake_minimum_required(VERSION 3.8)
project(complex)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp r_complex.h)
add_executable(complex ${SOURCE_FILES})