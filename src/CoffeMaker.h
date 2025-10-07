#ifndef COFFEEMAKER_H
#define COFFEEMAKER_H

#include "relay.h"
#include "button.h"
#include "ntc.h"

class CoffeeMaker {
    public:

        CoffeeMaker(int buttonPin, int heaterRelayPin, int pumpRelayPin, int ntcPin);

        void start();
        void update();
    
    private:
        Button button;
        Relay heaterRelay;
        Relay pumpRelay;
        NTC tempSensor;

        bool heating = false;
        bool makingCoffeeStatus = false;
        unsigned long lastActionTime = 0;
        unsigned long makingCoffeeTime = 0;

        void heaterOn ();
        void heaterOff();
        void makingCoffee();
        void stopMakingCoffee();
        bool isHot();
        void offTime();

};

#endif