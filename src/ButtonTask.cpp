#include "ButtonTask.h"
#include "Button.h"
#include "Config.h"
#include "Events.h"
#include "Queues.h"
#include "FsmMessage.h"

Button buttonHome(buttonPinHome);
Button buttonNight(buttonPinNight);
Button buttonAway(buttonPinAway);

void sendToQueue(SystemEvent &event)
{
    FsmMessage message;
    message.type = FsmMessageType::Event;
    message.event = event;
    xQueueSend(fsmQueue, &message, portMAX_DELAY);
}

void buttonTask(void *pvParameters)
{
    while(true)
    {
        buttonHome.update();
        buttonNight.update();
        buttonAway.update();

        if(buttonHome.isPressed())
        {
            SystemEvent event = SystemEvent::SetToHome;
            sendToQueue(event);
        }
        if(buttonNight.isPressed())
        {
            SystemEvent event = SystemEvent::SetToNight;
            sendToQueue(event);
        }
        if(buttonAway.isPressed())
        {
            SystemEvent event = SystemEvent::SetToAway;
            sendToQueue(event);
        }

        vTaskDelay(pdMS_TO_TICKS(20));
    }
}