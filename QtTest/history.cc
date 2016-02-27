#include "history.h"

History::History():position(0)
{

}

void History::addToHistory(std::string line)
{
    cmdHistory.push_back(line);
    position = cmdHistory.size();
}

std::string History::getFromHistory(){
    HistoryList::size_type pos = 0;

    if (position < cmdHistory.size()){
        pos = position - 1;
    } else {
        pos = cmdHistory.size() - 1;
    }

    return cmdHistory[pos];
}

void History::stepBackHistory(){

    if(position > 1){
        position -= 1;
    }
}

void History::stepForwardHistory(){

    if(position < cmdHistory.size()){
        position += 1;
    }
}
