cmake_minimum_required(VERSION 3.27)
project(Lab2v2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab2v2 ui.c
        service.c
        service.h
        tests.c
        tests.h)
