#include "ntc.h"

NTC::NTC (int pin){
    _pin = pin;
}

float NTC::readTemperature(){
    int adcValue = analogRead(_pin);
    float voltageValue = adcValue / 1023.0;
    float vcc = 3.3;
    float vout = voltageValue * vcc;
    float ntcResistance = (vcc * seriesResistor / vout) - seriesResistor;
    float temperatureK = 1.0 / ((1.0 / t0) + (1.0 / beta) * log(ntcResistance / r0));
    Serial.print("Temperatura actual: ");
    Serial.print(temperatureK - 273.15);
    Serial.println(" C");
    return temperatureK - 273.15;
}