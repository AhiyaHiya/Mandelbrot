//
//  Created by Jaime Rios on 2021-02-01
//  Copyright © 2021 jaimerios.com. All rights reserved.
//

#pragma once

#include "image/utils.h"

#include <cmath>
#include <limits>
#include <stdint.h>

namespace hera
{

///////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
auto scale_coordinate(const T coordinate, const T min, const T max, const T size) -> T
{
    return coordinate * ((max - min) / size) + min;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// https://en.wikipedia.org/wiki/Mandelbrot_set#Escape_time_algorithm
template <typename T>
class mandelbrot
{
  public:
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    mandelbrot()
        : m_max_channel_value{std::numeric_limits<T>::max()}, m_max_iterations{m_max_channel_value}
    {
        ;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    auto pixel_at_coordinate(const double scaled_x, const double scaled_y) -> std::tuple<T, T, T, T>
    {
        auto x0 = 0.0;
        auto y0 = 0.0;

        const auto x1 = scaled_x;
        const auto y1 = scaled_y;

        auto iteration = 0u;

        while (((x0 * x0) + (y0 * y0) < (2.0 * 2.0)) && (iteration < m_max_iterations))
        {
            const auto xtemp = (x0 * x0) - (y0 * y0) + x1;
            const auto ytemp = (2.0 * x0 * y0) + y1;

            x0 = xtemp;
            y0 = ytemp;

            ++iteration;
        }

        return pixel_at_iteration(iteration);
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    auto pixel_at_iteration(const uint32_t iteration) -> std::tuple<T, T, T, T>
    {
        if (iteration < m_max_iterations)
        {
            auto value0 = m_max_channel_value * iteration / m_max_iterations;
            auto value1 = 0;

            for (auto loop = 0; loop < 8; ++loop)
            {
                value1 = (value1 << 1) | (value0 & 1);
                value0 >>= 1;
            }

            const auto red   = static_cast<T>(value1);
            const auto green = static_cast<T>(m_max_channel_value - value1);
            const auto blue  = static_cast<T>(m_max_channel_value - std::sqrt(red * green));
            const auto alpha = static_cast<T>(m_max_channel_value);
            return std::make_tuple(red, green, blue, alpha);
        }

        return std::make_tuple(0, 0, 0, 0);
    }

  private:
    const uint32_t m_max_channel_value;
    const uint32_t m_max_iterations;
};

///////////////////////////////////////////////////////////////////////////////////////////////////
// Template function
// Create a 1d vector with interlaced rgba pixel values, for a Mandelbrot set
// Single threaded, non re-entrant
//
template <typename T>
auto create_mandelbrot_image(const double        x_max,
                             const double        x_min,
                             const double        y_max,
                             const double        y_min,
                             const pixels_wide_t width,
                             const pixels_wide_t height) -> vec_1d<T>
{
    // This template function will fill up a 1d vec with the pixel data that you need for a
    // Mandelbrot image
    const auto channels = 4u;

    auto image  = mandelbrot<T>{};
    auto pixels = vec_1d<T>(width * height * channels, 0);

    for (auto y = 0; y < height; ++y)
    {
        for (auto x = 0; x < width; ++x)
        {
            const auto scaled_x = scale_coordinate<double>(x, x_min, x_max, static_cast<double>(width));
            const auto scaled_y = scale_coordinate<double>(y, y_min, y_max, static_cast<double>(height));
            const auto pixel    = image.pixel_at_coordinate(scaled_x, scaled_y);

            if (x > 300 && y > 300)
            {
                auto x = 0;
                x += 2;
                x = x * 2;
            }
            const auto red   = std::get<0>(pixel);
            const auto green = std::get<1>(pixel);
            const auto blue  = std::get<2>(pixel);
            const auto alpha = std::get<3>(pixel);

            const auto r_pos = position::offset_in_interleaved_1d_vec<channels>(width, x, y, 0);
            const auto g_pos = position::offset_in_interleaved_1d_vec<channels>(width, x, y, 1);
            const auto b_pos = position::offset_in_interleaved_1d_vec<channels>(width, x, y, 2);
            const auto a_pos = position::offset_in_interleaved_1d_vec<channels>(width, x, y, 3);

            pixels[r_pos] = red;
            pixels[g_pos] = green;
            pixels[b_pos] = blue;
            pixels[a_pos] = alpha;
        }
    }

    return pixels;
}

} // namespace hera
