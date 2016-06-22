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
        fill(data_.begin(),data_.end(),color);

    }
}

