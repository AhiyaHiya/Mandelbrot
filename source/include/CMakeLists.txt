
add_library(mandelbrot_headers INTERFACE
    "image/types.h"
    "image/utils.h"
    "mandelbrot/mandelbrot.h"
)

target_include_directories(mandelbrot_headers
    INTERFACE
        "${CMAKE_CURRENT_LIST_DIR}"
)