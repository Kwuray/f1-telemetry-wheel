#ifndef DEF_FEEDTHREAD
#define DEF_FEEDTHREAD

#include <QThread>
#include <chrono>
#include <thread>

class feedThread : public QThread {
  Q_OBJECT
public:
  int x = 0;
  feedThread(raceDisplay* screenInput) : QThread() {
    currentScreen = screenInput;
    QObject::connect(this, SIGNAL(receiveData()), currentScreen, SLOT(updateData(&x)));
  };
public slots:
  void getData() {
  }
signals:
  void receiveData();

private:
  raceDisplay* currentScreen;
  QApplication* currentApp;

protected:
  void run() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    while (true) {
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
      emit receiveData();
      x = x + 1;
      if (x > 100) {
        x = 0;
      }
    }
  }

};
#endif
