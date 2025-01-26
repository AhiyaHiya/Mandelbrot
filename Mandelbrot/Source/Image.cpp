namespace Image::Position
{
auto OffsetInInterlaced1dVec(
    const std::uint32_t channelCount,
    const std::uint32_t width,
    const std::uint32_t x,
    const std::uint32_t y,
    const std::uint32_t channel) -> std::size_t
{
    const auto offset = (y * width + x) * channelCount + channel;
    return offset;
}

auto OffsetInImage8bitRgbaInterlaced(const Image::PixelsLength width,
                                    const std::uint32_t x,
                                    const std::uint32_t y,
                                    const Image::Channel channel) -> std::size_t
{
    constexpr auto channelCount = 4;
    return OffsetInInterleaved1dVec(channelCount, width, x, y, static_cast<std::uint32_t>(channel));
}
} // namespace Image::Position