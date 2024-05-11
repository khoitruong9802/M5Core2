#include "wifi_service.h"
#include <WiFi.h>
#include <lvgl.h>
#include "../gui/ui_custom_events.h"

// WiFi credentials
const char *ssid = "pagoda wifi";
const char *password = "87654321";

void connect_wifi()
{
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  lv_event_send(ui_Image2, (lv_event_code_t)MY_LV_EVENT_WIFI_ON, NULL);
}

void wifi_service(void *parameter)
{
  for (;;)
  {
    if (WiFi.status() != WL_CONNECTED)
    {
      // Connect to wifi

      lv_event_send(ui_Image2, (lv_event_code_t)MY_LV_EVENT_WIFI_OFF, NULL);
      connect_wifi();
    }
    delay(1000);
  }
}

void scan_wifi(void *parameter)
{
  Serial.println("scan start");

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");

  ListOfWifi *list_of_wifi = new ListOfWifi;
  list_of_wifi->number_of_wifi = new int(n);
  list_of_wifi->name_of_wifi = new const char *[n];

  if (n == 0)
  {
    Serial.println("no networks found");
  }
  else
  {
    for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      String wifi_name = WiFi.SSID(i);
      list_of_wifi->name_of_wifi[i] = new char[wifi_name.length() + 1];
      list_of_wifi->name_of_wifi[i] = wifi_name.c_str();
    }
  }
  for (int i = 0; i < n; i++)
  {
    Serial.printf("%s\n", list_of_wifi->name_of_wifi[i]);
  }

  // lv_event_send(ui_WifiScreen, (lv_event_code_t)MY_LV_EVENT_SCAN_WIFI, (void *)list_of_wifi);

  vTaskDelete(NULL);
}
