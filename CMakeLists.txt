cmake_minimum_required(VERSION 3.21)
project(projet_c_l1 C)

set(CMAKE_C_STANDARD 99)

add_executable(projet_c_l1 main.c game.c takuzu.c io.c util.c game.h takuzu.h io.h util.h grids.h)
