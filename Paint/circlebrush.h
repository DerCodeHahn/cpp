#ifndef CIRCLEBRUSH_H
#define CIRCLEBRUSH_H

#include "brush.h"

namespace my {
class CircleBrush:public Brush
{

private:

    int getDirection(int pos, int target);
    int GetDelta(int x1, int x2);
public:
    CircleBrush(History* h, int size);
    void DrawCircle(int x, int y, int color);
    void OnMouseMove(int x, int y, int color) override;
    void OnMouseDown(int x, int y, int color) override;
    void OnMouseUp(int x, int y, int color) override;
};
}
#endif // CIRCLEBRUSH_H
