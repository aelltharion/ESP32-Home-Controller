#ifndef CONFIG_H
#define CONFIG_H
#include <Arduino.h>

// GPIO
constexpr uint8_t buttonPinHome = 15;
constexpr uint8_t buttonPinNight = 16;
constexpr uint8_t buttonPinAway = 5;
constexpr uint8_t sensorPin = 32;
constexpr uint8_t motionSensorPin = 13;
constexpr uint8_t buzzerPin = 27;
constexpr uint8_t greenLedPin = 26;
constexpr uint8_t blueLedPin = 25;
constexpr uint8_t redLedPin = 33;

// TIME
constexpr unsigned long debounceDelay = 50;
constexpr unsigned long blinkDelay = 200;
constexpr unsigned long reconnectInterval = 5000;

// SOUND
constexpr unsigned long buzzerNoteDelay = 300;
constexpr unsigned long signalingDuration = 900000;

// OLED DISPLAY SSD1306
constexpr uint8_t OLED_WIDTH = 128;
constexpr uint8_t OLED_HEIGHT = 64;
constexpr int8_t OLED_RESET = -1;
constexpr uint8_t OLED_ADDRESS = 0x3C;

// WiFi
extern const char* ssid;
extern const char* password;

// Telegram
extern const char* telegramToken;
extern const char* telegramChatId;
constexpr const char* highTemperature = "The temperature exceeded the normal range: ";
constexpr const char* lowTemperature = "Temperature below normal: ";
constexpr const char* highHumidity = "Humidity is exceeded the normal range: ";
constexpr const char* lowHumidity = "Humidity is below normal: ";
constexpr const char* trespassing = "Motion detected!";

#endif