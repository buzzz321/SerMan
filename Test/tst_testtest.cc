#include "history.h"
#include <QString>
#include <QtTest>

#include <iostream>

using namespace std;

class TestHistory : public QObject {
  Q_OBJECT

public:
  TestHistory();

private Q_SLOTS:
  void testAddToHistory();
  void testGetThirdItemFromHistory();
  void testGetOldestItemFromHistory();
  void testGetNewestItemFromHistory();
  void testFindCommandInHistory();
};

TestHistory::TestHistory() {}

void TestHistory::testAddToHistory() {
  History his;

  his.addToHistory("row1");
  his.addToHistory("row2");
  his.addToHistory("row3");
  his.addToHistory("row4");

  QCOMPARE(QString(his.getFromHistory().c_str()), QString("row4"));
}

void TestHistory::testGetThirdItemFromHistory() {
  History his;

  his.addToHistory("row1");
  his.addToHistory("row2");
  his.addToHistory("row3");
  his.addToHistory("row4");

  his.stepBackHistory();
  his.stepBackHistory();
  QCOMPARE(QString(his.getFromHistory().c_str()), QString("row2"));
}

void TestHistory::testGetOldestItemFromHistory() {
  History his;

  his.addToHistory("row1");
  his.addToHistory("row2");
  his.addToHistory("row3");
  his.addToHistory("row4");

  for (int i = 0; i < 100000; i++) {
    his.stepBackHistory();
  }

  QCOMPARE(QString(his.getFromHistory().c_str()), QString("row1"));
}

void TestHistory::testGetNewestItemFromHistory() {
  History his;

  his.addToHistory("row1");
  his.addToHistory("row2");
  his.addToHistory("row3");
  his.addToHistory("row4");

  for (int i = 0; i < 100000; i++) {
    his.stepBackHistory();
  }

  for (int i = 0; i < 100000; i++) {
    his.stepForwardHistory();
  }

  QCOMPARE(QString(his.getFromHistory().c_str()), QString("row4"));
}

void TestHistory::testFindCommandInHistory() {
  History his;

  his.addToHistory("row1");
  his.addToHistory("row2");
  his.addToHistory("row3");
  his.addToHistory("row4");

  QCOMPARE(QString(his.find("row1")[0].c_str()), QString("row1"));

  auto retVal = his.find("row");
  QCOMPARE(QString(retVal[3].c_str()), QString("row4"));

  for (auto &item : retVal) {
    std::cout << item << std::endl;
  }
}

QTEST_APPLESS_MAIN(TestHistory)

#include "tst_testtest.moc"
