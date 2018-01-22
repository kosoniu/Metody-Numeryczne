cmake_minimum_required(VERSION 3.9)
project(GSL)

set(CMAKE_CXX_STANDARD 11)

add_executable(GSL main.cpp)

find_package(GSL REQUIRED)    # See below (2)
target_link_libraries(GSL GSL::gsl GSL::gslcblas)