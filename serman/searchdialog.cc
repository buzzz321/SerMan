#include "searchdialog.h"

SearchDialog::SearchDialog(QWidget *parent)
    : QDialog(parent), search(new Ui::SearchDialogWindow) {
  search->setupUi(this);
  search->exit->setVisible(true);
  search->lineEdit->setVisible(true);
  search->search->setVisible(true);
}
