cmake_minimum_required(VERSION 3.21)
project(projet_c_l1 C)

set(CMAKE_C_STANDARD 99)

add_executable(projet_c_l1 main.c mat.c mat.h takuzu.c takuzu.h util.c util.h grids.h io.c io.h)
