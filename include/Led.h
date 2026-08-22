#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led
{
    private:
    uint8_t pin;
    unsigned long previousBlink = 0;
    bool ledState = false;

    public:
    Led(uint8_t pin);

    void init();
    void modeStatic();
    void modeBlink();
    void off();
};

#endif