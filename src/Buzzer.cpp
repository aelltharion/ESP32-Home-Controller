#include "Buzzer.h"
#include "Config.h"

Buzzer::Buzzer(uint8_t pin)
: pin(pin)
{
    pinMode(pin, OUTPUT);
}

void Buzzer::sound()
{
    if((millis() - previousSound > buzzerNoteDelay) && changeTone == false)
    {
        previousSound = millis();
        tone(pin, 700);
        changeTone = true;
    }
    if((millis() - previousSound > buzzerNoteDelay) && changeTone == true)
    {
        previousSound = millis();
        tone(pin, 500);
        changeTone = false;
    }
}

void Buzzer::stopSound()
{
    noTone(pin);
}