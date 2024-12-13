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
#include <TimeProfiler.h>
#include "gui/porting/lvgl_port.h"
#include <Preferences.h>
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
    int current_page;
    lv_obj_t *  ui_PanelScheduleItemContainer;
    lv_obj_t *  ui_PanelScheduleItem;
    lv_obj_t *  ui_LabelScheduleItem;
    lv_obj_t *  ui_PanelScheduleItemIngredientPriority;
    lv_obj_t *  ui_LabelScheduleItemPriority;
    lv_obj_t *  ui_LabelScheduleItemTimer;
    lv_obj_t *  ui_SwitchScheduleItem;
    lv_obj_t *  ui_LabelNameScheduleListItem;
    lv_obj_t *  ui_ButtonRemoveScheduleListItem;
} jsonScheduleItem;


extern Preferences preferences; // To Storage to NvM

extern jsonScheduleItem jsonScheduleItemList[3]; // To Storage entire Schedule Item List

extern const char* web_server_official;
extern const char* web_server;
extern const char* web_server_2;
extern const char* ota_server;


extern SemaphoreHandle_t lvgl_mutex;

extern String jsonString;

extern int numberOfPage;
extern int numberOfElement;
extern int currentPage;
extern int current_schedule_id;

extern int currentWateringHistoryPage;
extern int totalWateringHistoryPage;

extern uint16_t current_year;
extern uint16_t current_month;
extern uint16_t current_day;

extern bool touch_enabled;  // Flag to control whether touch is enabled
extern bool convert_mqtt_task;

extern const char *str_topic_temp1;
extern const char *str_topic_humi1;
extern const char *str_topic_kali1;
extern const char *str_topic_nito1;
extern const char *str_topic_photpho1;
extern const char *str_topic_temp2;
extern const char *str_topic_humi2;
extern const char *str_topic_kali2;
extern const char *str_topic_nito2;
extern const char *str_topic_photpho2;
extern const char *str_topic_temp3;
extern const char *str_topic_humi3;
extern const char *str_topic_kali3;
extern const char *str_topic_nito3;
extern const char *str_topic_photpho3;

//GENERAL
extern int current_area_for_sensors_log;
extern int current_area_for_sensors;

// OTA Mode
extern bool ota_running_flag;

// Sleep mode
extern bool is_touching;


// Debug mode
#define PRINT   1
#define PRINTLN 2
#define PRINTF  3


#define DEBUG_MODE  0 // Enable it to print all message


void print(uint8_t print_mode,  const char* msg, ...);
void buzz_in_second();
