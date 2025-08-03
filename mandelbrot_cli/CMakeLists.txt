
add_executable(mandelbrot_cli main.cpp)

target_link_libraries(mandelbrot_cli
    PRIVATE
    MandelbrotSet
    CImg::CImg
)
