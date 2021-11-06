//
//  Created by Jaime Rios on 2021-02-01
//  Copyright © 2021 jaimerios.com. All rights reserved.
//

#pragma once

#include "image/types.h"

#include <filesystem>
#include <vector>

namespace hera
{
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
  const auto offset = static_cast<size_t>((channel * (width * height)) + (y * width + x));
  return offset;
}
} // namespace position

} // namespace hera
