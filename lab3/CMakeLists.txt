cmake_minimum_required( VERSION 3.16.3 )

project( lab4 )

#include
include_directories( ./include ./src )

#target
add_executable( test ./src/main.cpp ./src/matrix.cpp ./src/matrix.h)
