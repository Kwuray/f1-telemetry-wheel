#ifndef DEF_RACEDISPLAY
#define DEF_RACEDISPLAY

#include <QApplication>
#include <QWidget>
#include "../elements/throttleBar.hpp"
#include "../elements/brakeBar.hpp"

class raceDisplay : public QWidget {
private:
  //brakeBar* brake;

public:
  throttleBar* throttle;
public slots:
  void updateData(int* x) {
    throttle->setValue(*x);
    throttle->update();
  };
  raceDisplay () {
    this->setStyleSheet("background-color: black;");
    throttle = new throttleBar(this);
    //brake = new brakeBar(this);
    throttle->move(100, 100);
    this->show();
  };
};
#endif
