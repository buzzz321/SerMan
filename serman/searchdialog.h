#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QObject>
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
  void SearchInLog(QString &buffer, QString searchTerm);
signals:

public slots:

private slots:

private:
  Ui::SearchDialogWindow *search;
};

#endif // SEARCHDIALOG_H
