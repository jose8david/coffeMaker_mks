#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
public:
    enum State {
        IDLE,
        PRESSED,
        HELD,
        RELEASED
    };

    Button(int pin, unsigned long debounceTime = 50, bool pull = false);

    void update();
    bool isPressed();   // Evento en flanco de bajada
    bool isHeld();      // Mientras se mantiene pulsado
    bool isReleased();  // Evento en flanco de subida
    State getState() const;

private:
    int _pin;
    unsigned long _debounceTime;
    bool _pull;
    State _state;

    unsigned long _lastDebounceTime;
    bool _lastStableReading; // último estado estable
    bool _currentReading;    // lectura actual cruda

    bool _pressedEvent;
    bool _releasedEvent;
};

#endif