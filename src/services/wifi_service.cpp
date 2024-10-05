#include "wifi_service.h"

#include <WiFi.h>
#include <lvgl.h>

#include "../global.h"
#include "../gui/ui_custom_events.h"

#define WIFI_TIMEOUT 4000 // ms

// WiFi credentials
const char *ssid = "Mi tom thanh long";
const char *password = "87654321";

uint8_t connect_wifi(const char *ssid, const char *password) {
  unsigned long startTime = millis(); // Get the current time

  Serial.printf("Connecting to %s", ssid);
  WiFi.begin(ssid, password);
  while (millis() - startTime < WIFI_TIMEOUT && WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  if (WiFi.status() != WL_CONNECTED) {
    return 0;
  }
  Serial.printf("\nWiFi connected");
  lv_event_send(ui_Image2, (lv_event_code_t)MY_LV_EVENT_WIFI_ON, NULL);
  return 1;
}

void wifi_service(void *parameter) {
  WifiCredentials *wifiCredentials = (WifiCredentials *) parameter;

  for (;;) {
    if (WiFi.status() != WL_CONNECTED) {
      // Connect to wifi

      lv_event_send(ui_Image2, (lv_event_code_t)MY_LV_EVENT_WIFI_OFF, NULL);
      uint8_t connect_ok = connect_wifi(wifiCredentials->username, wifiCredentials->password);
      if (connect_ok == 0) {
        vTaskDelete(NULL);
      }
    }
    delay(1000);
  }
}

void scan_wifi(void *parameter) {
  Serial.printf("scan start on core: %d\n", xPortGetCoreID());

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  ListOfWifi *list_of_wifi = new ListOfWifi;
  list_of_wifi->number_of_wifi = new int(n);
  list_of_wifi->name_of_wifi = new char *[n];

  if (n == 0) {
    Serial.println("no networks found");
  } else {
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      String wifi_name = WiFi.SSID(i);
      list_of_wifi->name_of_wifi[i] = new char[wifi_name.length() + 1];
      strcpy(list_of_wifi->name_of_wifi[i], wifi_name.c_str());
    }
  }
  // for (int i = 0; i < n; i++)
  // {
  //   Serial.printf("%s\n", list_of_wifi->name_of_wifi[i]);
  // }
  Serial.println("Begin send event!");
  lv_event_send(ui_WifiScreen, (lv_event_code_t)MY_LV_EVENT_SCAN_WIFI, (void *)list_of_wifi);
  Serial.println("End send event!");

  vTaskDelete(NULL);
}
