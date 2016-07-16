#ifndef HISTORY_H
#define HISTORY_H

#include <vector>
#include <image.h>
#include <string>

namespace my {



class History
{
    struct Step {Image img; std::string Message; };
    std::vector<Step> history;
public:
    History();
    History(Image i);
    void Commit(std::string msg);
    Image& Current();
    void Undo();
    std::vector<std::string> GetNameList();
    my::Image& GetImage(int nr);
};
}

#endif // HISTORY_H
