#ifndef FSM_TASK_H
#define FSM_TASK_H

#include "SystemHomeController.h"
#include "SensorsDataState.h"
#include "SensorData.h"
#include "Events.h"

void changeMode(System& system, Mode nextMode);
TemperatureState checkTemperature(float temperature);
HumidityState checkHumidity(float humidity);
void ledData(Mode mode);
void checkSensorData(System& system, SensorData& data);
void proccessEvent(System& system, SystemEvent event);
void updateDisplay(System& system);
void fsmTask(void *pvParameters);

#endif