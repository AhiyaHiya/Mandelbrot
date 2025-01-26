#pragma once

#include "Mandelbrot/Image.hpp"

namespace Mandelbrot
{

auto CreateMandelbrotImage(PixelsLength width, PixelsLength height) -> Image8bitRgbaInterlaced;

}