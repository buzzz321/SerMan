#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

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

signals:

public slots:

private:
  Ui::SearchDialogWindow *search;
};

#endif // SEARCHDIALOG_H
