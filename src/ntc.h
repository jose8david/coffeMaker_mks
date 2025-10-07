#ifndef NTC_H
#define NTC_H
#include "Arduino.h"

class NTC{

    public:
    NTC(int pin);
    float readTemperature();

    private:
    int _pin;
    const float beta = 3950.0;
    const float r0 = 100000.0; // 25 ºC
    const float t0 = 298.15;   // Kelvin
    const float seriesResistor = 100000.0;

};

#endif