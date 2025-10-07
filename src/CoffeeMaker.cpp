#include "CoffeMaker.h"
#include "Arduino.h"

CoffeeMaker::CoffeeMaker(int buttonPin, int heaterRelayPin, int pumpRelayPin, int ntcPin)
    :button (buttonPin),
    heaterRelay (heaterRelayPin),
    pumpRelay(pumpRelayPin), 
    tempSensor(ntcPin){}

void CoffeeMaker::start(){
    Serial.begin(9600);
    Serial.println("Iniciando el sistema...");
    heaterOn();
    lastActionTime = millis();
}

void CoffeeMaker::heaterOn(){
    heaterRelay.activate();
    heating = true;
    Serial.println("Calderín encendido");
}

void CoffeeMaker::update(){
  button.update(); 
    if(button.isPressed()){
        if(makingCoffeeStatus){
            Serial.println("Botón pulsado. Parada de emergencia");
            stopMakingCoffee();
        } else {
            Serial.println("Botón pulsado: Comprobando la temperatura para hacer un café");
            if(heating){
                if(isHot()){
                    makingCoffee();
                } else {
                    Serial.println("El agua todavía no está caliente. Espera un poco");
                }
            } else {
                Serial.println("Encendiendo la máquina");
                heaterOn();
            }
        }
        lastActionTime = millis();
    }

    if(makingCoffeeStatus && (millis() - makingCoffeeTime) > 20000){
        Serial.println("Tiempo de preparación agotado. Parando la máquina");
        stopMakingCoffee();
    }

    offTime();

}

void CoffeeMaker::makingCoffee(){
    if(!isHot()){
        Serial.println("No puedo preparar el café, el agua no está caliente");
        return;
    }
    pumpRelay.activate();
    makingCoffeeStatus = true;
    makingCoffeeTime = millis();
    Serial.println("Iniciando la preparación del café (20 segundos)");

}

void CoffeeMaker::stopMakingCoffee(){
    pumpRelay.deactivate();
    makingCoffeeStatus = false;
    Serial.println("Se ha detenido la preparación del café");
}

bool CoffeeMaker::isHot(){
    float temp = tempSensor.readTemperature();
    if(temp >= 60.0){
        return true;
    }
        return false;

}

void CoffeeMaker::offTime(){
    if(!makingCoffeeStatus && heating){
        if((millis() - lastActionTime) > 120000){
            Serial.println("Inactividad de la cafetera");
            heaterOff();
        }
    }
}

void CoffeeMaker::heaterOff(){
    heating = false;
    heaterRelay.deactivate();
    stopMakingCoffee();
    Serial.println("Calentador apagado. Cafetera inactiva");
}