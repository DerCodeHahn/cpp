#include "circlebrush.h"

#include <iostream>
#include <math.h>
namespace my{

CircleBrush::CircleBrush(Image *i, int size):Brush(i,size)
{
}
void  CircleBrush::OnMouseMove(int xpos, int ypos, int color)
{
}

void CircleBrush::OnMouseDown(int xpos, int ypos, int color)
{
    lastX = xpos;
    lastY = ypos;
}

void CircleBrush::OnMouseUp(int xpos, int ypos, int color){
    DrawCircle(xpos,ypos,color);
}

int CircleBrush::getDirection(int pos, int target){
    if(pos > target)
        return -1;
    else
        return 1;
}

int CircleBrush::GetDelta(int x1, int x2){
    int delta (x2 - x1);
    delta  = std::abs(delta);
    return delta;
}

void CircleBrush::DrawCircle(int xpos, int ypos, int color){
    int dX = GetDelta(lastX,xpos);
    int dY = GetDelta(lastY,ypos);
    int d;
    if(dX <= dY){
        d=dX;
    }else{
        d=dY;
    }

    for(unsigned i=0; i<=d*2; ++i){
        int tmpX = (int) d*sin(((double)i/(double)d) * (M_PI/2.0));
        int tmpY = (int) d*cos(((double)i/(double)d) * (M_PI/2.0));
        Emit(lastX+tmpX,lastY+tmpY,color);
        Emit(lastX+tmpX,lastY-tmpY,color);
        Emit(lastX-tmpX,lastY+tmpY,color);
        Emit(lastX-tmpX,lastY-tmpY,color);
    }


}

}
