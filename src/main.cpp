#include <Arduino.h>
#include "EmonLib.h"
#include "storage.h"

EnergyMonitor emon1;

const int analogPin = 1;
const float calibration = 29;
const int network = 220;
const int sdPin;
void setup(){

  Serial.begin(9600);
  initializerSD(sdPin);
  emon1.current(analogPin, calibration);

}

void loop(){

  double irms = emon1.calcIrms(1480);
  double power = irms * network;
}

