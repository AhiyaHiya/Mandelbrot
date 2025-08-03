
#####################################################
# CLI app
add_executable(mandelbrot_app "main.cpp")

include_directories(source)

target_link_libraries(mandelbrot_app
    PRIVATE
        mandelbrot_headers
        cimg::cimg
)

if(MSVC)
target_compile_options(mandelbrot_app
    PRIVATE
        "/EHsc"
)
endif()