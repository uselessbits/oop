cmake_minimum_required(VERSION 3.27)
project(Lab2v2 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -D_GLIBCXX_ASSERTIONS")

add_executable(Lab2v2 ui.c
        service.c
        service.h
        tests.c
        tests.h)
