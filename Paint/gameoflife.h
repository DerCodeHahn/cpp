#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "image.h"
#include <vector>
#include <iostream>


namespace my {
class GameOfLife
{
private:
    bool multipleLifeForms;
    Image* image;
    Image newImage;
    uint32_t CheckCell(int x, int y);
    std::vector<uint32_t> GetSurrounding(int x, int y);
public:
    GameOfLife();
    GameOfLife(Image* img, bool multi);
    void Update();

};
}

#endif // GAMEOFLIFE_H
