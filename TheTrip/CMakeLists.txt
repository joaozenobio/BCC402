cmake_minimum_required(VERSION 3.22)
project(TheTrip C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(TheTrip
        src/main.c
        src/TheTrip.c
        src/TheTrip.h)
