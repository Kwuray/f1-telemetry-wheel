#include <QApplication>
#include <QPushButton>
#include "display-modes/raceDisplay.hpp"
#include "feedThread.hpp"
#include <thread>
#include <iostream>
#include <chrono>
#include <QThread>
/*
void backgroundTask(QApplication* app, raceDisplay* currentScreen) {
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  int x = 0;
  while (true) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    currentScreen->updateData(&x);
    x = x + 1;
    if (x > 100) {
      x = 0;
    }
  }
}
*/
int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  raceDisplay screen;
  feedThread dataFeed(&screen);
  dataFeed.start();
  //std::thread dataFeed(backgroundTask, &app, &screen);
  //dataFeed.detach();
  app.exec();
  return 0;
}
