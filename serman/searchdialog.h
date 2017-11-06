#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QObject>
#include <QTextDocument>
#include <QWidget>
#include <ui_search-dialog.h>

namespace Ui {
class SearchDialogWindow;
}

class SearchDialog : public QDialog {
  Q_OBJECT
public:
  explicit SearchDialog(QWidget *parent = nullptr);
  ~SearchDialog() { delete search; }
  QTextCursor SearchInLog(const QTextDocument *buffer);
signals:

public slots:

private slots:

private:
  Ui::SearchDialogWindow *search;
  int m_lastpos = 0;
};

#endif // SEARCHDIALOG_H
