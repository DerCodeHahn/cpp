#include "image.h"
#include <algorithm>

using namespace std;

namespace my {
    image::image( size_t width, size_t height )
    : width_   { width }
    , height_  { height }
    , data_    ( width * height, 0xff123456 )
    {}

    //Clear image with a color
    void image::clear(int color)
    {
        fill(data_.begin(),data_.end(),color);

    }
}

