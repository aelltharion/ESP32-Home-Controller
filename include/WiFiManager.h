#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include "WiFi.h"

class WiFiManager
{
    private:
    const char* ssid;
    const char* password;
    wl_status_t previousStatus = WL_IDLE_STATUS;
    unsigned long previousRecconectMillis = 0;
    bool connected = false;

    public:
    void begin(const char* ssid, const char* password);
    void update();
    void attemptConnection();
    bool isConnected();
};

#endif