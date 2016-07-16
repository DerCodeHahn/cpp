#ifndef IMAGE_H
#define IMAGE_H
#pragma once

#include <vector>
#include <cstdint>
#include <memory>
#include <QImage>


namespace my
{

class Image
{
public:

    using pixel_t = std::uint32_t;
    using tile_t = std::vector<pixel_t>;

    using SharedTile_t = std::shared_ptr<tile_t>;

    Image( int width = {} , int height = {} );

    void set_pixel( int x, int y, pixel_t pixel );
    pixel_t getPixel(int x, int y);

    int width() { return width_; }
    int height()  { return height_; }


    std::vector<pixel_t> getData();// const   -> pixel_t const*   { return data_.data(); }
    void clear(pixel_t color);
    pixel_t getBackgroundColor();
    void ClearFlags();
    void SetData(QImage i); //
private:
    int tileSizeX;
    int tileSizeY;
    int  width_;
    int  height_;
    pixel_t bgColor;
    std::vector<SharedTile_t>  data_;
    pixel_t& getPixelRef(int x, int y);
};

}

#endif // IMAGE_H
