#include "MandelbrotSet.hpp"

#include <CImg.h>
using namespace cimg_library;

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

auto ConvertToCimg(const std::int32_t width, const std::int32_t height,
    const std::vector<std::int32_t> rgba_image) -> CImg<uint8_t>
{
    constexpr auto channelCount = 4u;
    auto image = CImg<uint8_t>{width, height, 1, channelCount, 0};

    // Macro for looping over image
    cimg_forXYC(image, x, y, c)
    {
        // Interleaved RGBA data
        // Each pixel has 4 channels (R, G, B, A), stored consecutively
        const auto offset = (y * width + x) * channelCount + c;
        image(x, y, c)    = rgba_image[offset];
    }
    return image;
}

int main(int argc, char **argv)
{
    if (argc < 5)
    {
        std::cout << "Usage: " << argv[0] << " --width <imageWidth> --height <imageHeight>\n";
        return 1;
    }

    auto width = 0, height = 0;
    for (auto i = 1; i < argc; ++i)
    {
        if ((std::string(argv[i]) == "--width" || std::string(argv[i]) == "-w") && i + 1 < argc)
        {
            width = std::stoi(argv[++i]);
        }
        else if ((std::string(argv[i]) == "--height" || std::string(argv[i]) == "-h") && i + 1 < argc)
        {
            height = std::stoi(argv[++i]);
        }
    }

    if (width <= 0 || height <= 0)
    {
        std::cout << "Invalid or missing width/height.\n";
        std::cout << "Usage: " << argv[0] << " --width <imageWidth> --height <imageHeight>\n";
        return 1;
    }

     // Dimensions we need for image creation
    constexpr auto x_min = -2.0;
    constexpr auto x_max = +0.5;
    constexpr auto y_max = +1.0;
    constexpr auto y_min = -1.0;

    auto rgba_image = CreateMandelbrotImage(x_max, x_min, y_max, y_min, width, height);

    const auto image = ConvertToCimg(width, height, rgba_image);

    image.save_jpeg("mandelbrot.jpg");

    return 0;
}