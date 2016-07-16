#include "gameoflife.h"
#include "thread"

namespace my {
GameOfLife::GameOfLife(){}

GameOfLife::GameOfLife(bool multi):
    multipleLifeForms(multi)
{

}

void GameOfLife::Update(Image* img){
    Image newImage = Image(*img);
    //FragUpdate(0,0,img->width(),img->height(), &newImage, img);
    std::thread t1 ([&](){this->FragUpdate(0,0,(int)img->width()/ 2, (int)img->height() / 2, &newImage, img);});
    std::thread t2 ([&](){this->FragUpdate(img->width()/ 2,0, img->width(), img->height(), &newImage, img);});
    std::thread t3 ([&](){this->FragUpdate(0, img->height() / 2, img->width(), img->height(), &newImage, img);});
    std::thread t4 ([&](){this->FragUpdate(img->width()/ 2, img->height() / 2, img->width(), img->height(), &newImage, img);});

    t1.join();
    t2.join();
    t3.join();
    t4.join();
     //*img = newImage;

}

void GameOfLife::FragUpdate(int xx, int yy, int xmax, int ymax, Image* inImg, Image* outImg){
    for (int x = xx; x < xmax; ++x) {
        for (int y = yy; y < ymax; ++y) {
            uint32_t pixColor = inImg->getPixel(x,y);
                uint32_t color = CheckCell(x,y, inImg);
                if(pixColor != color){
                    outImg->set_pixel(x,y,color);

                }
        }
    }
}

//return the color of the current Cell
uint32_t GameOfLife::CheckCell(int x, int y, Image* inImg){
    std::vector<uint32_t> surrounding = GetSurrounding(x,y, inImg);
    if(surrounding.size() <= 1 || surrounding.size() >= 4) //Über und Unterpopulation
        return inImg->getBackgroundColor();
    if(surrounding.size() != 3 && inImg->getPixel(x , y) == inImg->getBackgroundColor())//Tote Zelle beleben
        return inImg->getBackgroundColor();

    return surrounding[0];
}

std::vector<uint32_t> GameOfLife::GetSurrounding(int x, int y, Image* inImg){
    std::vector<uint32_t> surr;
    for (int xx = -1; xx <= 1; xx++) {
        for (int yy = -1; yy <= 1; yy++) {
            if(!(xx == 0 && yy == 0)){
                uint32_t pixelColor = inImg->getPixel(x + xx,y + yy);
                if(pixelColor != inImg->getBackgroundColor())
                {
                    surr.push_back(pixelColor);
                }
            }
        }
    }
    //if(surr.size() != 8)
    //    std::cout << " end "<< surr.size() <<std::endl;

    return surr;
}

}

