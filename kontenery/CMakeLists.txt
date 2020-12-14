cmake_minimum_required( VERSION 3.16.3 )

project( kontenery )

#include
include_directories( ./include/kontenery ./src )

#target
add_executable( test.out ./src/main.cpp ./src/Employee.cpp ./src/HRMS.cpp )
