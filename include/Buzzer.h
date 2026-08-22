#ifndef BUZZER_H
#define BUZZER_h
#include <Arduino.h>

class Buzzer
{
    private:
    uint8_t pin;
    unsigned long previousSound = 0;
    bool changeTone = false;

    public:
    Buzzer(uint8_t pin);

    void sound();
    void stopSound();
};

#endif