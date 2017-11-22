#ifndef FILELOADER_H
#define FILELOADER_H
#include <QString>

class FileLoader {
public:
  struct Settings {
    QString hostName;
    QString prepend;
    quint16 port;
  };

  FileLoader();
  Settings loadSettings();
  static const QString fileName;
};

#endif // FILELOADER_H
