cmake_minimum_required(VERSION 3.22)
project(AustralianVoting C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(AustralianVoting
        src/AustralianVoting.c
        src/AustralianVoting.h
        src/main.c)
