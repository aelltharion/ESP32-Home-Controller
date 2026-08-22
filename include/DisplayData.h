#ifndef DISPLAY_DATA_H
#define DISPLAY_DATA_H

#include "Events.h"

struct DisplayData
{
    Mode currentMode;
    float temperature;
    float humidity;
    bool motion;
};

#endif