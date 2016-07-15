#ifndef PATTERNBRUSH_H
#define PATTERNBRUSH_H

#include "brush.h"

namespace my{
class PatternBrush : public Brush
{

public:
    struct Pattern {const std::string name ;const std::vector<std::string> content; };

    static std::vector<Pattern> GetPatterns();
    Pattern activePattern;

    PatternBrush();
    PatternBrush(History* h, int p);

    void OnMouseMove(int x, int y, int color) override;
    void OnMouseDown(int x, int y, int color) override;
    void OnMouseUp(int x, int y, int color) override;
};
}
#endif // PATTERNBRUSH_H
