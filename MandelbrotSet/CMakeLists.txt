
add_library(mandelbrot STATIC
    "Include/MandelbrotSet.hpp"
    "Source/MandelbrotSet.cpp"
)

target_include_directories(mandelbrot PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>
    $<INSTALL_INTERFACE:include>
)
