#ifndef FILELOADER_H
#define FILELOADER_H
#include <QString>

class FileLoader {
public:
  struct Settings {
    QString hostName;
    quint16 port;
  };

  FileLoader();
  Settings loadSettings();
};

#endif // FILELOADER_H
