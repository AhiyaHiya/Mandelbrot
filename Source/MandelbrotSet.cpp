
auto MandelbrotSet::PixelAtCoordinate(const double scaled_x, const double scaled_y) -> std::tuple<red_t, green_t, blue_t, alpha_t>
{
    double x0 = 0.0;
    double y0 = 0.0;

    const auto x1 = scaled_x;
    const auto y1 = scaled_y;

    auto iteration = 0U;

    while (((x0 * x0) + (y0 * y0) < (2.0 * 2.0)) && (iteration < m_maxIterations))
    {
        const auto xtemp = (x0 * x0) - (y0 * y0) + x1;
        const auto ytemp = (2.0 * x0 * y0) + y1;

        x0 = xtemp;
        y0 = ytemp;

        ++iteration;
    }

    return PixelAtIteration(iteration);
}

auto MandelbrotSet::PixelAtIteration(const uint32_t iteration) -> std::tuple<red_t, green_t, blue_t, alpha_t>
{
    if (iteration < m_maxIterations)
    {
        auto value0 = m_maxChannelValue * iteration / m_maxIterations;
        auto value1 = 0;

        for (auto loop = 0; loop < 8; ++loop)
        {
            value1 = (value1 << 1) | (value0 & 1);
            value0 >>= 1;
        }

        const auto red   = static_cast<red_t>(value1);
        const auto green = static_cast<green_t>(m_maxChannelValue - value1);
        const auto blue  = static_cast<blue_t>(m_maxChannelValue - std::sqrt(red * green));
        const auto alpha = static_cast<alpha_t>(m_maxChannelValue);
        return std::make_tuple(red, green, blue, alpha);
    }

    return std::make_tuple(0, 0, 0, 0);
}

auto CreateMandelbrotImage(const double x_max, const double x_min, const double y_max, const double y_min,
                             const size_t width, const size_t height) -> vec_1d<std::uint32_t>
{
    auto mandelbrotSet = MandelbrotSet();

    constexpr auto channelCount = 4u; // RGBA
    auto image = std::vector<std::uint32_t>(width * height * channelCount);

    for (auto y = 0; y < height; ++y)
    {
        for (auto x = 0; x < width; ++x)
        {
            const auto scaled_x = mandelbrotSet.scale_coordinate(static_cast<double>(x), x_min, x_max, width);
            const auto scaled_y = mandelbrotSet.scale_coordinate(static_cast<double>(y), y_min, y_max, height);

            const auto [red, green, blue, alpha] = mandelbrotSet.PixelAtCoordinate(scaled_x, scaled_y);

            const auto offset = position::offset_in_interleaved_1d_vec(4, width, x, y);
            image[offset]     = static_cast<std::uint32_t>(red);
            image[offset + 1] = static_cast<std::uint32_t>(green);
            image[offset + 2] = static_cast<std::uint32_t>(blue);
            image[offset + 3] = static_cast<std::uint32_t>(alpha);
        }
    }

    return image;
}