
add_library(MandelbrotSet STATIC
    "Include/MandelbrotSet.h"
    "Source/MandelbrotSet.cpp"
)
target_include_directories(MandelbrotSet PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>
    $<INSTALL_INTERFACE:include>
)
