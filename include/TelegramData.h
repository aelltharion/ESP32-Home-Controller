#ifndef TELEGRAM_DATA_H
#define TELEGRAM_DATA_H

#include "SensorsDataState.h"

enum class MessageType
{
    Temperature,
    Humidity,
    Trespassing
};

struct TelegramMessage
{
    MessageType type;

    TemperatureState tempState;
    HumidityState humState;

    float h;
    float t;
};

#endif