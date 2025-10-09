
#include "MandelbrotSet.hpp"

#include <CImg.h>

int main(int argc, char* argv[])
{
    if (argc != 7)
    {
        std::printf("Usage: %s <x_max> <x_min> <y_max> <y_min> <width> <height>\n", argv[0]);
        return 1;
    }

    const auto x_max = std::atof(argv[1]);
    const auto x_min = std::atof(argv[2]);
    const auto y_max = std::atof(argv[3]);
    const auto y_min = std::atof(argv[4]);
    const auto width = static_cast<size_t>(std::atoi(argv[5]));
    const auto height = static_cast<size_t>(std::atoi(argv[6]));

    const auto image_data = CreateMandelbrotImage(x_max, x_min, y_max, y_min, width, height);

    auto image = cimg_library::CImg<std::uint32_t>(image_data.data(), width, height, 1, 4);
    image.save("mandelbrot.png");

    return 0;
}