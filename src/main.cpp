#include <Arduino.h>
#include "Queues.h"
#include "ButtonTask.h"
#include "SensorTask.h"
#include "MotionSensorTask.h"
#include "fsmTask.h"
#include "DisplayTask.h"
#include "BuzzerTask.h"
#include "LedTask.h"
#include "WiFiTask.h"
#include "TelegramTask.h"


void setup() {
  Serial.begin(115200);
  initQueues();
  initAllSensors();

  xTaskCreatePinnedToCore(buttonTask, "buttonTask", 4096, NULL, 1, NULL, 1);
  xTaskCreatePinnedToCore(sensorTask, "sensorTask", 4096, NULL, 1, NULL, 1);
  xTaskCreatePinnedToCore(motionSensorTask, "motionSensorTask", 4096, NULL, 2, NULL, 1);
  xTaskCreatePinnedToCore(fsmTask, "fsmTask", 4096, NULL, 3, NULL, 0);
  xTaskCreatePinnedToCore(displayTask, "displayTask", 4096, NULL, 2, NULL, 0);
  xTaskCreatePinnedToCore(buzzerTask, "buzzerTask", 2048, NULL, 1, NULL, 1);
  xTaskCreatePinnedToCore(ledTask, "ledTask", 2048, NULL, 1, NULL, 1);
  xTaskCreatePinnedToCore(WiFiTask, "WiFiTask", 4096, NULL, 1, NULL, 1);
  xTaskCreatePinnedToCore(telegramTask, "telegramTask", 4096, NULL, 2, NULL, 0);
}

void loop() {
  vTaskDelay(portMAX_DELAY);
}

