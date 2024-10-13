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


void cleanup_wifi_list(ListOfWifi *list_of_wifi) {
  // Clean up each SSID name
  for (int i = 0; i < *(list_of_wifi->number_of_wifi); ++i) {
    delete[] list_of_wifi->name_of_wifi[i];  // Free each SSID string
  }

  // Clean up the array of SSID names
  delete[] list_of_wifi->name_of_wifi;

  // Clean up the number_of_wifi pointer
  delete list_of_wifi->number_of_wifi;

  // Finally, free the ListOfWifi structure
  delete list_of_wifi;

  Serial.println("Memory cleanup completed.");
}

void scan_wifi() {

}
