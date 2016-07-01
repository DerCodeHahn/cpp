#include "brush.h"
namespace my {
Brush::Brush(){

}

void Brush::SetSize(int size){
    size_ = size;
}
int Brush::GetSize(){
    return size_;
}
void Brush::OnMouseMove(int xpos, int ypos, int color)
{
    Emit(xpos,ypos,color);
}

void Brush::OnMouseDown(int xpos, int ypos, int color)
{
    Emit(xpos,ypos,color);
}

void Brush::OnMouseUp(int xpos, int ypos, int color)
{
    Emit(xpos,ypos,color);
}

void Brush::Emit(int xpos, int ypos, int color)
{
    if(size_ <= 1){
        (*img_).set_pixel(xpos,ypos,color);
        return;
    }
    else{
        for(int y = -size_/ 2; y < size_/2;y++ )
        {
            for(int x = -size_/ 2; x< size_ / 2;x++)
            {
                (*img_).set_pixel(xpos + x,ypos + y,color);
            }
        }
    }
}


}
