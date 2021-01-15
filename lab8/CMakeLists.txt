cmake_minimum_required( VERSION 3.16.3 )
set (CMAKE_CXX_STANDARD 11)
project( lab8 )

find_package (Threads)


#include
include_directories( ./include/lab8 ./src )

#target
add_executable( lab8.exe ./src/main.cpp ./src/philosopher.cpp )
