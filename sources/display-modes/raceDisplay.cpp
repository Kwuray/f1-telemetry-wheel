#include "raceDisplay.hpp"
using namespace std;

void raceDisplay::updateData(int throttleValue) {
  raceDisplay::throttle->setValue(throttleValue);
  return;
}
