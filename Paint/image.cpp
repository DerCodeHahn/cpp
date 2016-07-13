#include "image.h"
#include <algorithm>
#include <iostream>


using namespace std;

namespace my {
    Image::Image( int width, int height )
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

//    void Image::ClearFlags(){
//        for(SharedTile_t& t:data_)
//        {
//            t.editFlag = false;
//        }
//        std::cout << "Cleared Flags" << std::endl;

//    }

    void Image::set_pixel(int x, int y, pixel_t pixel){
        if(x < 0 || y < 0 || x >= width()|| y >= height())
            return ;
        int tileX = x / tileSizeX;
        int tileY = y / tileSizeY;
        SharedTile_t& tile = data_[tileX + tileY*10 ];
        if(!tile.tile.unique())
        {
            shared_ptr<tile_t> newTile = make_shared<tile_t>(*tile.tile);
            tile.tile = newTile;
            tile.editFlag = true;
            std::cout << "Create New Tile @ " << tileX << ", " << tileY << std::endl;

        }
        (*tile.tile)[ x % tileSizeX + (y % tileSizeY) * tileSizeX  ] = pixel;

    }

    uint32_t Image::getPixel(int x, int y){
        if(x < 0 || y < 0 || x >= width()|| y >= height())
            return bgColor;
        int tileX = x / tileSizeX;
        int tileY = y / tileSizeY;
        tile_t& tile = (*data_[tileX + tileY*10 ].tile);
        return tile[ x % tileSizeX + (y % tileSizeY) * tileSizeX  ];

    }

    uint32_t& Image::getPixelRef(int x, int y){
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

    void Image::SetData(QImage img)
    {
        width_ = img.width();
        height_ = img.height();
        std::cout << width_ << "x" << height_ << std::endl;
        tileSizeX = width_ / 10;
        tileSizeY = height_ / 10;
        data_ = std::vector<SharedTile_t>(100);
        for (int tilecount = 0; tilecount < 100; ++tilecount) {
            data_[tilecount].tile = make_shared< tile_t>(tileSizeY * tileSizeX ) ;
            int minY = (tilecount / 10) * tileSizeY;
            int maxY = minY + tileSizeY;
            for (int y = minY ; y < maxY; ++y) {
                int minX =  (tilecount % 10) * tileSizeX;
                int maxX = minX + tileSizeX;
                for(int x = minX; x < maxX; x++)
                {
                    QColor pixColor (img.pixel(x,y));
                    QString qs = pixColor.name(QColor::HexArgb);
                    qs.remove(0,1);
                    bool npointr;
                    std::uint32_t color = qs.toUInt(&npointr,16);
                    //std::cout << tilecount <<" x " << x << " y " << y << endl;

                    set_pixel(x,y, color);
                }
            }
        }
    }

    uint32_t Image::getBackgroundColor(){
        return bgColor;
    }
}

