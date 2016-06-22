#include "brush.h"
namespace my {
void Brush::OnMouseMove(int xpos, int ypos, int color)
{
    for(int y = -size_/ 2; y < size_/2;y++ )
    {
        for(int x = -size_/ 2; x< size_ / 2;x++)
        {
            (*img_).set_pixel(xpos + x,ypos + y,color);
        }
    }
}

void Brush::OnMouseDown(int xpos, int ypos, int color)
{
    for(int y = -size_/ 2; y < size_/2;y++ )
    {
        for(int x = -size_/ 2; x< size_ / 2;x++)
        {
            (*img_).set_pixel(xpos + x,ypos + y,color);
        }
    }
}

void Brush::SetSize(int size){
    size_ = size;
}
}
