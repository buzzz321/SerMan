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

QTextCursor SearchDialog::SearchInLog(const QTextDocument *buffer) {
  auto searchItem = search->lineEdit->text().trimmed();
  auto found = buffer->find(searchItem, m_lastpos);

  if (found.isNull() && m_lastpos != 0) {
    m_lastpos = 0;
  } else if (!found.isNull()) {
    m_lastpos = found.position();
  }
  return found;
}
