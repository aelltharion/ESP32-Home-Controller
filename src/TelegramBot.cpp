#include "TelegramBot.h"
#include "Config.h"

void TelegramBot::begin(const char* token, const char* chatId)
{
    this->chatId = chatId;
    url = "https://api.telegram.org/bot";
    url += token;
    url += "/sendMessage";
}

String TelegramBot::createBody(const TelegramMessage& data)
{
    String body;

    body += "{";
    body += "\"chat_id\":\"";
    body += chatId;
    body += "\",";
    body += "\"text\":\"";

    switch(data.type)
    {
        case MessageType::Temperature:
        switch(data.tempState)
        {
            case TemperatureState::High:
            body += highTemperature;
            body += data.t;
            break;

            case TemperatureState::Low:
            body += lowTemperature;
            body += data.t;
            break;
        }
        break;

        case MessageType::Humidity:
        switch(data.humState)
        {
            case HumidityState::High:
            body += highHumidity;
            body += data.h;
            break;

            case HumidityState::Low:
            body += lowHumidity;
            body += data.h;
            break;
        }
        break;

        case MessageType::Trespassing:
        body += trespassing;
        break;
    }
    body += "\"}";

    return body;
}

void TelegramBot::sendMessage(const TelegramMessage& data)
{
    String body = createBody(data);
    network.post(url.c_str(), contentType, body.c_str());
}