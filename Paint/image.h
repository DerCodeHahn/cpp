#ifndef IMAGE_H
#define IMAGE_H
#pragma once

#include <vector>

namespace my
{

class Image
{
public:
    using rgba_t = std::uint32_t;


    Image( size_t width = {} , size_t height = {} );

    void set_pixel( size_t x, size_t y, rgba_t pixel );


    auto width() const  -> size_t          { return width_; }
    auto height() const -> size_t          { return height_; }
    auto data() const   -> rgba_t const*   { return data_.data(); }
    void clear(int color);

private:

   size_t  width_;
   size_t  height_;

   std::vector<rgba_t>  data_;
};
}
#endif // IMAGE_H
