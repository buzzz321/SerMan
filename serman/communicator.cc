#include "communicator.h"
#include "sermanwindow.h"
#include <QHostAddress>
#include <QtNetwork>
#include <iostream>

Communicator::Communicator(QObject *parent) : QObject(parent) {
  QObject::connect(&client, QOverload<QAbstractSocket::SocketError>::of(
                                &QAbstractSocket::error),
                   this, &Communicator::displayError);

  QObject::connect(&client, &QIODevice::readyRead,
                   static_cast<const SermanWindow *>(parent),
                   &SermanWindow::gotRemoteData);
}

Communicator::~Communicator() {}

void Communicator::connect() {
  client.connectToHost(address, remotePort,
                       QIODevice::ReadWrite | QIODevice::Text);
}

void Communicator::connect(QString hostname, quint16 port) {
  client.connectToHost(QHostAddress(hostname), port,
                       QIODevice::ReadWrite | QIODevice::Text);
}

void Communicator::disconnect() { client.disconnectFromHost(); }

void Communicator::sendCommand(QString cmd) {
  client.write(cmd.toLatin1(), cmd.length());
  // client.waitForReadyRead(2000);

  // auto retval = client.readAll();
}

void Communicator::setAddress(QHostAddress address) {
  this->address = address;
  std::cout << address.toString().toStdString() << std::endl;
}
void Communicator::setPort(quint16 port) { this->remotePort = port; }

void Communicator::displayError(QAbstractSocket::SocketError socketError) {
  switch (socketError) {
  case QAbstractSocket::RemoteHostClosedError:
    std::cout << tr("The host disconnected unexpectedly.").toStdString();
    break;
  case QAbstractSocket::HostNotFoundError:
    std::cout << tr("The host was not found. Please check the host name and "
                    "port settings.")
                     .toStdString();
    break;
  case QAbstractSocket::ConnectionRefusedError:
    std::cout << tr("The connection was refused by the peer. "
                    "Make sure the fortune server is running, "
                    "and check that the host name and port "
                    "settings are correct.")
                     .toStdString();
    break;
  default:
    std::cout << tr("The following error occurred: %1.")
                     .arg(client.errorString())
                     .toStdString();
    break;
  }
}

QString Communicator::getRemoteData() {
  auto consoleText = client.readAll();
  std::cout << consoleText.toStdString();
  return consoleText;
}
