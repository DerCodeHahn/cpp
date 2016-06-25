#include "colorfader.h"

namespace my{

    ColorFader::ColorFader()
    {
        inc = true;
        channels = {255,0,0};
        i = 1;
    }

    void ColorFader::Update(){
        if(inc)
        {
            if(++channels[i % 3] == 255)
                inc = false;
        }
        else
        {
            if(--channels[i-1] == 0)
            {
                i++;
                inc = true;
            }
        }
        if(i == 4)
            i = 1;
    }

    std::vector<int> ColorFader::getColor(){
        return channels;
    }

}
