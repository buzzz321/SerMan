#include "fileloader.h"
#include <QStandardPaths>
#include <QString>
#include <QStringList>
#include <fstream>
#include <iostream>
#include <string>

const QString FileLoader::fileName = ".serman";

FileLoader::FileLoader() {}

FileLoader::Settings FileLoader::loadSettings() {
  QString filename =
      QStandardPaths::locate(QStandardPaths::HomeLocation, fileName);
  std::ifstream myfile(filename.toStdString());
  FileLoader::Settings retVal;
  if (myfile.is_open()) {
    std::string line;

    while (std::getline(myfile, line)) {
      QString tmp(line.c_str());
      tmp.trimmed();

      QStringList keyValues =
          tmp.split(':', QString::SplitBehavior::SkipEmptyParts);

      if (keyValues.length() < 2) {
        continue;
      }
      if ("hostname" == keyValues[0]) {
        retVal.hostName = keyValues[1].trimmed();
      } else if ("port" == keyValues[0]) {
        bool ok;
        retVal.port = keyValues[1].toUShort(&ok);
      } else if ("prepend" == keyValues[0]) {
        retVal.prepend = keyValues[1].trimmed();
      } else {
        std::cout << "Unkown file values found, can't parse "
                  << keyValues[0].toStdString()
                  << "value = " << keyValues[1].toStdString() << std::endl;
      }

      std::cout << line << '\n';
    }
    myfile.close();
  }
  std::cout << "Hostname = " << retVal.hostName.toStdString()
            << " Port = " << retVal.port << std::endl;
  return retVal;
}
