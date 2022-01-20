#ifndef DEF_FEEDTHREAD
#define DEF_FEEDTHREAD

#include <QThread>
#include <chrono>
#include <thread>
#include "packetManager.hpp"

class feedThread : public QThread {
public:
  int x = 0;
  feedThread(raceDisplay* screenInput) {
    currentScreen = screenInput;
  };


private:
  raceDisplay* currentScreen;

protected:
  void run() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    packetManager manager(currentScreen, &x);
    while (true) {
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
      manager.usingData();
      x = x + 1;
      if (x > 100) {
        x = 0;
      }
    }
  }

};
#endif
