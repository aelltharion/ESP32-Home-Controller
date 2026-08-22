#ifndef TELEGRAM_BOT_H
#define TELEGRAM_BOT_H
#include <Arduino.h>
#include "TelegramData.h" 
#include "NetworkClient.h"

class TelegramBot{
    private:
    String chatId;
    String url;
    const char* contentType = "application/json";
    NetworkClient network;

    public:
    void begin(const char* token, const char* chatId);
    void sendMessage(const TelegramMessage& data);
    String createBody(const TelegramMessage& data);
};

#endif