#ifndef STORAGE_H
#define STORAGE_H

#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

void initializerSD(int sdPin){
    if(!SD.begin(sdPin)){
        Serial.println("Falha ao inicializar modulo SD!");
    }
    Serial.println("Modulo SD inicializado com sucesso.");

    if(SD.mkdir("/data")){
        Serial.println("Diretorio criado com sucesso");
    }else{
        Serial.println("Falha ao criar diretorio.");
    }
}

#endif
