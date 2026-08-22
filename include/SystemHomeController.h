#ifndef SYSTEM_HOME_CONTROLLER_H
#define SYSTEM_HOME_CONTROLLER_H

#include "Events.h"
#include "SensorsDataState.h"

struct System
{
    Mode currentMode = Mode::Home;
    SystemEvent event = SystemEvent::None;
    bool motionState = false;

    float temperature = 0;
    float humidity = 0;

    TemperatureState temperatureState = TemperatureState::Normal;
    HumidityState humidityState = HumidityState::Normal;
};

#endif