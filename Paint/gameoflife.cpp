#include "gameoflife.h"

namespace my {
GameOfLife::GameOfLife(){}

GameOfLife::GameOfLife(Image* img, bool multi):
    image(img),
    multipleLifeForms(multi)
{

}

void GameOfLife::Update(){
    newImage = Image(*image);
    for (int x = 0; x < image->width(); ++x) {
        for (int y = 0; y < image->height(); ++y) {
            uint32_t pixColor = newImage.getPixel(x,y);
            //if(pixColor != newImage.getBackgroundColor())
            //{
                uint32_t color = CheckCell(x,y);
                if(pixColor != color){
                    newImage.set_pixel(x,y,color);

                }

            //}
        }
    }
    *image = newImage;
}
//return the color of the current Cell
uint32_t GameOfLife::CheckCell(int x, int y){
    std::vector<uint32_t> surrounding = GetSurrounding(x,y);
    if(surrounding.size() <= 2 || surrounding.size() >= 4) //Über und Unterpopulation
        return image->getBackgroundColor();

    return surrounding[0];
}

std::vector<uint32_t> GameOfLife::GetSurrounding(int x, int y){
    std::vector<uint32_t> surr;
    for (int xx = -1; xx <= 1; xx++) {
        for (int yy = -1; yy <= 1; yy++) {
            if(!(xx == 0 && yy == 0)){
                uint32_t pixelColor = image->getPixel(x + xx,y + yy);
                if(pixelColor != image->getBackgroundColor())
                {
                    surr.push_back(pixelColor);
                }
            }
        }
    }
    //if(surr.size() != 0)
    //    std::cout << " end "<< surr.size() <<std::endl;

    return surr;
}

}

