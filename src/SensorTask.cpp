#include "SensorTask.h"
#include "DHT22.h"
#include "Config.h"
#include "FsmMessage.h"
#include "Queues.h"

Sensor sensorDHT22(sensorPin);

void sensorTask(void *pvParameters)
{
    sensorDHT22.begin();
    
    while(true)
    {
        sensorDHT22.update();
        float h = sensorDHT22.valueHumidity();
        float t = sensorDHT22.valueTemperature();

        FsmMessage message;
        message.type = FsmMessageType::SensorData;
        message.sensorData.temperature = t;
        message.sensorData.humidity = h;
        xQueueSend(fsmQueue, &message, portMAX_DELAY);

        vTaskDelay(pdMS_TO_TICKS(3000));
    }
}