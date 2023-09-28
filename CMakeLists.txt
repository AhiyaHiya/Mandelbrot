cmake_minimum_required(VERSION 3.19.0)

project(mandelbrot VERSION 0.1.0)

# C17 and C++20
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)

# Folders for IDEs that support it
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# We need to specify these types since we are supporting multi-config IDEs like Xcode and Visual Studio
set(CMAKE_CONFIGURATION_TYPES "Debug" "Release")

# Conan section
include(ConanHelper.cmake)

# CImg package ( http://cimg.eu/reference/tutorial.html )
conan_cmake_configure(
    REQUIRES
      cimg/3.2.6
    GENERATORS
        cmake_find_package_multi
)

# Each config has to be set up for each package, so we'll loop through each (Debug, Release)
foreach(type ${CMAKE_CONFIGURATION_TYPES})
    message(STATUS "Configuring build type ${type}")
    conan_cmake_autodetect(settings BUILD_TYPE ${type})
    conan_cmake_install(PATH_OR_REFERENCE .
                        BUILD missing
                        REMOTE conancenter
                        SETTINGS ${settings})
endforeach()

# Now call find_package
find_package(CImg CONFIG)

set(header_files
  "source/image/types.h"
  "source/image/utils.h"
  "source/mandelbrot/mandelbrot.h"
)

#####################################################
# Main app
add_executable(mandelbrot "source/cli/main.cpp" "${header_files}")

include_directories(source)

target_link_libraries(mandelbrot
    PRIVATE
        CImg::CImg
)

if(MSVC)
target_compile_options(mandelbrot
    PRIVATE
        "/EHsc"
)
endif()
