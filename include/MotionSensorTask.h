#ifndef MOTION_SENSOR_TASK
#define MOTION_SENSOR_TASK

#include "Events.h"

void initAllSensors();
void sendToQueue(SystemEvent event);
void motionSensorTask(void *pvParameters);

#endif