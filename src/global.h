#pragma once
#include <freertos/FreeRTOS.h>
#include <M5Unified.h>
#include <ArduinoOTA.h>
#include <HTTPClient.h>
#include <SD.h>
#include <SPIFFS.h>
#include <Arduino.h>
#include <stdarg.h>
#include <lvgl.h>
#include <ArduinoJson.h>

extern const char* web_server;

extern SemaphoreHandle_t lvgl_mutex;

extern JsonArray jsonArray;

static int current_schedule_id = -1;

#define PRINT   1
#define PRINTLN 2
#define PRINTF  3

#define DEBUG_MODE  1 // Enable it to print all message


void print(uint8_t print_mode,  const char* msg, ...);

