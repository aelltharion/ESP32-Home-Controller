#ifndef FSM_MESSAGE_H
#define FSM_MESSAGE_H

#include "Events.h"
#include "SensorData.h"

enum class FsmMessageType 
{
    Event,
    SensorData
};

struct FsmMessage
{
    FsmMessageType type;

    SystemEvent event;
    SensorData sensorData;
};

#endif