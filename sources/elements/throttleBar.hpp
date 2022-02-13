#ifndef DEF_THROTTLEBAR
#define DEF_THROTTLEBAR

#include <QWidget>
#include <QProgressBar>
#include <QObject>
#include "../../headers/games/games.hpp"

#include "../../headers/games/F1-2020/packets-structures/carTelemetry.hpp"

class throttleBar : public QProgressBar {
  Q_OBJECT
  private:
    Game* m_selectedGame;


  public:
    throttleBar (QWidget* parent, Game* selectedGame, managerUnion* manager) : QProgressBar(parent) {
      m_selectedGame = selectedGame;
      this->setStyleSheet("QProgressBar::chunk { background-color: green } QProgressBar { text-align: center; border: 2px solid grey }");
      this->setOrientation(Qt::Vertical);
      this->setMinimum(0);
      this->setMaximum(100);
      this->setFixedSize(50, 300);
      switch (*m_selectedGame) {
        case Game::F12020:
          QObject::connect(manager->F12020_manager, SIGNAL(dataReady(uint8_t, void*)), this, SLOT(updateData(uint8_t, void*)));
          break;
        default:
          QObject::connect(manager->F12020_manager, SIGNAL(dataReady(uint8_t, void*)), this, SLOT(updateData(uint8_t, void*)));
          break;
      }

    };

  public slots:
    void updateData(uint8_t packetId, void* packet) {
      int playerIndex;
      //Récupération de la donnée différente selon le jeu...
      switch (*m_selectedGame) {
        case Game::F12020:
          if (packetId == 6) {
            playerIndex = static_cast<packetCarTelemetryData*>(packet)->m_header.m_playerCarIndex;
            printf("Signal émis ! Voici la valeur de throttle : %d\n", (int)(static_cast<packetCarTelemetryData*>(packet)->m_carTelemetryData[playerIndex].m_throttle * 100));
            setValue((int)(static_cast<packetCarTelemetryData*>(packet)->m_carTelemetryData[playerIndex].m_throttle * 100));
            break;
          } else {
            return;
          }

        default: break;
      }
    };

};
#endif
