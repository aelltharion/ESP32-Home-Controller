#ifndef BUTTON_H
#define BUTTON_H
#include <Arduino.h>

class Button{
    private:
    uint8_t pin;
    bool lastReading = HIGH;
    bool buttonState = HIGH;
    bool pressed = false;
    unsigned long debounceTime = 0;

    public:
    Button(uint8_t pin);

    void update();
    bool isPressed();
};

#endif