#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <QDataStream>
#include <QHostAddress>
#include <QObject>
#include <QTcpSocket>

class Communicator : public QObject {
  Q_OBJECT
public:
  explicit Communicator(QObject *parent = nullptr);
  virtual ~Communicator();
  void connect(QString hostname, quint16 port);
  void connect();
  void sendCommand(QString cmd);
  void disconnect();
  void displayError(QAbstractSocket::SocketError socketError);
  QString getRemoteData();
  void setAddress(QHostAddress address);
  void setPort(quint16 port);
  quint16 getPort() { return remotePort; }

signals:
  void remoteData(QString data);
public slots:

private slots:

private:
  QTcpSocket client;
  QHostAddress address;
  quint16 remotePort;
};

#endif // COMMUNICATOR_H
