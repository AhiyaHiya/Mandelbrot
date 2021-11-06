//
//  Created by Jaime Rios on 2021-02-01
//  Copyright © 2021 jaimerios.com. All rights reserved.
//

#include <iostream>

#include "image/types.h"
#include "mandelbrot/mandelbrot.h"

#include "CImg.h"
using namespace cimg_library;

////////////////////////////////////////////////////////////////
//
int main(int, char **)
{
    ////////////////////////////////////////////////////////////////
    // Create a mandelbrot image
    constexpr auto width  = pixels_wide_t(1536);
    constexpr auto height = pixels_wide_t(1152);

    // Dimensions we need for image creation
    constexpr auto x_min = -2.0;
    constexpr auto x_max = +0.5;
    constexpr auto y_max = +1.0;
    constexpr auto y_min = -1.0;

    auto rgba_image = hera::create_mandelbrot_image<uint8_t>(x_max, x_min, y_max, y_min, width, height);

    ////////////////////////////////////////////////////////////////
    // Now use CImg for displaying the rendered image
    constexpr auto channel_count = 4u;
    CImg<uint8_t>  image(width, height, 1, channel_count, 0);

    // Macro for looping over image
    cimg_forXYC(image, x, y, c)
    {
        const auto offset = hera::position::offset_in_interleaved_1d_vec<channel_count>(width, x, y, c);
        image(x, y, c)    = rgba_image[offset];
    }

    // Display mechanism
    auto main_disp = CImgDisplay(image, "Image");
    while (!main_disp.is_closed())
    {
        main_disp.wait();
    }
    return 0;
}
