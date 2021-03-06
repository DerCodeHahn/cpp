#include "patternbrush.h"
#include <iostream>

namespace my{
PatternBrush::PatternBrush():activePattern (GetPatterns()[0])
{
    Description = "PatternBrush";
}
PatternBrush::PatternBrush(History* h, int p):activePattern(GetPatterns()[p])
{
    history = h;
}

void  PatternBrush::OnMouseMove(int xpos, int ypos, int color)
{

}

void PatternBrush::OnMouseDown(int xpos, int ypos, int color)
{
    char livingCell = 'O';
    //std::cout << "painting:" << activePattern.name <<" : "<< activePattern.content.size() <<std::endl;
    for(int y = 0; y < activePattern.content.size(); y++)
    {
        std::string row = activePattern.content[y];
        for(int x = 0; x < row.size(); x++ )
        {
            char cell = row.data()[x];

            if(cell == livingCell)
            {
        //        std::cout << "x " << x << " y " << y << std::endl;
                history->Current().set_pixel(xpos + x, ypos + y , color);

            }
        }
    }
}

void PatternBrush::OnMouseUp(int x, int y, int color){

}
std::vector<PatternBrush::Pattern> PatternBrush::GetPatterns(){
    return  {
        Pattern{"Acron" , {".O","...O","OO..OOO"}},
        Pattern{"Glider" ,{".O","..O","OOO"}},
        Pattern{"Smal Spaceship" , {".O..O","O", "O...O","OOOO"}},
        Pattern{"Big Spaceship" , {"...OO",".O....O","O","O.....O","OOOOOO"}},
        Pattern{"25P3H1V0.2" ,{".......OO.O","....OO.O.OO.OOO",".OOOO..OO......O","O....O...O...OO",".OO"}},
        Pattern{"Weekender",{".O............O",".O............O","O.O..........O.O",".O............O",".O............O","..O...OOOO...O","......OOOO","..OOOO....OOOO","","....O......O",".....OO..OO"}},
        Pattern{"Glider Diamant", {"....OOOO","","..OOOOOOOO","","OOOOOOOOOOOO","","..OOOOOOOO","","....OOOO"}},
        Pattern{"Glider Gun" , {"........................O","......................O.O","............OO......OO............OO","...........O...O....OO............OO","OO........O.....O...OO","OO........O...O.OO....O.O","..........O.....O.......O","...........O...O","............OO"}},
        Pattern{"Brain" , {".OOO.........OOO","O.O.OO.....OO.O.O","O.O.O.......O.O.O",".O.OO.OO.OO.OO.O",".....O.O.O.O","...O.O.O.O.O.O","..OO.O.O.O.O.OO","..OOO..O.O..OOO","..OO..O...O..OO",".O....OO.OO....O",".O.............O"}},
        Pattern{"Vulcano", {"....OOOOO","...O.....O",".OOO.....OOO","O...........O","O.OOO.O.OOOO",".O...OOO","...O.....OO.O","..OO.O.O.O.OO","...O.O..O","...O..OO","..OO"}},
        Pattern{"Star",{"........................................OO",
                        "........................................OO",
                        "........................................OO",
                        "........................................O",
                        ".......................................O.O",
                        ".......................................O.OO",
                        "",
                        "..............................................OO",
                        "........................................OO....OO",
                        "........................................OO",
                        "",
                        "............................................................O..........................OO",
                        "..................................................OO........OOO........................O",
                        "..................................................O.O..........O.....................O.O",
                        "..................................................O...........OO...............O.....OO....OO",
                        "..............................................................................OO...........OO",
                        "...................................................OO.........................O.O",
                        "...............................................O...O..O.....................................O",
                        "..............................................O..O.OOO.....................................O.O",
                        "..............................................OOO.O.......................................O..O",
                        "........................................OO.....O.OOO.....................................O..O",
                        "........................................OO...........O",
                        "........................................OO......................OO.......................O..O",
                        ".........................................O......................OO.........................OO",
                        "........................................O.O",
                        ".......................................OO.O............OOO",
                        ".......................................................O",
                        "........................................................O",
                        "........................................OO",
                        "........................................OO.........................................................OOO",
                        "",
                        ".........................................................................OO....................OOO.O..O",
                        "..........................................................................O.......OO.........O.OOO",
                        ".......................................................................OOO........OO........O......OOO",
                        ".......................................................................O....................OO",
                        "",
                        "...............................................................................................OO",
                        ".......................................................................................OO.........OO",
                        ".......................................................................................OO.......O.O",
                        "...........................................OO....................................................O.........................O...................OO",
                        "...........................................OO..........................................................................OO..OO.OOO..........OO....OOOO",
                        "......................................................................................................OO...............OO....OOOO..........OO..OO.OOO",
                        "....................................................................................OO...............OOO...................OO..................O",
                        "...........................................OOO..................................OO..OO..OO..........O.O..O..OO",
                        "............................................OO..................................O.O..O..OO..........OO..OO..OO",
                        ".........................................OO......................................OOO....................OO",
                        "...............................O.........OOO......................................OO.............................................OO.........OO",
                        ".............................O...O........O.O...................................................................................OO.O........OO",
                        ".............................O...O.........OO....................................................................................O",
                        ".............................O.O.O...O..........................................................................................O.O",
                        ".....................................OO.........................................................................................OO....OOO",
                        "...............................OO......O........................................................................................O.OOO...O",
                        "...............................OO...O.O...........................................................................................O.O..O",
                        "...............................OO...O..........................................................................................O..O",
                        "...................................................................................................................................O",
                        "..................OO............O.O..........................O............................................................OO",
                        "..............OO.O..O.OO.........OO..........................O.O.........................................................O.O",
                        "..............OO..O....O.....................................OO............................................................O",
                        "...................O",
                        "....................O.O....................OO",
                        "...........O.........................OO....OO...........................................................................................OO",
                        "...........OOO.......................OO....................................................OOO..........................................O",
                        "..............O............................................................................O..........................................O.O",
                        ".............OO...........................OOO...............................................O.........................................OO",
                        "..........................................OO.................................................................................OO",
                        "................................OO...........OO..............................................................................OO",
                        "................................OO..........OOO",
                        "...........................................O.O",
                        "................O..........................OO",
                        "..............OO",
                        "...............OO",
                        "..................................................................................................................OO",
                        "...................................................................................................................O",
                        "...................................................................................................................O.O",
                        "...............................OO...................................................................................OO",
                        "...............................O.O",
                        ".................................O",
                        ".................................OO",
                        "....................................................................................................................................OO",
                        ".....................................................................................................................................OO",
                        "........................................................................................................OO..........................O",
                        ".......................................................................................................O.O",
                        "......................................................................................................OOO..........OO",
                        "......................OO..............................................................................OO...........OO",
                        "......................OO.................................................................................OO",
                        ".............OO.........................................O...............................................OOO...........................OO",
                        "............O.O..........................................O............................................................................O",
                        "............O..........................................OOO....................................................OO.......................OOO",
                        "...........OO...........................................................................................OO....OO.........................O",
                        "........................................................................................................OO....................O.O",
                        ".................................................................................................................................O",
                        ".........................O............................................................OO.....................................O....O..OO",
                        ".........................O.O.........................................................O.O..........................OO.........OO.O..O.OO",
                        ".........................OO............................................................O..........................O.O............OO",
                        ".................O",
                        "..................O..O..........................................................................................O...OO",
                        ".............O..O.O...........................................................................................O.O...OO",
                        "............O...OOO.O........................................................................................O......OO",
                        "............OOO....OO.........................................................................................OO",
                        "..................O.O..........................................................................................O...O.O.O",
                        "...................O....................................................................................OO.........O...O",
                        ".......OO........O.OO...................................................................................O.O........O...O",
                        ".......OO.........OO.............................................OO......................................OOO.........O",
                        "...........................................OO....................OOO......................................OO",
                        ".......................................OO..OO..OO..........OO..O..O.O..................................OO",
                        ".......................................OO..O..O.O..........OO..OO..OO..................................OOO",
                        ".....O..................OO...................OOO...............OO",
                        "OOO.OO..OO..........OOOO....OO...............OO",
                        "OOOO....OO..........OOO.OO..OO..........................................................................OO",
                        "....OO...................O.........................O....................................................OO",
                        "..................................................O.O.......OO",
                        ".................................................OO.........OO",
                        "....................................................OO",
                        "",
                        ".......................................................OO....................O",
                        "...............................................OOO......O........OO........OOO",
                        "...................................................OOO.O.........OO.......O",
                        "..............................................O..O.OOO....................OO",
                        "",
                        "...............................................OOO.........................................................OO",
                        "...........................................................................................................OO",
                        "............................................................................................O",
                        ".............................................................................................O",
                        "...........................................................................................OOO............O.OO",
                        "..........................................................................................................O.O",
                        "........................................................OO.........................OO......................O",
                        "........................................................O..O.......................OO......................OO",
                        "...............................................................................................O...........OO",
                        "........................................................O..O.....................................OOO.O.....OO",
                        ".......................................................O..O.......................................O.OOO",
                        ".......................................................O.O.....................................OOO.O..O",
                        "........................................................O.....................................O..O...O",
                        "....................................................................O.O.........................OO",
                        "........................................................OO...........OO",
                        "........................................................OO....OO.....O...............OO...........O",
                        ".............................................................O.O.....................O..........O.O",
                        ".............................................................O........................OOO........OO",
                        "............................................................OO..........................O",
                        "",
                        "...........................................................................................................OO ",
                        ".....................................................................................................OO....OO ",
                        ".....................................................................................................OO",
                        ""
                        "..........................................................................................................OO.O",
                        "...........................................................................................................O.O",
                        "............................................................................................................O",
                        "...........................................................................................................OO",
                        "...........................................................................................................OO",
                        "...........................................................................................................OO"}}
    };
}
}
