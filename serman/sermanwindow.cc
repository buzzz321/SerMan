#include "sermanwindow.h"
#include "searchdialog.h"
#include "ui_sermanwindow.h"
#include "util.h"
#include <QDir>
#include <QFileDialog>
#include <QFileInfo>
#include <QInputDialog>
#include <QKeyEvent>
#include <QMessageBox>
#include <QStandardPaths>
#include <fstream>
#include <iostream>
#include <thread>

using namespace std;

SermanWindow::SermanWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), search(nullptr),
      remote(new Communicator(this)) {
  ui->setupUi(this);
  ui->logEdit->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
  ui->logEdit->setVisible(true);
  ui->cmdLineEdit->installEventFilter(this);
  ui->logEdit->installEventFilter(this);
  title = this->windowTitle();

  commandHistory = History(QDir::homePath().toStdString());
  commandHistory.readFromDisc();
  watcher.addPath(QStandardPaths::locate(QStandardPaths::HomeLocation,
                                         FileLoader::fileName));

  QObject::connect(&watcher, &QFileSystemWatcher::fileChanged, this,
                   &SermanWindow::on_hotload);

  auto filesettings = settings.loadSettings();

  if (filesettings.prepend != "") {
    remote->setPrepend(filesettings.prepend);
  }
  if (filesettings.hostName != "") {
    remote->setPort(filesettings.port);
    cout << "|" << filesettings.hostName.toStdString() << "|" << endl;
    QHostInfo::lookupHost(filesettings.hostName, this,
                          SLOT(on_newHostname(QHostInfo)));
    auto title = this->windowTitle();
    QString str;
    str.setNum(filesettings.port);
    title += " " +filesettings.hostName +" on port:" + str;
    this->setWindowTitle(title);
  }
}

SermanWindow::~SermanWindow() {
  delete remote;
  delete search;
  delete ui;
}

void SermanWindow::on_sendButton_clicked() {
  commandHistory.addToHistory(ui->cmdLineEdit->text().toStdString());

  cout << ui->cmdLineEdit->text().toStdString() << endl;
  remote->sendCommand(ui->cmdLineEdit->text() + "\n");

  auto retVal = ui->cmdLineEdit->text();
  auto scrollBar = ui->logEdit->verticalScrollBar();
  scrollBar->setValue(scrollBar->maximumHeight());
  ui->logEdit->append(retVal);
  ui->cmdLineEdit->clear();
}

void SermanWindow::on_newHostname(QHostInfo ipnumber) {
  auto addresses = ipnumber.addresses();
  if (addresses.size() > 0) {
    cout << "on_newHostname:" << addresses[0].toString().toStdString() << endl;
    cout << "port: " << remote->getPort() << std::endl;
    remote->setAddress(addresses[0]);
  }
}

void SermanWindow::on_hotload(const QString &path) {

  if (path.contains(FileLoader::fileName)) {
    auto filesettings = settings.loadSettings();
    remote->setPrepend(filesettings.prepend);
    if (filesettings.hostName != "") {
      remote->setPort(filesettings.port);
      cout << "|" << filesettings.hostName.toStdString() << "|" << endl;
      QHostInfo::lookupHost(filesettings.hostName, this,
                            SLOT(on_newHostname(QHostInfo)));
      QString title = title + " " + filesettings.hostName;
      QString str;
      str.setNum(filesettings.port);
      title += " on port:" + str;
      this->setWindowTitle(title);
    }
  } else {
    std::cout << path.toStdString() << std::endl;
  }

  // apperently this code is needed on linux since some editors delete the file
  // and make a new one instead of change it.
  QFileInfo checkFile(path);
  while (!checkFile.exists())
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  watcher.addPath(path);
}

