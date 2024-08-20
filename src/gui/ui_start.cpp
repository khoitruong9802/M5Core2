#include <lvgl.h>
#include "ui_start.h"
#include "ui.h"
#include "driver/lvgl_driver.h"
#include "ui_custom_events.h"

void custom_event_init()
{
  lv_obj_add_event_cb(ui_Panel40, mqtt_connect_ok_handler, (lv_event_code_t)MY_LV_EVENT_MQTT_CONNECT_OK, NULL);
  lv_obj_add_event_cb(ui_Label22, mqtt_update_handler, (lv_event_code_t)MY_LV_EVENT_MQTT_UPDATE_LABEL, NULL);
  lv_obj_add_event_cb(ui_Label27, mqtt_update_handler, (lv_event_code_t)MY_LV_EVENT_MQTT_UPDATE_LABEL, NULL);
  lv_obj_add_event_cb(ui_Label26, mqtt_update_handler, (lv_event_code_t)MY_LV_EVENT_MQTT_UPDATE_LABEL, NULL);
  lv_obj_add_event_cb(ui_Switch1, mqtt_update_handler, (lv_event_code_t)MY_LV_EVENT_MQTT_UPDATE_SWITCH, NULL);
  lv_obj_add_event_cb(ui_Switch2, mqtt_update_handler, (lv_event_code_t)MY_LV_EVENT_MQTT_UPDATE_SWITCH, NULL);
  lv_obj_add_event_cb(ui_Label1, rtc_update_handler, (lv_event_code_t)MY_LV_EVENT_RTC_UPDATE_LABEL, NULL);
  lv_obj_add_event_cb(ui_Label2, rtc_update_handler, (lv_event_code_t)MY_LV_EVENT_RTC_UPDATE_LABEL, NULL);
  lv_obj_add_event_cb(ui_Image2, wifi_update_handler, (lv_event_code_t)MY_LV_EVENT_WIFI_OFF, NULL);
  lv_obj_add_event_cb(ui_Image2, wifi_update_handler, (lv_event_code_t)MY_LV_EVENT_WIFI_ON, NULL);
  lv_obj_add_event_cb(ui_MainScreen, change_screen_handler, (lv_event_code_t)MY_LV_EVENT_CHANGE_SCREEN, NULL);
  lv_obj_add_event_cb(ui_MainScreen, back_screen_handler, (lv_event_code_t)MY_LV_EVENT_BACK_SCREEN, NULL);
  lv_obj_add_event_cb(ui_WifiScreen, scan_wifi_handler, (lv_event_code_t)MY_LV_EVENT_SCAN_WIFI, NULL);
}

void ui_start()
{
  lv_init();
  lvgl_driver_init();
  ui_init();
  custom_event_init();
}