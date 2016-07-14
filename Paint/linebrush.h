#ifndef LINEBRUSH_H
#define LINEBRUSH_H

#include <sstream>
#include "brush.h"

namespace my{
class LineBrush:public Brush
{
private:
    int getDirection(int pos, int target);
    int GetDelta(int x1, int x2);
public:
    LineBrush(History* h, int size);
    void DrawLine(int x, int y, int color);
    void OnMouseMove(int x, int y, int color) override;
    void OnMouseDown(int x, int y, int color) override;
    void OnMouseUp(int x, int y, int color) override;
};
}
#endif // LINEBRUSH_H
