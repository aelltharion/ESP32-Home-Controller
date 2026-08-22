#include "PIRSensor.h"

PIRSensor::PIRSensor(uint8_t pin)
: pin(pin){}

void PIRSensor::initSensor()
{
    pinMode(pin, INPUT);
}

void PIRSensor::monitor()
{
    bool currentState = digitalRead(pin);

    if(currentState != lastReading)
    {
        detected = true;
    }
    lastReading = currentState;
}

bool PIRSensor::isDetected()
{
    bool result = detected;
    detected = false;

    return result;
}