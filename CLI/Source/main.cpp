
#include "MandelbrotSet.hpp"

#include <CImg.h>

namespace 
{
constexpr auto x_min = -2.0;
constexpr auto x_max = +0.5;
constexpr auto y_max = +1.0;
constexpr auto y_min = -1.0;
} // namespace

int main(int argc, char* argv[])
{
    if (argc != 7)
    {
        std::printf("Usage: %s <width> <height>\n", argv[0]);
        return 1;
    }

    const auto width = static_cast<size_t>(std::atoi(argv[1]));
    const auto height = static_cast<size_t>(std::atoi(argv[2]));

    const auto image_data = CreateMandelbrotImage(x_max, x_min, y_max, y_min, width, height);

    auto image = cimg_library::CImg<std::uint32_t>(image_data.data(), width, height, 1, 4);
    image.save("mandelbrot.png");

    return 0;
}