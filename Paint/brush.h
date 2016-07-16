#ifndef BRUSH_H
#define BRUSH_H

#include "history.h"
namespace my
{

class Brush
{
protected:
    History* history;
    int lastX;
    int lastY;
    int size_;
    void Emit(int x, int y, int color);
public:
    Brush();
    Brush(History* h, int size):history(h), size_(size)
    {
        Description = "DotBrush";
    }
    virtual void OnMouseDown(int x, int y, int color);
    virtual void OnMouseMove(int x, int y, int color);
    virtual void OnMouseUp(int x, int y, int color);
    std::string Description;
    void SetSize(int size);
    int GetSize();

};
}
#endif // BRUSH_H
