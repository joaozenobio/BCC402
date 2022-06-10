cmake_minimum_required(VERSION 3.22)
project(wertyu C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(wertyu
        src/main.c
        src/wertyu.c
        src/wertyu.h)
