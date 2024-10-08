#include "ui_custom_events.h"

#include <M5Unified.h>

#include "../global.h"
#include "../services/wifi_service.h"

uint32_t MY_LV_EVENT_MQTT_CONNECT_OK = lv_event_register_id();
uint32_t MY_LV_EVENT_MQTT_UPDATE_LABEL = lv_event_register_id();
uint32_t MY_LV_EVENT_MQTT_UPDATE_SWITCH = lv_event_register_id();
uint32_t MY_LV_EVENT_RTC_UPDATE_LABEL = lv_event_register_id();
uint32_t MY_LV_EVENT_WIFI_OFF = lv_event_register_id();
uint32_t MY_LV_EVENT_WIFI_ON = lv_event_register_id();
uint32_t MY_LV_EVENT_SCAN_WIFI = lv_event_register_id();

void mqtt_connect_ok_handler(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  uint8_t *data = (uint8_t *)e->param;
  Serial.printf("data = %d, pointer = %p, pointer to = %p\n", *data, &data, data);
  if (event_code == MY_LV_EVENT_MQTT_CONNECT_OK) {
    if (*data == 0) {
      _ui_screen_change(&ui_AppScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_AppScreen_screen_init);
      _ui_flag_modify(target, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
      _ui_flag_modify(ui_Panel42, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    } else if (*data == 1) {
      _ui_flag_modify(target, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
      _ui_screen_change(&ui_MqttScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_MqttScreen_screen_init);
    }
  }
  delete[] data;
}

void mqtt_update_handler(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == MY_LV_EVENT_MQTT_UPDATE_LABEL) {
    char *data = (char *)e->param;
    _ui_label_set_property(target, _UI_LABEL_PROPERTY_TEXT, data);
    delete[] data;
  } else if (event_code == MY_LV_EVENT_MQTT_UPDATE_SWITCH) {
    uint8_t *data = (uint8_t *)e->param;
    Serial.printf("data = %d", *data);
    if (*data == 48) {
      _ui_state_modify(target, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
      Serial.printf("data = 0");
    } else if (*data == 49) {
      _ui_state_modify(target, LV_STATE_CHECKED, _UI_MODIFY_STATE_ADD);
      Serial.printf("data = 1");
    }
    delete data;
  }
}

void rtc_update_handler(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  char *data = (char *)e->param;
  if (event_code == MY_LV_EVENT_RTC_UPDATE_LABEL) {
    _ui_label_set_property(target, _UI_LABEL_PROPERTY_TEXT, data);
  }
  delete[] data;
}

void wifi_update_handler(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == MY_LV_EVENT_WIFI_OFF) {
    _ui_flag_modify(ui_Image2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
  } else if (event_code == MY_LV_EVENT_WIFI_ON) {
    _ui_flag_modify(ui_Image2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
  }
}

static void click_wifi_handler(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *obj = lv_event_get_target(e);
  if (code == LV_EVENT_CLICKED) {
    Serial.printf("Clicked: %s", lv_list_get_btn_text(custom_ui_ListOfWifi, obj));
    lv_label_set_text(wifi_name_label, lv_list_get_btn_text(custom_ui_ListOfWifi, obj));
    _ui_flag_modify(enter_password_panel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
  }
}

void scan_wifi_handler(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  ListOfWifi *list_of_wifi = (ListOfWifi *)e->param;
  Serial.println("in scan wifi handler");
  // Serial.printf("data = %s, pointer = %p, pointer to = %p\n", data, &data, data);
  if (list_of_wifi == NULL) {
    Serial.println("list of wifi is null");
  }
  if (list_of_wifi->name_of_wifi == NULL) {
    Serial.println("name of wifi is null");
  }

  lv_obj_t *btn;

  if (event_code == MY_LV_EVENT_SCAN_WIFI) {
    if (xSemaphoreTake(lvgl_mutex, portMAX_DELAY) == pdTRUE) {
      for (int i = 0; i < *list_of_wifi->number_of_wifi; i++) {
        Serial.printf("%s\n", list_of_wifi->name_of_wifi[i]);

        // Critical section (access shared resource here)
        btn = lv_list_add_btn(custom_ui_ListOfWifi, NULL, list_of_wifi->name_of_wifi[i]);
        lv_obj_add_event_cb(btn, click_wifi_handler, LV_EVENT_CLICKED, NULL);

        // Release the mutex after critical section
      }
      xSemaphoreGive(lvgl_mutex);
    } else {
      Serial.println("fail to render wifi name");
    }
  }

  // if (list_of_wifi != nullptr) {
  //   // Free each allocated string
  //   if (list_of_wifi->name_of_wifi != nullptr) {
  //     for (int i = 0; i < *(list_of_wifi->number_of_wifi); i++) {
  //       delete[] list_of_wifi->name_of_wifi[i];
  //     }
  //     // Free the array of char pointers
  //     delete[] list_of_wifi->name_of_wifi;
  //   } else {
  //     Serial.println("name of wifi is null");
  //   }
  //   // Free the integer
  //   delete list_of_wifi->number_of_wifi;
  //   // Free the ListOfWifi object itself
  //   delete list_of_wifi;
  // } else {
  //   Serial.println("list of wifi is null");
  // }
  Serial.println("End scan!!!!!!!!!!!!!");
}
