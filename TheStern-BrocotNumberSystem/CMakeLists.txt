cmake_minimum_required(VERSION 3.22)
project(TheStern_BrocotNumberSystem C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(TheStern_BrocotNumberSystem
        src/main.c
        src/TheStern-BrocotNumberSystem.c
        src/TheStern-BrocotNumberSystem.h)
