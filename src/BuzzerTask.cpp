#include "BuzzerTask.h"
#include "Buzzer.h"
#include "Config.h"
#include "BuzzerData.h"
#include "Queues.h"

Buzzer buzzer1(buzzerPin);

void buzzerTask(void *pvParameters)
{
    BuzzerCommands data;
    bool isSignaling = false;
    while(true)
    {
        if(xQueueReceive(buzzerQueue, &data, pdMS_TO_TICKS(10)) == pdTRUE)
        {
            if(data == BuzzerCommands::Sound)
            {
                isSignaling = true;
            }
            if(data == BuzzerCommands::Mute)
            {
                isSignaling = false;
                buzzer1.stopSound();
            }
        }
            
        if(isSignaling)
        {
            buzzer1.sound();
        }
        
        vTaskDelay(pdMS_TO_TICKS(1));
    }
}