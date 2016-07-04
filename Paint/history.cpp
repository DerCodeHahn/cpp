#include "history.h"

namespace my {
    History::History(Image i)
    {
        Step s {i,"initial Pic"};
        history.push_back(s);
    }

    void History::Commit(std::string msg){

    }

    Image& History::Current(){
        Step& lastStep = history.back();
        return lastStep.img ;
    }

    void History::Undo(){

    }
}

