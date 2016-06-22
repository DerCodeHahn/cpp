#ifndef BRUSH_H
#define BRUSH_H

#include "image.h"
namespace my
{

class Brush
{
private:
    Image* img_;
    int size_;
public:

    Brush(Image* i, float size):img_(i), size_(size)
    {
    }
    void OnMouseDown(int x, int y, int color);
    void OnMouseMove(int x, int y, int color);
    void SetSize(int size);
};
}
#endif // BRUSH_H
