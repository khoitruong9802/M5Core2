#include "wifi_service.h"

#include <WiFi.h>
#include <lvgl.h>

#include "../global.h"
#include "../gui/custom_widget.h"
#include "../gui/update/ui_update.h"
#define WIFI_TIMEOUT 4000  // ms

lv_obj_t *btn[9];
bool btn_flag = false;
uint8_t connect_wifi(const char *ssid, const char *password) {
  unsigned long startTime = millis();  // Get the current time

  print(PRINTF, "Connecting to %s with password %s...", ssid, password);
  WiFi.begin(ssid, password);
  while (millis() - startTime < WIFI_TIMEOUT && WiFi.status() != WL_CONNECTED) {
    delay(500);
    print(PRINT, ".");
  }
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.disconnect();
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
      save_wifi_credentials(wifiCredentials->username, wifiCredentials->password);
      uint8_t connect_ok = connect_wifi(wifiCredentials->username, wifiCredentials->password);
      vTaskDelete(NULL);
    }
    else {
      WiFi.disconnect();
    }
    vTaskDelay(pdMS_TO_TICKS(1000));
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
  lv_obj_add_flag(wifiLoading, LV_OBJ_FLAG_HIDDEN);
  vTaskDelete(NULL);
}
void save_wifi_credentials(const char* username, const char* password) {
  preferences.begin("wifi-config", false); // Mở namespace "wifi-config" ở chế độ ghi
  preferences.putString("wifi_user", username); // Lưu username
  preferences.putString("wifi_pass", password); // Lưu password
  preferences.end();
}

void check_wifi_icon()
{
  if(WiFi.isConnected())
  {
    _ui_flag_modify(ui_Image2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
  }
  else
  {
    _ui_flag_modify(ui_Image2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
  }
}