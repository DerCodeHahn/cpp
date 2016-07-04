#include "rectanglebrush.h"
#include <iostream>
namespace my{

RectangleBrush::RectangleBrush(Image *i, int size):Brush(i,size)
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
    delta  = std::abs(delta) << 1;
    return delta;
}

void RectangleBrush::DrawRectangle(int xpos, int ypos, int color){

    int ix = getDirection (xpos, lastX);
    int iy = getDirection (ypos, lastY);
    //std::cout <<" Last X " << lastX <<" ix" << xIterator;
    int delta_x = GetDelta(xpos , lastX);
    int delta_y = GetDelta(ypos , lastY);


    int saveXpos = xpos;
    int saveYpos = ypos;
    if (delta_x >= delta_y)
    {
        // error may go below zero
        int error(delta_y - (delta_x >> 1));

        while (xpos != lastX)
        {
            if ((error >= 0) && (error || (ix > 0)))
            {
                error -= delta_x;
                ypos += iy;
            }
            // else do nothing

            error += delta_y;
            xpos += ix;

            Emit(xpos,ypos, color);
        }
    }
    else
    {
        // error may go below zero
        int error(delta_x - (delta_y >> 1));

        while (ypos != lastY)
        {
            if ((error >= 0) && (error || (iy < 0)))
            {
                error -= delta_y;
                xpos += ix;
            }
            // else do nothing

            error += delta_x;
            ypos += iy;

            Emit(xpos,ypos, color);
        }
    }

    lastX = saveXpos;
    lastY = saveYpos;
}

}
