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
    uint32_t CheckCell(int x, int y, Image* inImg);
    std::vector<uint32_t> GetSurrounding(int x, int y, Image* inImg);
    void FragUpdate(int x, int y, int width, int height, Image* inImg, Image* outImg);
public:
    GameOfLife();
    GameOfLife( bool multi);
    void Update(Image* img);

};
}

#endif // GAMEOFLIFE_H
