#include "WiFiManager.h"
#include "Config.h"

void WiFiManager::begin(const char* ssid, const char* password)
{
    this->ssid = ssid;
    this->password = password;
    WiFi.mode(WIFI_STA);
    attemptConnection();
}

void WiFiManager::attemptConnection()
{
    WiFi.begin(ssid, password);
}

void WiFiManager::update()
{
    wl_status_t currentStatus = WiFi.status();

    if(currentStatus != previousStatus)
    {
        if(currentStatus == WL_CONNECTED)
        {
            connected = true;
        }
        previousStatus = currentStatus;
    }

    if(currentStatus != WL_CONNECTED)
    {
        connected = false;
        if(millis() - previousRecconectMillis > reconnectInterval)
        {
            previousRecconectMillis = millis();
            attemptConnection();
        }
    }
}

bool WiFiManager::isConnected()
{
    return connected;
}