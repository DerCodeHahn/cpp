#ifndef IMAGE_H
#define IMAGE_H
#pragma once

#include <vector>

namespace my
{

class Image
{
public:
    using pixel_t = uint32_t;
    using tile_t = std::vector<pixel_t>;

    Image( size_t width = {} , size_t height = {} );

    void set_pixel( size_t x, size_t y, pixel_t pixel );
    uint32_t getPixel(size_t x, size_t y);

    auto width() const  -> size_t          { return width_; }
    auto height() const -> size_t          { return height_; }
    std::vector<pixel_t> getData();// const   -> pixel_t const*   { return data_.data(); }
    void clear(int color);
    pixel_t getBackgroundColor();
private:

    size_t  width_;
    size_t  height_;
    pixel_t bgColor;
    std::vector<pixel_t>  data_;
};

}

#endif // IMAGE_H
