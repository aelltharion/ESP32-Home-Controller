#include "DHT22.h"
#include <DHT.h>

Sensor::Sensor(uint8_t pin)
:pin(pin), dht(pin, DHT22){}

void Sensor::begin()
{
    dht.begin();
}

void Sensor::update()
{
    humidity = dht.readHumidity();
    temperature = dht.readTemperature();
}

float Sensor::valueHumidity()
{
    return humidity;
}

float Sensor::valueTemperature()
{
    return temperature;
}