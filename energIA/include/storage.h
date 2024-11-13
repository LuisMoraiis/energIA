#ifndef STORAGE_H
#define STORAGE_H

#include <Arduino.h>
#include <SD.h>
#include <SPI.h>
#include <Wire.h>

File myFile;

void initializerSD(int sdPin){
    if(!SD.begin(sdPin)){
        Serial.println("Falha ao inicializar modulo SD!");
    }else{
        Serial.println("Modulo SD inicializado com sucesso.");
    }
    
    if(SD.mkdir("/DATA")){
        Serial.println("Diretorio criado com sucesso");
    }else{
        Serial.println("Falha ao criar diretorio.");
    }
}

void createFile(){
    myFile = SD.open("/DATA/dtCol.csv", FILE_WRITE);
    if(myFile){
        Serial.println("Arquivo criado com sucesso.");
        myFile.println("CORRENTE;POTENCIA");
        myFile.close();
    }else{
        Serial.println("Erro ao criar arquivo");
    }
}

void writeFile(double current, double power){
    myFile = SD.open("/DATA/dtcol.csv", FILE_WRITE);
    if(myFile){ //add time
        String data = String(current, 2) + ";" + String(power, 2);
        myFile.println(data);
        myFile.close();
    }else{
        Serial.println("Erro ao abrir arquivo.");
    }
}

#endif
