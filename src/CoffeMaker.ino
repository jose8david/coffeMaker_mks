#include "CoffeMaker.h"

const int buttonPin = 4; //D2-4
const int heaterRelayPin= 0 ; //D3-0
const int pumpRelayPin = 2; //D4-2
const int ntcPin = A0; //A0

CoffeeMaker mksCoffee (buttonPin, heaterRelayPin, pumpRelayPin, ntcPin);

void setup(){
  mksCoffee.start();
}

void loop(){
  mksCoffee.update();
}