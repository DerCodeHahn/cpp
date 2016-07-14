#ifndef RECTANGLEBRUSH_H
#define RECTANGLEBRUSH_H

#include <sstream>
#include "brush.h"

namespace my{
class RectangleBrush:public Brush
{

private:
    int getDirection(int pos, int target);
    int GetDelta(int x1, int x2);
public:
    RectangleBrush(History *h, int size);
    void DrawRectangle(int x, int y, int color);
    void OnMouseMove(int x, int y, int color) override;
    void OnMouseDown(int x, int y, int color) override;
    void OnMouseUp(int x, int y, int color) override;
};
}
#endif // RECTANGLEBRUSH_H
