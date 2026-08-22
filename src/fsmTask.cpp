#include "fsmTask.h"
#include "Queues.h"
#include "FsmMessage.h"
#include "SystemHomeController.h"
#include "BuzzerTask.h"
#include "SensorData.h"
#include "DisplayData.h"
#include "SensorsDataState.h"
#include "BuzzerData.h"
#include "TelegramData.h"


void changeMode(System& system, Mode nextMode)
{
    ledData(nextMode);
    if(system.currentMode == Mode::Away && nextMode == Mode::Trespassing)
    {
        BuzzerCommands data = BuzzerCommands::Sound;
        xQueueOverwrite(buzzerQueue, &data);

        TelegramMessage message;
        message.type = MessageType::Trespassing;
        xQueueOverwrite(telegramQueue, &message);
    }
    if(system.currentMode == Mode::Trespassing && nextMode == Mode::Home)
    {
        BuzzerCommands data = BuzzerCommands::Mute;
        xQueueOverwrite(buzzerQueue, &data);
    }
    system.currentMode = nextMode;
}

void ledData(Mode mode)
{
    Mode data;
    data = mode;
    xQueueOverwrite(ledQueue, &data);
}

TemperatureState checkTemperature(float temperature)
{
    if(temperature > 30)
    {
        return TemperatureState::High;
    }
    if(temperature < 15)
    {
        return TemperatureState::Low;
    }
    return TemperatureState::Normal;
}

HumidityState checkHumidity(float humidity)
{
    if(humidity > 65)
    {
        return HumidityState::High;
    }
    if(humidity < 35)
    {
        return HumidityState::Low;
    }
    return HumidityState::Normal;
}

void checkSensorData(System& system, FsmMessage& data)
{
    system.temperature = data.sensorData.temperature;
    system.humidity = data.sensorData.humidity;

    TemperatureState newTempState = checkTemperature(data.sensorData.temperature);
    HumidityState newHumState = checkHumidity(data.sensorData.humidity);

    if(newTempState != system.temperatureState)
    {
        system.temperatureState = newTempState;
        TelegramMessage message;
        message.type = MessageType::Temperature;
        message.tempState = newTempState;
        message.t = data.sensorData.temperature;
        xQueueOverwrite(telegramQueue, &message);
    }
    if(newHumState != system.humidityState)
    {
        system.humidityState = newHumState;
        TelegramMessage message;
        message.type = MessageType::Humidity;
        message.humState = newHumState;
        message.h = data.sensorData.humidity;
        xQueueOverwrite(telegramQueue, &message);
    }
}

void proccessEvent(System& system, SystemEvent event)
{
    switch(system.currentMode)
    {
        case Mode::Home:
        if(event == SystemEvent::SetToNight) {
            changeMode(system, Mode::Night);
        }
        if(event == SystemEvent::SetToAway) {
            changeMode(system, Mode::Away);
        }
        break;

        case Mode::Night:
        if(event == SystemEvent::SetToHome) {
            changeMode(system, Mode::Home);
        }
        if(event == SystemEvent::SetToAway) {
            changeMode(system, Mode::Away);
        }
        if(event == SystemEvent::MotionDetected) {
            system.motionState = true;
        }
        if(event == SystemEvent::MotionUndetected) {
            system.motionState = false;
        }
        break;

        case Mode::Away:
        if(event == SystemEvent::SetToHome) {
            changeMode(system, Mode::Home);
        }
        if(event == SystemEvent::SetToNight) {
            changeMode(system, Mode::Night);
        }
        if(event == SystemEvent::MotionDetected) {
            changeMode(system, Mode::Trespassing);
        }
        break;

        case Mode::Trespassing:
        if(event == SystemEvent::RemoveProtection || event == SystemEvent::SetToHome) {
            changeMode(system, Mode::Home);
        }
        break;
    }
}

void updateDisplay(System& system)
{
    DisplayData info;

    info.currentMode = system.currentMode;
    info.temperature = system.temperature;
    info.humidity = system.humidity;
    info.motion = system.motionState;

    xQueueOverwrite(displayQueue, &info);
}

void fsmTask(void *pvParameters)
{
    System system{};
    FsmMessage message;

    while(true)
    {
        if(xQueueReceive(fsmQueue, &message, portMAX_DELAY) == pdTRUE)
        {
            switch(message.type)
            {
                case FsmMessageType::Event:
                proccessEvent(system, message.event);
                break;

                case FsmMessageType::SensorData:
                checkSensorData(system, message);
                break;
            }
            updateDisplay(system);
        }
    }
}