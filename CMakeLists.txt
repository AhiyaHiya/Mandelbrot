cmake_minimum_required(VERSION 3.19.0)

project(mandelbrot VERSION 0.1.0)

# C17 and C++20
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)

# Folders for IDEs that support it
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# We need to specify these types since we are supporting multi-config IDEs like Xcode and Visual Studio
set(CMAKE_CONFIGURATION_TYPES "Debug" "Release")

# Add the CMake folder to the search path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake")

# Setup packages
include(ConanHelper)
include(ConanPackageSetup)

add_subdirectory(source)
