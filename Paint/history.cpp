#include "history.h"
#include <cassert>

#include <iostream>

namespace my {
    History::History(Image i):history(0)
    {
        Step s {i,"initial Pic"};
        history.push_back(s);
        Commit("first Save");
    }

    void History::Commit(std::string msg){

        Step lastStep = history[history.size() - 1];
        //lastStep.img.ClearFlags();
        Step newStep = {lastStep.img, msg};

        history.push_back(newStep);
        std::cout << "Commit " << history.size() << " [" << msg <<"]"<< std::endl;
    }

    Image& History::Current(){
        Step& lastStep = history[history.size()-1];
        return lastStep.img ;
    }

    void History::Undo(){
        if(history.size() > 1)
            history.pop_back();
        std::cout << "Undo now at "<< history.size()<< ((Step)history[history.size() - 1]).Message << std::endl;
        //history.erase(history.end());
    }
}

