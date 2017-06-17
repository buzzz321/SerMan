#include "history.h"
#include <iostream>
History::History():position(0)
{
    cmdHistory.clear();
}

void History::addToHistory(std::string line)
{
        std::cout << "adding " << std::endl;
        cmdHistory.push_back(line);
        position = cmdHistory.size() - 1;
}

std::string History::getFromHistory(){
    return cmdHistory[position];
}

void History::stepBackHistory(){

    if(0 != position){
        position -= 1;
    }
}

void History::stepForwardHistory(){

    if(position < cmdHistory.size() - 1){
        position += 1;
    }
}

HistoryList History::dumpHistory(){
   return cmdHistory;
}
