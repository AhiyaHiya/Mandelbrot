
#include "MandelbrotSet.hpp"

#include <gtest/gtest.h>

TEST(MandelbrotSetTests, PixelAtIteration_FirstTest)
{
    const auto pixels_wide   = 120U;
    const auto pixels_high   = 120U;
    const auto channel_count = 4U; // RGBA
    auto       image_data    = vec_1d<std::uint32_t>();

    const auto pixel_count = pixels_wide * pixels_high * channel_count;

    image_data.reserve(pixel_count);
    for (auto index = 0U; index < pixel_count; ++index)
    {
        image_data.push_back(0U);
        image_data.push_back(1U);
        image_data.push_back(2U);
        image_data.push_back(3U);
    }

    // Now test that the data is what we expect it to be
    for (auto y = point_t{0}; y < pixels_high; ++y)
    {
        for (auto x = point_t{0}; x < pixels_wide; ++x)
        {
            const auto r_pos = position::offset_in_interleaved_1d_vec<channel_count>(pixels_wide, x, y, 0);
            const auto g_pos = position::offset_in_interleaved_1d_vec<channel_count>(pixels_wide, x, y, 1);
            const auto b_pos = position::offset_in_interleaved_1d_vec<channel_count>(pixels_wide, x, y, 2);
            const auto a_pos = position::offset_in_interleaved_1d_vec<channel_count>(pixels_wide, x, y, 3);

            const auto red   = image_data[r_pos];
            const auto green = image_data[g_pos];
            const auto blue  = image_data[b_pos];
            const auto alpha = image_data[a_pos];

            EXPECT_EQ(red, 0U);
            EXPECT_EQ(green, 1U);
            EXPECT_EQ(blue, 2U);
            EXPECT_EQ(alpha, 3U);
        }
    }
}

TEST(MandelbrotSetTests, CreateImageTest)
{
    constexpr auto x_min  = -2.0;
    constexpr auto x_max  = +0.5;
    constexpr auto y_max  = +1.0;
    constexpr auto y_min  = -1.0;
    const auto     width  = static_cast<pixels_wide_t>(120);
    const auto     height = static_cast<pixels_high_t>(120);

    auto image_data = CreateMandelbrotImage(x_max, x_min, y_max, y_min, width, height);
    EXPECT_EQ(image_data.size(), width * height * 4U);
}