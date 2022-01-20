#ifndef DEF_GETDATA
#define DEF_GETDATA
#include "display-modes/raceDisplay.hpp"
#include <QObject>

class packetManager : public QObject {
Q_OBJECT

public:
  int* throttleValue;
  raceDisplay* currentScreen;

  packetManager (raceDisplay* screenInput, int* val) {
    throttleValue = val;
    currentScreen = screenInput;
    QObject::connect(this, SIGNAL(resultReady()), currentScreen, SLOT(updateData(throttleValue)));
  }

public slots:
  void usingData() {
    emit resultReady();
  }

signals:
  void resultReady();

};

#endif
