#include "sermanwindow.h"
#include "ui_sermanwindow.h"
#include <QKeyEvent>
#include <iostream>

using namespace std;

SermanWindow::SermanWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      remote(new Communicator(this)) {
  ui->setupUi(this);
  ui->logEdit->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
  ui->logEdit->setVisible(true);
  ui->cmdLineEdit->installEventFilter(this);

  auto filesettings = settings.loadSettings();
  if (filesettings.hostName != "") {
    remote->setPort(filesettings.port);
    cout << "|" << filesettings.hostName.toStdString() << "|" << endl;
    QHostInfo::lookupHost(filesettings.hostName, this,
                          SLOT(on_newHostname(QHostInfo)));
  }
}

SermanWindow::~SermanWindow() {
  delete remote;
  delete ui;
}

void SermanWindow::on_sendButton_clicked() {
  commandHistory.addToHistory(ui->cmdLineEdit->text().toStdString());

  cout << ui->cmdLineEdit->text().toStdString() << endl;
  remote->sendCommand(ui->cmdLineEdit->text());

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
    remote->setAddress(addresses[0]);
  }
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
