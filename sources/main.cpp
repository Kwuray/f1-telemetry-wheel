#include <QApplication>
#include "display-modes/timeAttack.hpp"
#include "feedThread.hpp"
#include "../headers/games/games.hpp"
#include <thread>
#include <chrono>
#include <QThread>

int main(int argc, char *argv[]) {
  //Sélection du jeu/format des paquets
  //Rendre cette variable publique ???
  Game selectedGame = Game::F12020;

  //Création de l'application
  QApplication app(argc, argv);
  raceDisplay screen(&selectedGame);
  //Création Thread qui gèrera les paquets
  dataListenerThread dataFeed(&selectedGame, &screen);
  dataFeed.start();
  app.exec();
  return 0;
}
