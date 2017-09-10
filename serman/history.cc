#include "history.h"
#include <fstream>
#include <iostream>
#include <regex>
#include<limits>


History::History()
    : position(std::numeric_limits<std::size_t>::max()), currentSearchIndex(0), fileName(".serman_history") {
  cmdHistory.clear();
}

History::History(std::string path)
    : position(std::numeric_limits<std::size_t>::max()), currentSearchIndex(0), fileName(path + "/.serman_history") {
  cmdHistory.clear();
}

void History::addToHistory(std::string line) {
  std::cout << "adding " << std::endl;
  cmdHistory.push_back(line);
  position = cmdHistory.size() - 1;
}

std::string History::getFromHistory() {
    if ( position < std::numeric_limits<std::size_t>::max() ) {
        return cmdHistory[position];
    }
    else {
        return "";
    }
}

void History::stepBackHistory() {

  if (0 != position && position < std::numeric_limits<std::size_t>::max()) {
    position -= 1;
  }
}

void History::stepForwardHistory() {

  if (position < cmdHistory.size() - 1) {
    position += 1;
  }
}

HistoryList History::dumpHistory() { return cmdHistory; }

HistoryList History::find(std::string cmd) {
  HistoryList retVal;

  std::smatch m;
  std::regex e(cmd); // matches words beginning by "sub"

  for (auto &item : cmdHistory) {
    bool found = std::regex_search(item, m, e);
    if (found) {
      std::cout << item << std::endl;
      retVal.push_back(item);
    }
  }

  currentSearch = retVal;
  return retVal;
}

std::string History::stepForwardSearch() {
  std::string retVal;
  if (currentSearchIndex < currentSearch.size()) {
    currentSearchIndex += 1;
  }
  if (currentSearchIndex >= currentSearch.size()) {
    currentSearchIndex = 0;
  }
  if (currentSearch.size() > 0) {
    retVal = currentSearch[currentSearchIndex];
  }
  return retVal;
}

void History::readFromDisc() {
  std::ifstream myfile;
  std::string line;
  myfile.open(fileName);
  if (myfile.is_open()) {
    while (std::getline(myfile, line)) {
      cmdHistory.push_back((line));
    }
    myfile.close();
  }
}

void History::saveToDisc() {
  std::ofstream myfile;
  myfile.open(fileName);
  if (myfile.is_open()) {
    for (auto &item : cmdHistory) {
      myfile << item << std::endl;
    }
    myfile.close();
  }
}

HistoryList History::removeDuplicates() { return cmdHistory; }
