#include "MotionSensorTask.h"
#include "PIRSensor.h"
#include "Config.h"
#include "Events.h"
#include "Queues.h"
#include "FsmMessage.h"

PIRSensor sensor(motionSensorPin);

void initAllSensors()
{
    sensor.initSensor();
}

void sendToQueue(SystemEvent event)
{
    FsmMessage message;
    message.type = FsmMessageType::Event;
    message.event = event;
    xQueueSend(fsmQueue, &message, portMAX_DELAY);
}

bool previousState = false;
void motionSensorTask(void *pvParameters)
{
    while(true)
    {
        sensor.monitor();

        bool currentState = sensor.isDetected();

        if(currentState != previousState)
        {
            if(currentState)
            {
                sendToQueue(SystemEvent::MotionDetected);
            } 
            else 
            {
                sendToQueue(SystemEvent::MotionUndetected);
            }
            previousState = currentState;
        }
        vTaskDelay(pdMS_TO_TICKS(20));
    }
}