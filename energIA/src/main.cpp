#include "storage.h"
#include "lcd.h"
#include "sct.h"

#define REDE 220.0
#define PIN_SCT 1
#define PIN_SD 4


void setup(){
  Serial.begin(9600);
  SPI.begin();
  initializerSD(PIN_SD);
  createFile();
  initializerLcd();
  emon1.current(PIN_SCT, 29);
} 

void loop(){
  double Irms = calc_irms();
  double power = calc_power(Irms, REDE);
  writeFile(Irms, power);
  printLcd(Irms, power);
  delay(1000);
}

