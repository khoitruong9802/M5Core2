#include "wifi_service.h"
#include <WiFi.h>
#include <lvgl.h>
#include "../gui/ui_custom_events.h"
#include "../global.h"

// WiFi credentials
const char *ssid = "Mi tom thanh long";
const char *password = "87654321";

void connect_wifi(const char *ssid, const char *password)
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
      connect_wifi(::ssid, ::password);
    }
    delay(1000);
  }
}

static lv_obj_t *RenderListOfWifi;

static void event_handler(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *obj = lv_event_get_target(e);
  if (code == LV_EVENT_CLICKED)
  {
    const char *wifi_name = lv_list_get_btn_text(RenderListOfWifi, obj);
    Serial.printf("Clicked: %s", wifi_name);
    if (strcmp(wifi_name, "Mi tom thanh long") == 0)
    {
      xTaskCreate(wifi_service, "wifi_service", 4096, NULL, 2, NULL);
    }
  }
}

void scan_wifi(void *parameter)
{

  Serial.printf("scan start on core: %d\n", xPortGetCoreID());
  vTaskDelay(1000);

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  ListOfWifi *list_of_wifi = new ListOfWifi;
  list_of_wifi->number_of_wifi = new int(n);
  list_of_wifi->name_of_wifi = new char *[n];

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
      strcpy(list_of_wifi->name_of_wifi[i], wifi_name.c_str());
    }
  }
  // for (int i = 0; i < n; i++)
  // {
  //   Serial.printf("%s\n", list_of_wifi->name_of_wifi[i]);
  // }
  Serial.println("Begin send event!");
  // lv_event_send(ui_WifiScreen, (lv_event_code_t)MY_LV_EVENT_SCAN_WIFI, (void *)list_of_wifi);
  // Serial.println("End send event!");

  Serial.println("in scan wifi handler");
  // Serial.printf("data = %s, pointer = %p, pointer to = %p\n", data, &data, data);
  if (list_of_wifi == NULL)
  {
    Serial.println("list of wifi is null");
  }
  if (list_of_wifi->name_of_wifi == NULL)
  {
    Serial.println("name of wifi is null");
  }

  /*Create a list*/
  if (xSemaphoreTake(my_mutex, portMAX_DELAY) == pdTRUE)
  {
    // Critical section (access shared resource here)
    RenderListOfWifi = lv_list_create(lv_scr_act());
    lv_obj_set_size(RenderListOfWifi, 310, 230);
    lv_obj_center(RenderListOfWifi);

    /*Add buttons to the list*/
    lv_list_add_text(RenderListOfWifi, "Wifi");

    // Release the mutex after critical section
    xSemaphoreGive(my_mutex);
  }
  else
  {
    Serial.println("fail to init variable");
  }
  lv_obj_t *btn;

  for (int i = 0; i < *list_of_wifi->number_of_wifi; i++)
  {
    Serial.printf("%s\n", list_of_wifi->name_of_wifi[i]);
    if (xSemaphoreTake(my_mutex, portMAX_DELAY) == pdTRUE)
    {
      // Critical section (access shared resource here)
      Serial.printf("Render wifi on core: %d\n", xPortGetCoreID());
      // vTaskDelay(500);
      btn = lv_list_add_btn(RenderListOfWifi, NULL, list_of_wifi->name_of_wifi[i]);
      lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, NULL);

      // Release the mutex after critical section
      Serial.printf("check1");
      xSemaphoreGive(my_mutex);
      Serial.printf("check2");
    }
    else
    {
      Serial.println("fail to render wifi name");
    }
  }

  if (list_of_wifi != nullptr)
  {
    // Free each allocated string
    if (list_of_wifi->name_of_wifi != nullptr)
    {
      for (int i = 0; i < *(list_of_wifi->number_of_wifi); i++)
      {
        delete[] list_of_wifi->name_of_wifi[i];
      }
      // Free the array of char pointers
      delete[] list_of_wifi->name_of_wifi;
    }
    else
    {
      Serial.println("name of wifi is null");
    }
    // Free the integer
    delete list_of_wifi->number_of_wifi;
    // Free the ListOfWifi object itself
    delete list_of_wifi;
  }
  else
  {
    Serial.println("list of wifi is null");
  }
  Serial.println("End scan!!!!!!!!!!!!!");

  vTaskDelete(NULL);
}
