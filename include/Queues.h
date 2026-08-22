#ifndef QUEUES_H
#define QUEUES_H
#include <Arduino.h>

extern QueueHandle_t fsmQueue;
extern QueueHandle_t sensorDataQueue;
extern QueueHandle_t buzzerQueue;
extern QueueHandle_t displayQueue;
extern QueueHandle_t ledQueue;
extern QueueHandle_t telegramQueue;

void initQueues();

#endif