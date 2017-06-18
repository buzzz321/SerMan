#ifndef SERMAN_H
#define SERMAN_H

#include <vector>
#include <string>

typedef std::vector<std::string> HistoryList;

class History
{
public:
    History();

    void addToHistory(std::string line);
    std::string getFromHistory();
    void stepBackHistory();
    void stepForwardHistory();
    HistoryList dumpHistory();
private:
    HistoryList cmdHistory;
    HistoryList::size_type position;
};

#endif // SERMAN_H
