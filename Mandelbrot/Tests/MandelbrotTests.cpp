
#include "Mandelbrot/Mandelbrot.hpp"

#include <gtest/gtest.h>

// Get the raw image data, from the Mandelbrot functions
TEST(MandelbrotTests, GetASmallMandelbrotImage)
{
    constexpr auto width = 240;
    constexpr auto height = 180;
    const auto rgbaImage = Mandelbrot::GetMandelbrotImage(width, height);

    ASSERT_NE(rgbaImage.size(), 0);
}
