#include "DisplayTask.h"
#include "Display.h"
#include "Queues.h"
#include "DisplayData.h"

OledDisplay display;
void displayTask(void *pvParameters)
{
    display.begin();
    DisplayData data;

    while(true)
    {
        if(xQueueReceive(displayQueue, &data, portMAX_DELAY) == pdTRUE)
        {
            if(data.currentMode == Mode::Trespassing)
            {
                display.printTrespassingScreen();
            }
            else
            {
                display.updateScreen(data);
            }
        }
    }
}