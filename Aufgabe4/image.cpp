#include "image.h"

namespace my {

image::image( size_t width, size_t height )
: width_   { width }
, height_  { height }
, data_    ( width * height, 0xff123456 )
{}

}