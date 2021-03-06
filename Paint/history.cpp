#include "history.h"
#include <cassert>

#include <iostream>

namespace my {
    History::History(Image i):history(0)
    {
        Step s {i,"initial Pic"};
        history.push_back(s);
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

    std::vector<std::string> History::GetNameList(){
        std::vector<std::string> list;
        for(Step& s : history)
            list.push_back(s.Message);
        return list;
    }

    Image& History::GetImage(int nr)
    {
        Step& s =  history[history.size() - 1 - nr];
        return s.img;
    }
}

