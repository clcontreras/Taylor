cmake_minimum_required(VERSION 3.25)
project(Taylor C)

set(CMAKE_C_STANDARD 17)

add_executable(Taylor main.c main_aux.c main_aux.h)
