cmake_minimum_required( VERSION 3.16.3 )

project( kalkulator_macierzy )
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)


find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net) 
include(${wxWidgets_USE_FILE})
include_directories( ./include/matrix ./include/app ./src )
add_executable( app.out WIN32 ./src/app.cpp ./src/matrix.cpp ./src/matrix_exceptions.cpp ./src/MainFrame.cpp ./src/ResultFrame.cpp ./src/UIMatrix.cpp ./src/PrecisionFrame.cpp)
target_link_libraries(app.out ${wxWidgets_LIBRARIES})


#set(wxWidgets_ROOT_DIR "C:\\wxWidgets-3.1.4")
#SET(wxWidgets_LIB_DIR "C:\\wxWidgets-3.1.4")
