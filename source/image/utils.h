//
//  Created by Jaime Rios on 2021-02-01
//  Copyright © 2021 jaimerios.com. All rights reserved.
//

#pragma once

#include <vector>

namespace jaimerios
{
namespace position
{
/**
 For use with 1d_vec that is storing pixels in interleaved format: e.g. rgbrgbrgb
 Will return memory offset within 1d_vec for x,y coordinate and desired channel.
 */
template <const uint32_t channel_count>
auto offset_in_interleaved_1d_vec(const uint32_t width, const uint32_t x, const uint32_t y, const uint32_t channel) -> size_t
{
  const auto offset = (y * width + x) * channel_count + channel;
  return offset;
}

/**
 For use with 1d_vec that is storing pixels in planar format: e.g. rrrgggbbb
 Will return memory offset within 1d_vec for x,y coordinate and desired channel.
 */
template <const uint32_t width, const uint32_t height>
auto offset_in_planar_1d_vec(const uint32_t x, const uint32_t y, const uint32_t channel) -> size_t
{
  const auto offset = static_cast<size_t>((channel * (width * height)) + (y * width + x));
  return offset;
}
} // namespace position

// compilers love 1d vec's for vectorization
template <typename T>
using vec_1d = std::vector<T>;

} // namespace jaimerios
