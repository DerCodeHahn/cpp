#ifndef BRUSH_H
#define BRUSH_H

#include "image.h"
namespace my
{

class Brush
{
protected:
    Image* img_;
    int size_;
    void Emit(int x, int y, int color);
public:
    Brush();
    Brush(Image* i, int size):img_(i), size_(size)
    {
    }
    virtual void OnMouseDown(int x, int y, int color);
    virtual void OnMouseMove(int x, int y, int color);
    virtual void OnMouseUp(int x, int y, int color);
    void SetSize(int size);
    int GetSize();

};
}
#endif // BRUSH_H
