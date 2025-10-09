
add_library(MandelbrotLib STATIC
    "Include/MandelbrotSet.hpp"
    "Source/MandelbrotSet.cpp"
)

target_include_directories(MandelbrotLib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>
    $<INSTALL_INTERFACE:include>
)
