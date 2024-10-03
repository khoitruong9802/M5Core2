#pragma once
#include <freertos/FreeRTOS.h>
#include <M5Unified.h>
#include <ArduinoOTA.h>
#include <HTTPClient.h>
#include <SD.h>
#include <SPIFFS.h>

extern const char* web_server;

extern SemaphoreHandle_t lvgl_mutex;
