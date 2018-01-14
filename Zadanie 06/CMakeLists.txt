cmake_minimum_required(VERSION 3.9)
project(Zadanie_06)

set(CMAKE_CXX_STANDARD 11)

add_executable(Zadanie_06 main.cpp)

find_package(GSL REQUIRED)    # See below (2)
target_link_libraries(Zadanie_06 GSL::gsl GSL::gslcblas)