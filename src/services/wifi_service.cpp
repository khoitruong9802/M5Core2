#include "wifi_service.h"

#include <WiFi.h>
#include <lvgl.h>

#include "../global.h"
#include "../gui/custom_widget.h"
#include "../gui/update/ui_update.h"
#define WIFI_TIMEOUT 4000  // ms

// WiFi credentials
const char *ssid = "Mi tom thanh long";
const char *password = "87654321";
lv_obj_t *btn[9];
bool btn_flag = false;
uint8_t connect_wifi(const char *ssid, const char *password) {
  unsigned long startTime = millis();  // Get the current time

  print(PRINTF, "Connecting to %s", ssid);
  WiFi.begin(ssid, password);
  while (millis() - startTime < WIFI_TIMEOUT && WiFi.status() != WL_CONNECTED) {
    delay(500);
    print(PRINT, ".");
  }
  if (WiFi.status() != WL_CONNECTED) {
    return 0;
  }
  print(PRINTF, "\nWiFi connected");
  ui_update_wifi_status(1);
  return 1;
}

void wifi_service(void *parameter) {
  WifiCredentials *wifiCredentials = (WifiCredentials *)parameter;

  for (;;) {
    if (WiFi.status() != WL_CONNECTED) {
      // Connect to wifi

      ui_update_wifi_status(0);
      uint8_t connect_ok = connect_wifi(wifiCredentials->username, wifiCredentials->password);
      if (connect_ok == 0) {
        vTaskDelete(NULL);
      }
    }
    delay(1000);
  }
}

void click_wifi_handler(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *obj = lv_event_get_target(e);
  if (code == LV_EVENT_CLICKED) {
    print(PRINTF, "Clicked: %s", lv_list_get_btn_text(custom_ui_ListOfWifi, obj));
    lv_label_set_text(wifi_name_label, lv_list_get_btn_text(custom_ui_ListOfWifi, obj));
    _ui_flag_modify(enter_password_panel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
  }
}

void init_scan_wifi_list_element() {
  /*Add 9 list item*/
  if (btn_flag == false) {
    for (int i = 0; i < 9; i++) {
      print(PRINTLN, "test");
      btn[i] = lv_list_add_btn(custom_ui_ListOfWifi, NULL, "");
      lv_obj_add_event_cb(btn[i], click_wifi_handler, LV_EVENT_CLICKED, NULL);
    }
    btn_flag = true;
  }
}

void scan_wifi(void *parameter) {
  print(PRINTF, "scan start on core: %d\n", xPortGetCoreID());
  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  print(PRINTLN, "scan done");

  if (n == 0) {
    print(PRINTLN, "no networks found");
  } else {
    for (int i = 0; i < 9; ++i) {
      // Print SSID and RSSI for each network found
      String wifi_name = WiFi.SSID(i);
      const char *wifi_name_cstr = wifi_name.c_str();
      print(PRINTLN, wifi_name_cstr);
      lv_label_set_text(lv_obj_get_child(btn[i], 0), wifi_name_cstr);
    }
  }
  // for (int i = 0; i < n; i++)
  // {
  //   print(PRINTF,"%s\n", list_of_wifi->name_of_wifi[i]);
  // }
  print(PRINTLN, "Begin send event!");
  // lv_event_send(ui_WifiScreen, (lv_event_code_t)MY_LV_EVENT_SCAN_WIFI, (void *)list_of_wifi);
  print(PRINTLN, "End send event!");

  vTaskDelete(NULL);
}
