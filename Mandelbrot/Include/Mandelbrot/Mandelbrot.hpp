#pragma once

namespace Mandelbrot
{

// Image - Memory size - Pixel Channels - Pixel Layout
using Image8bitRgbaInterlaced = std::vector<std::uint8_t>;
using Image16bitRgbaInterlaced = std::vector<std::uint16_t>;
using PixelsLength = std::uint32_t;

auto GetMandelbrotImage(PixelsLength width, PixelsLength height) -> Image8bitRgbaInterlaced;

}