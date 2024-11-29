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
#include <cmath>

struct SpiRamAllocator {
  void* allocate(size_t size) {
    return heap_caps_malloc(size, MALLOC_CAP_SPIRAM);
  }

  void deallocate(void* pointer) {
    heap_caps_free(pointer);
  }

  void* reallocate(void* ptr, size_t new_size) {
    return heap_caps_realloc(ptr, new_size, MALLOC_CAP_SPIRAM);
  }
};


typedef struct
{
    /* data */
    int schedule_id;
    lv_obj_t *  ui_PanelScheduleItemContainer;
    lv_obj_t *  ui_PanelScheduleItem;
    lv_obj_t *  ui_LabelScheduleItem;
    lv_obj_t *  ui_PanelScheduleItemIngredientWaterQuantity;
    lv_obj_t *  ui_LabelScheduleItemWaterQuantity;
    lv_obj_t *  ui_LabelScheduleItemTimer;
    lv_obj_t *  ui_SwitchScheduleItem;
    lv_obj_t *  ui_LabelNameScheduleListItem;
} jsonScheduleItem;

extern jsonScheduleItem jsonScheduleItemList[5];

extern const char* web_server;
extern const char* ota_server;


extern SemaphoreHandle_t lvgl_mutex;

extern String jsonString;

extern int numberOfPage;
extern int numberOfElement;
extern int currentOfElementHeader;
extern int current_schedule_id;

extern uint16_t current_year;
extern uint16_t current_month;
extern uint16_t current_day;

#define PRINT   1
#define PRINTLN 2
#define PRINTF  3

#define DEBUG_MODE  1 // Enable it to print all message


void print(uint8_t print_mode,  const char* msg, ...);

