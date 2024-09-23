#ifndef SCT_H
#define SCT_H

#include "EmonLib.h"


EnergyMonitor emon1;
//Calcula a corrente, Irms é a corrente e o Irms*rede é a potencia
double calc_irms(){
    double Irms = emon1.calcIrms(1480);
    return Irms;
}
//calcula a potencia
double calc_power(double Irms, float rede){
    double pot = (Irms * rede);
    return pot;
}

#endif