#ifndef BUTTON_TASK_H
#define BUTTON_TASK_H

#include "Events.h"

void sendToQueue(SystemEvent &event);
void buttonTask(void *pvParameters);

#endif