bool SermanWindow::eventFilter(QObject *dist, QEvent *event) {
  if (event->type() == QEvent::KeyPress) {
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

    if (keyEvent->key() == Qt::Key_Up) {
      ui->cmdLineEdit->setText(
          QString(commandHistory.getFromHistory().c_str()));
      commandHistory.stepBackHistory();

      return true;
    }

    if (keyEvent->key() == Qt::Key_Down) {
      ui->cmdLineEdit->setText(
          QString(commandHistory.getFromHistory().c_str()));
      commandHistory.stepForwardHistory();
      // cout << "down arrow" << endl;
      return true;
    }

    if (keyEvent->key() == Qt::Key_Return) {
      on_sendButton_clicked();
      return true;
    }
    if ((keyEvent->key() == Qt::Key_D) &&
        (QApplication::keyboardModifiers() & Qt::ControlModifier)) {
      for (auto line : commandHistory.dumpHistory()) {
        std::cout << line << std::endl;
      }
    }
    if ((keyEvent->key() == Qt::Key_R) &&
        (QApplication::keyboardModifiers() & Qt::ControlModifier)) {
      if (!searchMode) {
        auto found = commandHistory.find(ui->cmdLineEdit->text().toStdString());
        if (found.size() > 0) {
          ui->cmdLineEdit->setText(QString(found[0].c_str()));
        }
        searchMode = true;
        std::cout << "searching" << std::endl;
        statusBar()->showMessage("Searching");
      } else {
        auto line = commandHistory.stepForwardSearch();
        ui->cmdLineEdit->setText(QString(line.c_str()));
      }
    }
    if ((keyEvent->key() == Qt::Key_F) &&
        (QApplication::keyboardModifiers() & Qt::ControlModifier)) {

      std::cout << "finding" << std::endl;

      if (nullptr == search) {
        search = new SearchDialog(this);
      }

      search->setVisible(true);
      search->show();
    }
    if (((keyEvent->key() == Qt::Key_G) &&
         (QApplication::keyboardModifiers() & Qt::ControlModifier)) ||
        (keyEvent->key() == Qt::Key_Escape)) {
      searchMode = false;
      std::cout << "search mode off" << std::endl;
      statusBar()->clearMessage();
    }
  }

  return QObject::eventFilter(dist, event);
}

void SermanWindow::on_actionConnect_triggered() { remote->connect(); }

void SermanWindow::on_actionDisconnect_triggered() { remote->disconnect(); }

void SermanWindow::gotRemoteData() {
  auto retVal = remote->getRemoteData();
  auto scrollBar = ui->logEdit->verticalScrollBar();
  scrollBar->setValue(scrollBar->maximumHeight());
  ui->logEdit->append(retVal);
}

void SermanWindow::on_actionCleanup_triggered() {}

void SermanWindow::on_actionClear_Terminal_triggered() { ui->logEdit->clear(); }

void SermanWindow::searchClicked() {
  auto found = search->SearchInLog(ui->logEdit->document());
  if (!found.isNull()) {
    ui->logEdit->setTextCursor(found);
  }
  std::cout << "clicked" << std::endl;
}
void SermanWindow::searchDestoyed() {
  std::cout << "exit" << std::endl;
  search->close();
}

void SermanWindow::on_action_Load_Commands_triggered() {
  auto fileName = QFileDialog::getOpenFileName(
      this, tr("Open Command file"),
      QStandardPaths::locate(QStandardPaths::HomeLocation, ""),
      tr("Command Files (*.cmd *.bat )"));
  std::cout << "Load some files" << std::endl;

  std::ifstream myfile(fileName.toStdString());

  if (myfile.is_open()) {
    std::string line;

    while (std::getline(myfile, line)) {
      QString tmp(line.c_str());
      tmp.trimmed();
      remote->sendCommand(tmp + "\n");
      qSleep(100);
    }
  }
}

void SermanWindow::on_actionShortCuts_triggered() {
  QMessageBox msgBox;
  msgBox.setText(R"delim(
                 Arrow up/down for navigating in commando history.
                 Return key send the command.
                 Ctrl-d write all commands to console window.
                 Ctrl-r search in command history Ctrl-g to stop search .
                 Ctrl-f search in log view will use regexps c++ 11  style.
                     )delim");
  msgBox.setSizeGripEnabled(true);
  msgBox.exec();
}
