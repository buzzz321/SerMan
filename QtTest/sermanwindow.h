#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "history.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_sendButton_clicked();
protected:
  bool eventFilter( QObject *dist, QEvent *event );

private:
    Ui::MainWindow *ui;
    History commandHistory;
};

#endif // MAINWINDOW_H
