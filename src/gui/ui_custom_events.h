#pragma once

#include <lvgl.h>
#include "ui.h"
#include "custom_widget.h"

extern uint32_t MY_LV_EVENT_MQTT_CONNECT_OK;
extern uint32_t MY_LV_EVENT_MQTT_UPDATE_LABEL;
extern uint32_t MY_LV_EVENT_MQTT_UPDATE_SWITCH;
extern uint32_t MY_LV_EVENT_RTC_UPDATE_LABEL;
extern uint32_t MY_LV_EVENT_WIFI_OFF;
extern uint32_t MY_LV_EVENT_WIFI_ON;


void mqtt_connect_ok_handler(lv_event_t * e);
void mqtt_update_handler(lv_event_t * e);
void rtc_update_handler(lv_event_t * e);
void wifi_update_handler(lv_event_t * e);
void scan_wifi_handler(lv_event_t * e);
