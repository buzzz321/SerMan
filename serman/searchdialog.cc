#include "searchdialog.h"
#include "sermanwindow.h"
#include <iostream>

SearchDialog::SearchDialog(QWidget *parent)
    : QDialog(parent), search(new Ui::SearchDialogWindow) {
  search->setupUi(this);
  search->exit->setVisible(true);
  search->lineEdit->setVisible(true);
  search->search->setVisible(true);

  QObject::connect(search->search, &QPushButton::clicked,
                   static_cast<const SermanWindow *>(parent),
                   &SermanWindow::searchClicked);

  QObject::connect(search->exit, &QPushButton::clicked,
                   static_cast<const SermanWindow *>(parent),
                   &SermanWindow::searchDestoyed);
}

void SearchDialog::SearchInLog(QString &buffer, QString searchTerm) {
  int index = 0;
  while ((index = buffer.indexOf(searchTerm, index)) != -1) {
    int end = buffer.indexOf("\n", index);
    int start = buffer.lastIndexOf("\n", index);
    if (start == -1) {
      start = 0;
    }
    if (end == -1) {
      end = buffer.length() - 1;
    }

    std::cout << buffer.mid(start, end).toStdString() << std::endl;
  }
}
