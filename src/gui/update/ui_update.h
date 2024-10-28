#pragma once

#include <lvgl.h>

#include "../custom_widget.h"
#include "../ui.h"

void ui_update_mqtt_connect_ok(uint8_t data);
void ui_update_mqtt_sensor_label(lv_obj_t *target, uint8_t *data);
void ui_update_mqtt_device_switch(lv_obj_t *target, uint8_t *data);
void ui_update_rtc_time(lv_obj_t *target, uint8_t *data);
void ui_update_wifi_status(uint8_t data);
