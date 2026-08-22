#include "Display.h"
#include <Wire.h>

OledDisplay::OledDisplay()
: oled(OLED_WIDTH, OLED_HEIGHT, &Wire, OLED_RESET){}

void OledDisplay::begin()
{
    oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS);

    oled.setTextColor(WHITE);
    oled.setTextSize(1);

    oled.clearDisplay();
    oled.display();
}

void OledDisplay::printMode(Mode mode)
{
    oled.setCursor(0,0);
    switch(mode)
    {
        case Mode::Home:
        oled.print("> MODE: HOME");
        break;

        case Mode::Night:
        oled.print("> MODE: NIGHT");
        break;

        case Mode::Away:
        oled.print("> MODE: AWAY");
        break;
    }
}

void OledDisplay::printTemperature(float temperature)
{
    oled.setCursor(0, 16);
    oled.print("> TEMP: ");
    oled.print(temperature);
    oled.print(" C");
}

void OledDisplay::printHumidity(float humidity)
{
    oled.setCursor(0, 32);
    oled.print("> HUM: ");
    oled.print(humidity);
    oled.print(" %");
}

void OledDisplay::printMotionState(bool motion, Mode mode)
{
    oled.setCursor(0, 48);
    switch(mode)
    {
        case Mode::Home:
        oled.print("> MOTION: isn`t tracked");
        break;

        case Mode::Night:
        if(!motion)
        {
            oled.print("> MOTION: NONE");
        }
        else if(motion)
        {
            oled.print(" NIGHT ACTIVITY");
        }
        break;

        case Mode::Away:
        oled.print("> MOTION: is tracked");
        break;

        case Mode::Trespassing:
        oled.print("MOTION DETECTED");
        break;
    }
}

void OledDisplay::updateScreen(DisplayData &data)
{
    oled.clearDisplay();

    printMode(data.currentMode);
    printTemperature(data.temperature);
    printHumidity(data.humidity);
    printMotionState(data.motion, data.currentMode);

    oled.display();
}

void OledDisplay::printTrespassingScreen()
{
    oled.clearDisplay();

    oled.setCursor(0, 0);
    oled.print("   ALERT   ");
    oled.setCursor(0, 16);
    oled.print("MOTION DETECTED");
    oled.setCursor(0, 32);
    oled.print("SENDING MESSAGE");

    oled.display();
}