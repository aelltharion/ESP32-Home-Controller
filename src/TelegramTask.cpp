#include "TelegramTask.h"
#include "TelegramBot.h"
#include "TelegramData.h"
#include "Config.h"
#include "Queues.h"

TelegramBot telegram;

void telegramTask(void *pvParameters)
{
    TelegramMessage data;
    telegram.begin(telegramToken, telegramChatId);

    while(true)
    {
        if(xQueueReceive(telegramQueue, &data, portMAX_DELAY) == pdPASS)
        {
            telegram.sendMessage(data);
        }
    }
}