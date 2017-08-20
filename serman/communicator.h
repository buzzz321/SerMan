#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <QDataStream>
#include <QObject>
#include <QTcpSocket>

class Communicator : public QObject {
  Q_OBJECT
public:
  explicit Communicator(QObject *parent = nullptr);
  virtual ~Communicator();
  void connect(QString hostname, quint16 port);
  void sendCommand(QString cmd);
  void disconnect();
  void displayError(QAbstractSocket::SocketError socketError);
  QString getRemoteData();

signals:
  void remoteData(QString data);
public slots:

private slots:

private:
  QTcpSocket client;
};

#endif // COMMUNICATOR_H
