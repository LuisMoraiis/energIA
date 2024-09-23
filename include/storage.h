#ifndef STORAGE_H
#define STORAGE_H

#include <Arduino.h>
#include <SD.h>
#include <SPI.h>
#include <Wire.h>

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

File createFile(){
    File myFile = SD.open("/data/dataCollected.csv", FILE_WRITE);
    if(myFile){
        myFile.println("HORA;CORRENTE;POTENCIA");
    }else{
        Serial.println("Erro ao criar arquivo");
    }
    return myFile;
}

void writeFile(File myFile, double current, double power){
    if(myFile){ //add time
        String data = String(current, 2) + ";" + String(power, 2);
        myFile.println(data);
    }else{
        Serial.println("Erro ao abrir arquivo.");
    }
}

void closeFile(File myFile){
    myFile.close();
}

#endif
