#include "Led.h"
#include "Config.h"

Led::Led(uint8_t pin)
: pin(pin){}

void Led::init()
{
    pinMode(pin, OUTPUT);
}

void Led::modeStatic()
{
    digitalWrite(pin, HIGH);
}

void Led::modeBlink()
{
    if(millis() - previousBlink > blinkDelay)
    {
        previousBlink = millis();
        ledState = !ledState;
        digitalWrite(pin, ledState);
    }
}

void Led::off()
{
    digitalWrite(pin, LOW);
}