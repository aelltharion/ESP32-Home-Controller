#include "WiFiTask.h"
#include "WiFiManager.h"
#include "Config.h"

WiFiManager wifi;

void WiFiTask(void *pvParameters)
{
    wifi.begin(ssid, password);

    while(true)
    {
        wifi.update();

        vTaskDelay(100);
    }
}