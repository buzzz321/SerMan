#ifndef SERMAN_H
#define SERMAN_H

#include <string>
#include <vector>

typedef std::vector<std::string> HistoryList;

class History {
public:
  History();
  History(std::string path);

  void addToHistory(std::string line);
  std::string getFromHistory();
  void stepBackHistory();
  void stepForwardHistory();
  HistoryList dumpHistory();
  HistoryList find(std::string cmd);
  std::string stepForwardSearch();

  void readFromDisc();
  void saveToDisc();

private:
  HistoryList cmdHistory;
  HistoryList::size_type position;
  HistoryList currentSearch;
  HistoryList::size_type currentSearchIndex;
  std::string fileName;
};

#endif // SERMAN_H
