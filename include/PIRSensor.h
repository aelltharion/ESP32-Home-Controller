#ifndef PIR_SENSOR_H
#define PIR_SENSOR_H
#include <Arduino.h>

class PIRSensor{
    private:
    uint8_t pin;
    bool lastReading = LOW;
    bool detected = false;

    public:
    PIRSensor(uint8_t pin);

    void initSensor();
    void monitor();
    bool isDetected();
};

#endif