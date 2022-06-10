cmake_minimum_required(VERSION 3.22)
project(Expressions C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(Expressions
        src/Expressions.c
        src/Expressions.h
        src/main.c)
