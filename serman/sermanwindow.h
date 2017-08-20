#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollBar>

#include "communicator.h"
#include "history.h"
#include <QTextCursor>

namespace Ui {
class MainWindow;
}

class SermanWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit SermanWindow(QWidget *parent = 0);
  ~SermanWindow();

public slots:
  void gotRemoteData();
private slots:
  void on_sendButton_clicked();
  void on_actionConnect_triggered();
  void on_actionDisconnect_triggered();

protected:
  bool eventFilter(QObject *dist, QEvent *event);

private:
  Ui::MainWindow *ui;
  History commandHistory;
  Communicator *remote;
};

#endif // MAINWINDOW_H
