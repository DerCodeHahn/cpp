#include "image.h"
#include <algorithm>

using namespace std;

namespace my {
    Image::Image( size_t width, size_t height )
    : width_   { width }
    , height_  { height }
    , data_    ( width * height, 0xff123456 )
    {}

    //Clear image with a color
    void Image::clear(int color)
    {
        fill(data_.begin(), data_.end(), color);
        bgColor = color;
    }

    void Image::set_pixel(size_t x, size_t y, pixel_t pixel){
        if(x < 0 || y < 0 || x >= width()|| y >= height())
            return ;

        data_[ y*width_ + x ] = pixel;
    }

    uint32_t Image::getPixel(size_t x, size_t y){
        if(x < 0 || y < 0 || x >= width()|| y >= height())
            return bgColor;
        return data_[ y*width_ + x ];
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

