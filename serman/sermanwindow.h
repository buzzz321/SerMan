#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileSystemWatcher>
#include <QHostInfo>
#include <QMainWindow>
#include <QScrollBar>

#include "communicator.h"
#include "fileloader.h"
#include "history.h"
#include "searchdialog.h"
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
  void searchClicked();
  void searchDestoyed();
private slots:
  void on_sendButton_clicked();
  void on_actionConnect_triggered();
  void on_actionDisconnect_triggered();
  void on_newHostname(QHostInfo ipnumber);
  void on_hotload(const QString &path);
  void on_actionCleanup_triggered();
  void on_actionClear_Terminal_triggered();

  void on_action_Load_Commands_triggered();

  void on_actionShortCuts_triggered();

protected:
  bool eventFilter(QObject *dist, QEvent *event);

private:
  Ui::MainWindow *ui;
  SearchDialog *search;
  History commandHistory;
  Communicator *remote;
  FileLoader settings;
  QFileSystemWatcher watcher;
  bool searchMode = false;
  QString title;
};

#endif // MAINWINDOW_H
