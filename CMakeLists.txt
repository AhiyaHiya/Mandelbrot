cmake_minimum_required(VERSION 3.19.0)

project(Mandelbrot VERSION 0.2.0)

# Conan integration
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

# C17 and C++20
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)

# Folders for IDEs that support it
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# We need to specify these types since we are supporting multi-config IDEs like Xcode and Visual Studio
set(CMAKE_CONFIGURATION_TYPES "Debug" "Release")

# Not needed yet
#find_package(CImg REQUIRED)
find_package(GTest REQUIRED)

add_subdirectory(Mandelbrot)
