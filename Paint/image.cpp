#include "image.h"
#include <algorithm>
#include <iostream>

using namespace std;

namespace my {
    Image::Image( size_t width, size_t height )
    : width_   { width }
    , height_  { height }
    {
        int color = 0xAA123456;
        tileSizeX = width / 10;
        tileSizeY = height / 10;
        data_ = std::vector<SharedTile_t>(100);
        for (int tilecount = 0; tilecount < 100; ++tilecount) {
            data_[tilecount].tile = make_shared< tile_t>(tileSizeY * tileSizeX ) ;
            fill(data_[tilecount].tile->begin(), data_[tilecount].tile->end(), color);
        }

    }

    //Clear image with a color
    void Image::clear(pixel_t color)
    {
        for(SharedTile_t& tile : data_)
        {
            tile.tile = make_shared<tile_t>(*tile.tile);
            fill(tile.tile->begin(), tile.tile->end(), color);
            tile.editFlag = false;
        }

        bgColor = color;
    }

    void Image::ClearFlags(){
        for(SharedTile_t& t:data_)
        {
            t.editFlag = false;
        }
        std::cout << "Cleared Flags" << std::endl;

    }

    void Image::set_pixel(size_t x, size_t y, pixel_t pixel){
        if(x < 0 || y < 0 || x >= width()|| y >= height())
            return ;
        int tileX = x / tileSizeX;
        int tileY = y / tileSizeY;
        SharedTile_t& tile = data_[tileX + tileY*10 ];
        if(!tile.editFlag)
        {
            shared_ptr<tile_t> newTile = make_shared<tile_t>(*tile.tile);
            tile.tile = newTile;
            tile.editFlag = true;
            std::cout << "Create New Tile @ " << tileX << ", " << tileY << std::endl;

        }
        (*tile.tile)[ x % tileSizeX + (y % tileSizeY) * tileSizeX  ] = pixel;

    }

    uint32_t Image::getPixel(size_t x, size_t y){
        if(x < 0 || y < 0 || x >= width()|| y >= height())
            return bgColor;
        int tileX = x / tileSizeX;
        int tileY = y / tileSizeY;
        tile_t& tile = (*data_[tileX + tileY*10 ].tile);
        return tile[ x % tileSizeX + (y % tileSizeY) * tileSizeX  ];

    }

    uint32_t& Image::getPixelRef(size_t x, size_t y){
        int tileX = x / tileSizeX;
        int tileY = y / tileSizeY;
        tile_t& tile = *data_[tileX + tileY*10 ].tile;
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

