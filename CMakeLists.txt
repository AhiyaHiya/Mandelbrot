cmake_minimum_required(VERSION 3.28)

project(mandelbrot VERSION 0.2.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

##
# vcpkg portion
if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
  set(bootstrap_vcpkg_ext "bat")
else()
  set(bootstrap_vcpkg_ext "sh")
endif()

execute_process(
  COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/vcpkg/bootstrap-vcpkg.${bootstrap_vcpkg_ext}"
  RESULT_VARIABLE bootstrap_vcpkg_result
)

if(NOT bootstrap_vcpkg_result EQUAL 0)
  message(FATAL_ERROR "Bootstrapping failed with code: ${bootstrap_vcpkg_result}")
else()
  message(STATUS "Bootstrapping succeeded.")
endif()

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "vcpkg toolchain file")

# Folders for IDEs that support it
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# We need to specify these types since we are supporting multi-config IDEs like Xcode and Visual Studio
set(CMAKE_CONFIGURATION_TYPES "Debug" "Release")

find_package(CImg CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

enable_testing()

add_library(mandelbrot STATIC
    "Include/MandelbrotSet.hpp"
    "Source/MandelbrotSet.cpp"
)
