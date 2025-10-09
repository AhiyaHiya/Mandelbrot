add_executable(mandelbrot
    "Source/main.cpp"
)

target_link_libraries(mandelbrot
    PRIVATE
        MandelbrotLib
        CImg::CImg
)
