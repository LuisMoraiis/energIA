#include "storage.h"
#include "lcd.h"
#include "sct.h"


#define REDE 220.0
#define PINO_SCT 1
 
void setup(){
  Serial.begin(9600);   
  initializerLcd();
  emon1.current(PINO_SCT, 29);
} 
  
void loop(){
  double Irms = calc_irms();
  double power = calc_power(Irms, REDE);
  printLcd(Irms, power);
  delay(1000);
}

