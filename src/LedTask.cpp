#include "LedTask.h"
#include "Led.h"
#include "Config.h"
#include "Queues.h"
#include "Events.h"

Led greenLed(greenLedPin);
Led blueLed(blueLedPin);
Led redLed(redLedPin);

void ledTask(void *pvParameters)
{
    Mode data;

    greenLed.init();
    blueLed.init();
    redLed.init();

    greenLed.modeStatic();
    blueLed.off();
    redLed.off();
    
    bool isBlinking = false;

    while(true)
    {
        if(xQueueReceive(ledQueue, &data, pdMS_TO_TICKS(10)) == pdPASS)
        {
            if(data != Mode::Trespassing)
            {
                isBlinking = false;
            }
            switch(data)
            {
                case Mode::Home:
                greenLed.modeStatic();
                blueLed.off();
                redLed.off();
                break;

                case Mode::Night:
                greenLed.off();
                blueLed.modeStatic();
                redLed.off();
                break;

                case Mode::Away:
                greenLed.off();
                blueLed.modeStatic();
                redLed.modeStatic();
                break;

                case Mode::Trespassing:
                isBlinking = true;
                break;
            }
        }

        if(isBlinking)
        {
            greenLed.off();
            blueLed.off();
            redLed.modeBlink();
        }
        vTaskDelay(pdMS_TO_TICKS(1));
    }
}