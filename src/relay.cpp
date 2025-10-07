#include "relay.h"

Relay::Relay(int pin){
    _pin = pin;
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

void Relay::activate(){
    digitalWrite(_pin, HIGH); // Relé normalmente cerrado
    Serial.println("Relé activado");
}

void Relay::deactivate(){
    digitalWrite(_pin, LOW); 
    Serial.println("Relé apagado");
}