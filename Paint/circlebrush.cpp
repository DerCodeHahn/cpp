#include "circlebrush.h"

#include <iostream>
#define _USE_MATH_DEFINES //Needed to work on Windows
#include <math.h>
namespace my{

CircleBrush::CircleBrush(History *h, int size):Brush(h,size)
{
    Description = "CirleBrush";
}
void  CircleBrush::OnMouseMove(int xpos, int ypos, int color)
{
    history->Undo();
    history->Commit("Drag Cirle");
    DrawCircle(xpos,ypos,color);
}

void CircleBrush::OnMouseDown(int xpos, int ypos, int color)
{
    lastX = xpos;
    lastY = ypos;
    DrawCircle(xpos,ypos,color);
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
    int d = sqrt (pow(dX,2.0)+pow(dY,2.0));

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
