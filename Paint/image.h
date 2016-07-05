#ifndef IMAGE_H
#define IMAGE_H
#pragma once

#include <vector>
#include <cstdint>
#include <memory>

using std::size_t;
namespace my
{

class Image
{
public:

    using pixel_t = std::uint32_t;
    using tile_t = std::vector<pixel_t>;

    struct SharedTile_t { bool editFlag = false; std::shared_ptr<tile_t> tile;};


    Image( size_t width = {} , size_t height = {} );

    void set_pixel( size_t x, size_t y, pixel_t pixel );
    pixel_t getPixel(size_t x, size_t y);

    auto width() const -> size_t          { return width_; }
    auto height() const -> size_t          { return height_; }
    std::vector<pixel_t> getData();// const   -> pixel_t const*   { return data_.data(); }
    void clear(pixel_t color);
    pixel_t getBackgroundColor();
    void ClearFlags();
private:
    int tileSizeX;
    int tileSizeY;
    size_t  width_;
    size_t  height_;
    pixel_t bgColor;
    std::vector<SharedTile_t>  data_;
    pixel_t& getPixelRef(size_t x, size_t y);
};

}

#endif // IMAGE_H
