#include "history.h"
#include <cassert>

namespace my {
    History::History(Image i):history(0)
    {
        Step s {i,"initial Pic"};
        history.push_back(s);
        Commit("INit");
    }

    void History::Commit(std::string msg){

        Step lastStep = history[history.size() - 1];
        lastStep.img.ClearFlags();
        Step newStep = {lastStep.img, msg}; // Error

        history.push_back(newStep);
    }

    Image& History::Current(){
        Step& lastStep = history[history.size() - 1];
        return lastStep.img ;
    }

    void History::Undo(){
        if(history.size() > 1)
            history.pop_back();
        //history.erase(history.end());
    }
}

