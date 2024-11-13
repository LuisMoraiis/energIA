#ifndef LCD_H
#define LCD_H

#include <LiquidCrystal.h>
#include <Arduino.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void initializerLcd(){
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Corr.(A): ");
    lcd.setCursor(0, 1);
    lcd.print("Pot.(W): ");
}

void printLcd(double current, double power){
    lcd.setCursor(10, 0);
    lcd.print(current, 1);
    lcd.setCursor(10, 1);
    lcd.print("     ");
    lcd.setCursor(10, 1);
    lcd.print(power, 1);
    Serial.print("Corrente: ");
    Serial.println(current);
    Serial.print("Potencia: ");
    Serial.println(power);
    Serial.println();
}

#endif