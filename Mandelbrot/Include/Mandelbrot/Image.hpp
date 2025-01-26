#pragma once

namespace Image
{
// Image - Memory size - Pixel Channels - Pixel Layout
using Image8bitRgbaInterlaced = std::vector<std::uint8_t>;
using Image16bitRgbaInterlaced = std::vector<std::uint16_t>;
using PixelsLength = std::uint32_t;

enum class Channel : std::uint32_t
{
    Red = 0,
    Green = 1,
    Blue = 2,
    Alpha = 3
}
} // namespace Image

namespace Image::Position
{
auto OffsetInInterlaced1dVec(const std::uint32_t channelCount,
                            const Image::PixelsLength width,
                            const std::uint32_t x,
                            const std::uint32_t y,
                            const Image::Channel channel) -> std::size_t;

// For an interleaved 8-bit RGBA image, returns the offset to get the pixel value
// for the channel that you are interested in
auto OffsetInImage8bitRgbaInterlaced(const Image::PixelsLength width,
                                    const std::uint32_t x,
                                    const std::uint32_t y,
                                    const Image::Channel channel) -> std::size_t;
} // namespace Image::Position