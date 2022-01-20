#include <QApplication>
#include <QPushButton>
#include "display-modes/raceDisplay.hpp"
#include "feedThread.hpp"
#include <thread>
#include <chrono>
#include <QThread>

void backgroundTask(QApplication* app, raceDisplay* currentScreen) {
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  int x = 0;
  while (true) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    currentScreen->updateData(&x);
    QEvent* ptr;
    ptr = new QEvent(QEvent::UpdateRequest);

    app->postEvent(currentScreen, ptr);
    x = x + 1;
    if (x > 100) {
      x = 0;
    }
  }
}

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  raceDisplay screen;
  feedThread dataFeed(&screen);
  dataFeed.start();
  app.exec();
  return 0;
}
