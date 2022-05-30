cmake_minimum_required(VERSION 3.22)
project(AbelhaMaja C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(AbelhaMaja
        src/AbelhaMaja.c
        src/AbelhaMaja.h
        src/main.c)
