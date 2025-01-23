
add_library(MandelbrotLib STATIC
    "Source/Mandelbrot.cpp"
)

target_include_directories(MandelbrotLib
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/Include"
)

add_subdirectory(Tests)
