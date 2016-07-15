#ifndef STRAIGHTLINEBRUSH_H
#define STRAIGHTLINEBRUSH_H

#include <sstream>
#include "brush.h"

namespace my{
class StraightLineBrush:public Brush
{
private:
    int lastX;
    int lastY;
    int getDirection(int pos, int target);
    int GetDelta(int x1, int x2);
public:
    StraightLineBrush(Image* i, int size);
    void DrawLine(int x, int y, int color);
    void OnMouseMove(int x, int y, int color) override;
    void OnMouseDown(int x, int y, int color) override;
    void OnMouseUp(int x, int y, int color) override;
};
}

#endif // STRAIGHTLINEBRUSH_H
