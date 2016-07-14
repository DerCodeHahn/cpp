#include "rectanglebrush.h"
#include <iostream>
namespace my{

RectangleBrush::RectangleBrush(History *h, int size):Brush(h,size)
{
}
void  RectangleBrush::OnMouseMove(int xpos, int ypos, int color)
{
}

void RectangleBrush::OnMouseDown(int xpos, int ypos, int color)
{
    lastX = xpos;
    lastY = ypos;
}

void RectangleBrush::OnMouseUp(int xpos, int ypos, int color){
    DrawRectangle(xpos,ypos,color);
}

int RectangleBrush::getDirection(int pos, int target){
    if(pos > target)
        return -1;
    else
        return 1;
}

int RectangleBrush::GetDelta(int x1, int x2){
    int delta (x2 - x1);
    delta  = std::abs(delta);
    return delta;
}

void RectangleBrush::DrawRectangle(int xpos, int ypos, int color){
    int dX = GetDelta(lastX,xpos);
    int mX = getDirection(lastX,xpos);

    int tmpX = lastX;

    for(unsigned i=0; i<=dX; ++i){
        Emit(tmpX,lastY,color);
        Emit(tmpX,ypos,color);
        tmpX += mX;
    }

    int dY = GetDelta(lastY, ypos);
    int mY = getDirection(lastY,ypos);

    int tmpY =  lastY;

    for(unsigned i=0; i<=dY;++i){
        Emit(lastX,tmpY,color);
        Emit(xpos,tmpY, color);
        tmpY += mY;
    }

}

}
