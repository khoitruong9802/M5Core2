#include "ui_start.h"
#include <lvgl.h>
#include "../global.h"
#include "driver/lvgl_driver.h"
#include "ui.h"
#include "ui_custom_events.h"
#include "custom_widget.h"

void custom_event_init() {
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
  lv_obj_add_event_cb(ui_WifiScreen, scan_wifi_handler, (lv_event_code_t)MY_LV_EVENT_SCAN_WIFI, NULL);
}

void custom_widget_init() {
  list_wifi_widget_init();
  enter_password_widget_init();
}

int count = 0;
void ui_start(void *parameter) {
  lv_init();
  lvgl_driver_init();
  ui_init();
  custom_widget_init();
  custom_event_init();

  for (;;) {
    if (count == 100) {
      Serial.printf("ui handler run on core: %d\n", xPortGetCoreID());
      count = 0;
    }
    count++;
    if (xSemaphoreTake(lvgl_mutex, 0) == pdTRUE) {
      // Critical section (access shared resource here)
      lv_timer_handler();

      // Release the mutex after critical section
      xSemaphoreGive(lvgl_mutex);
    } else {
      Serial.println("ui handler can not require semaphore");
    }
    delay(10);

    // lv_timer_handler();
    // delay(5);
  }
}