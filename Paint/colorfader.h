#ifndef COLORFADER_H
#define COLORFADER_H

#include <vector>

namespace my{
class ColorFader
{
private:
    //int r,g,b; //Frage: wie viel Spart es ein hier ein kleineren Daten typ zu nehemen
    std::vector<int> channels;
    bool inc;
    int i;
public:
    ColorFader();
    void Update();
    std::vector<int> getColor();

};
}

#endif // COLORFADER_H
