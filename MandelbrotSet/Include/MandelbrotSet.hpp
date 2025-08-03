#pragma once

#include <cstdint>
#include <tuple>
#include <vector>

class MandelbrotSet
{
    using red_t = std::int32_t;
    using green_t = std::int32_t;
    using blue_t = std::int32_t;
    using alpha_t = std::int32_t;
public:
MandelbrotSet()
    : m_maxChannelValue{std::numeric_limits<std::int32_t>::max()},
        m_maxIterations{m_maxChannelValue} {}

auto PixelAtCoordinate(const double scaled_x, const double scaled_y) -> std::tuple<red_t, green_t, blue_t, alpha_t>;
auto PixelAtIteration(const uint32_t iteration) -> std::tuple<red_t, green_t, blue_t, alpha_t>;

private:
template <typename T>
auto ScaleCoordinate(const T coordinate, const T min, const T max, const T size) -> T
{
    return coordinate * ((max - min) / size) + min;
}

    const std::int32_t m_maxChannelValue;
    const std::int32_t m_maxIterations;
}

auto CreateMandelbrotImage(const double x_max, const double x_min, const double y_max, const double y_min,
                           const size_t width, const size_t height) -> std::vector<std::uint32_t>;
