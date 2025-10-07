#include "button.h"

Button::Button(int pin, unsigned long debounceTime, bool pull) {
    _pin = pin;
    _debounceTime = debounceTime;
    _pull = pull;
    _state = IDLE;

    _lastDebounceTime = 0;
    _lastStableReading = HIGH;   // no pulsado
    _currentReading = HIGH;

    _pressedEvent = false;
    _releasedEvent = false;

    if (_pull) {
        pinMode(_pin, INPUT_PULLUP);
    } else {
        pinMode(_pin, INPUT);
    }

    Serial.println("Construido el botón");
}

// Actualización del estado (llamar en loop)
void Button::update() {
    unsigned long currentTime = millis();
    bool rawReading = digitalRead(_pin);

    if (_pull) {
        rawReading = !rawReading; // invertir lógica si pull-up
    }

    // Debounce
    if (rawReading != _currentReading) {
        _lastDebounceTime = currentTime;
        _currentReading = rawReading;
    }

    if ((currentTime - _lastDebounceTime) >= _debounceTime) {
        // Solo si cambió de verdad
        if (_lastStableReading != _currentReading) {
            _lastStableReading = _currentReading;

            if (_lastStableReading == LOW) {
                _state = PRESSED;
                _pressedEvent = true;
            } else {
                _state = RELEASED;
                _releasedEvent = true;
            }
        } else {
            // Mantener estado
            if (_lastStableReading == LOW) {
                _state = HELD;
            } else {
                _state = IDLE;
            }
        }
    }
}

// Devuelve true solo una vez cuando se pulsa
bool Button::isPressed() {
    if (_pressedEvent) {
        _pressedEvent = false;
        return true;
    }
    return false;
}

// Devuelve true mientras esté pulsado
bool Button::isHeld() {
    return (_state == HELD || _state == PRESSED);
}

// Devuelve true solo una vez cuando se suelta
bool Button::isReleased() {
    if (_releasedEvent) {
        _releasedEvent = false;
        return true;
    }
    return false;
}

Button::State Button::getState() const {
    return _state;
}
