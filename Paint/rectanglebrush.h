#ifndef RECTANGLEBRUSH_H
#define RECTANGLEBRUSH_H

#include "brush.h"

namespace my{
class rectanglebrush:public Brush
{

private:
    int lastX;
    int lastY;
    int getDirection(int pos, int target);
    int GetDelta(int x1, int x2);
public:
    rectanglebrush(Image* i, int size);
    void DrawRectangle(int x, int y, int color);
    void OnMouseMove(int x, int y, int color) override;
    void OnMouseDown(int x, int y, int color) override;
    void OnMouseUp(int x, int y, int color) override;
};
}
#endif // RECTANGLEBRUSH_H
