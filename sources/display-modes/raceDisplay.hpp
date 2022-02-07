#ifndef DEF_RACEDISPLAY
#define DEF_RACEDISPLAY

#include <QApplication>
#include <QObject>
#include <QWidget>
#include "../elements/throttleBar.hpp"
#include "../elements/brakeBar.hpp"

class raceDisplay : public QWidget {
  Q_OBJECT
private:
  Game* m_selectedGame;
  throttleBar* throttle;

  //brakeBar* brake;

public:

  raceDisplay (Game* selectedGame) {
    m_selectedGame = selectedGame;
  };

  public slots:
    void initDisplay(void* manager) {
      throttle = new throttleBar(this, m_selectedGame, manager);
      throttle->move(100, 100);
      throttle->setValue(58);
      this->setStyleSheet("background-color: black;");
      this->show();
    };
};
#endif
