cmake_minimum_required(VERSION 3.0.0)
project(mandelbrot VERSION 0.1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

add_executable(mandelbrot source/cli/main.cpp)

include_directories(source)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
