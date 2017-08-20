#include "sermanwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  SermanWindow w;
  w.show();

  return a.exec();
}
