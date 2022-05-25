cmake_minimum_required(VERSION 3.22)
project(StackemUp C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(StackemUp
        src/main.c
        src/StackemUp.c
        src/StackemUp.h)
