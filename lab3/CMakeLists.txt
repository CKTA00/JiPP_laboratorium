cmake_minimum_required( VERSION 3.16.3 )

project( lab4 )

#include
include_directories( ./include/lab4 ./src )

#target
add_executable( test.out ./src/main.cpp ./src/matrix.cpp ./src/matrix_exceptions.cpp )
