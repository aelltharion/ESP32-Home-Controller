#include "Queues.h"
#include "Events.h"
#include "SensorData.h"
#include "DisplayData.h"
#include "BuzzerData.h"
#include "FsmMessage.h"
#include "TelegramData.h"

QueueHandle_t fsmQueue;
QueueHandle_t sensorDataQueue;
QueueHandle_t buzzerQueue;
QueueHandle_t displayQueue;
QueueHandle_t ledQueue;
QueueHandle_t telegramQueue;

void initQueues()
{
    fsmQueue = xQueueCreate(10, sizeof(FsmMessage));
    sensorDataQueue = xQueueCreate(1, sizeof(SensorData));
    buzzerQueue = xQueueCreate(1, sizeof(BuzzerCommands));
    displayQueue = xQueueCreate(1, sizeof(DisplayData));
    ledQueue = xQueueCreate(1, sizeof(Mode));
    telegramQueue = xQueueCreate(1, sizeof(TelegramMessage));
}