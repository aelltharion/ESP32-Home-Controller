#ifndef DISPLAY_H
#define DISPLAY_H

#include "Adafruit_SSD1306.h"
#include "DisplayData.h"
#include "Config.h"

class OledDisplay
{
    private:
    Adafruit_SSD1306 oled;

    public:
    OledDisplay();

    void begin();

    void printMode(Mode mode);
    void printTemperature(float temperature);
    void printHumidity(float humidity);
    void printMotionState(bool motionState, Mode mode);
    void updateScreen(DisplayData &data);
    void printTrespassingScreen();

};

#endif