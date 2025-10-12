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

using pixels_wide_t = std::uint32_t;
using pixels_high_t = std::uint32_t;
using point_t = std::uint32_t;

namespace position
{
/**
 For use with 1d_vec that is storing pixels in interleaved format: e.g. rgbrgbrgb
 Will return memory offset within 1d_vec for x,y coordinate and desired channel.
 */
template <const uint32_t channel_count>
auto offset_in_interleaved_1d_vec(const pixels_wide_t width, const point_t x, const point_t y, const uint32_t channel) -> size_t
{
  const auto offset = (y * width + x) * channel_count + channel;
  return offset;
}

/**
 For use with 1d_vec that is storing pixels in planar format: e.g. rrrgggbbb
 Will return memory offset within 1d_vec for x,y coordinate and desired channel.
 */
template <const pixels_wide_t width, const pixels_wide_t height>
auto offset_in_planar_1d_vec(const point_t x, const point_t y, const uint32_t channel) -> size_t
{
  const auto offset = (channel * (width * height)) + (y * width + x);
  return offset;
}
} // namespace position

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
                           const pixels_wide_t width, const pixels_high_t height) -> vec_1d<std::uint32_t>;
