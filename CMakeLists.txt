cmake_minimum_required(VERSION 3.25)
project(Taylor C)

set(CMAKE_C_STANDARD 17)

add_executable(Taylor main.c main_aux.c main_aux.h gsl_ode.c gsl_ode.h)

find_package(GSL REQUIRED)

target_link_libraries(Taylor GSL::gsl GSL::gslcblas m)
