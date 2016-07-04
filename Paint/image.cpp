#include "image.h"
#include <algorithm>

using namespace std;

namespace my {
    Image::Image( size_t width, size_t height )
    : width_   { width }
    , height_  { height }
    {
        int color = 0xAA123456;
        tileSizeX = width / 10;
        tileSizeY = height / 10;
        data_ = std::vector<tile_t>(100);
        for (int tilecount = 0; tilecount < 100; ++tilecount) {
            vector<pixel_t> tile (tileSizeY * tileSizeX ) ;
            fill(tile.begin(), tile.end(), color);
            data_[tilecount] = tile;
        }

    }

    //Clear image with a color
    void Image::clear(pixel_t color)
    {
        for (int TileNr = 0; TileNr < 100; ++TileNr) {
            fill(data_[TileNr].begin(), data_[TileNr].end(), color);
        }
        bgColor = color;
    }

    void Image::set_pixel(size_t x, size_t y, pixel_t pixel){
        if(x < 0 || y < 0 || x >= width()|| y >= height())
            return ;
        getPixelRef(x,y) = pixel;
    }

    uint32_t Image::getPixel(size_t x, size_t y){
        if(x < 0 || y < 0 || x >= width()|| y >= height())
            return bgColor;

        return getPixelRef(x,y);
    }

    uint32_t& Image::getPixelRef(size_t x, size_t y){
        int tileX = x / tileSizeX;
        int tileY = y / tileSizeY;
        tile_t& tile = data_[tileX + tileY*10 ];
        return tile[ x % tileSizeX + (y % tileSizeY) * tileSizeX  ];
    }

    vector<uint32_t>  Image::getData(){
        vector<uint32_t> dat (width_ * height_);
        for (int y = 0; y < height_; ++y) {
            for(int x = 0; x < width_;x ++)
            {
                dat[y * width_ + x] = getPixel(x,y);
            }
        }
        return dat;
    }

    uint32_t Image::getBackgroundColor(){
        return bgColor;
    }
}

