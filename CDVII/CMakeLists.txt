cmake_minimum_required(VERSION 3.22)
project(CDVII C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(CDVII
        src/CDVII.c
        src/CDVII.h
        src/main.c)
