#ifndef DHT22_H
#define DHT22_H
#include <Arduino.h>
#include <DHT.h>

class Sensor{
    private:
    uint8_t pin;
    DHT dht;
    float humidity = 0.0;
    float temperature = 0.0;

    public:
    Sensor(uint8_t pin);

    void begin();
    void update();
    float valueHumidity();
    float valueTemperature();
};

#endif