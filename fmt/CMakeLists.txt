cmake_minimum_required(VERSION 3.22)
project(fmt C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(fmt
        src/fmt.c
        src/fmt.h
        src/main.c)
