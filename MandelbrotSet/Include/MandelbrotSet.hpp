#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>
#include <tuple>
#include <vector>

template <typename T>
using vec_1d = std::vector<T>;

using red_t = std::int32_t;
using green_t = std::int32_t;
using blue_t = std::int32_t;
using alpha_t = std::int32_t;

using rgba_t = std::tuple<red_t, green_t, blue_t, alpha_t>;

class MandelbrotSet
{
    
public:
MandelbrotSet()
    : m_maxChannelValue{std::numeric_limits<std::int32_t>::max()},
        m_maxIterations{m_maxChannelValue} {}

auto PixelAtCoordinate(const double scaled_x, const double scaled_y) -> rgba_t;
auto PixelAtIteration(const uint32_t iteration) -> rgba_t;

private:
    const std::int32_t m_maxChannelValue;
    const std::int32_t m_maxIterations;
};

auto CreateMandelbrotImage(const double x_max, const double x_min, const double y_max, const double y_min,
                           const size_t width, const size_t height) -> vec_1d<std::uint32_t>;
