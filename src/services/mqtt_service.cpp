#include "mqtt_service.h"
#include <lvgl.h>
#include "../gui/ui_custom_events.h"
#include <ArduinoJson.h>

#define MQTT_TIMEOUT 5000     // ms
#define WIFI_MQTT_TIMEOUT 500 // ms

// MQTT broker details
const char *mqtt_server = "io.adafruit.com";
const int mqtt_port = 1883;
const char *mqtt_user = "khoitruong9802";
const char *mqtt_password = "khoitruong9802";

const char *topic_devices  = "khoitruong9802/feeds/devices";
const char *topic_nutnhan1 = "khoitruong9802/feeds/nutnhan1";
const char *topic_nutnhan2 = "khoitruong9802/feeds/nutnhan2";
const char *topic_cambien1 = "khoitruong9802/feeds/cambien1";
const char *topic_cambien2 = "khoitruong9802/feeds/cambien2";
const char *topic_cambien3 = "khoitruong9802/feeds/cambien3";

// Initialize the WiFi and MQTT clients
WiFiClient espClient;
PubSubClient client(espClient);

void callback(char *topic, uint8_t *payload, unsigned int length)
{
  // char *mqtt_topic = new char[strlen(topic) + 1];
  // strcpy(mqtt_topic, topic);
  char *mqtt_payload = new char[length + 1];
  memcpy(mqtt_payload, payload, length);
  mqtt_payload[length] = '\0';

  Serial.printf("Message received: %s from %s\n", mqtt_payload, topic);

  if (strcmp(topic, "khoitruong9802/feeds/cambien1") == 0)
  {
    Serial.println("Update temp!!");
    // Serial.printf("data = %s, pointer = %p, pointer to = %p\n", mqtt_payload, &mqtt_payload, mqtt_payload);

    lv_event_send(ui_Label22, (lv_event_code_t)MY_LV_EVENT_MQTT_UPDATE_LABEL, (void *)mqtt_payload);
  }
  else if (strcmp(topic, "khoitruong9802/feeds/cambien2") == 0)
  {
    Serial.println("Update humi!!");
    // Serial.printf("data = %s, pointer = %p, pointer to = %p\n", mqtt_payload, &mqtt_payload, mqtt_payload);

    lv_event_send(ui_Label27, (lv_event_code_t)MY_LV_EVENT_MQTT_UPDATE_LABEL, (void *)mqtt_payload);
  }
  else if (strcmp(topic, "khoitruong9802/feeds/cambien3") == 0)
  {
    Serial.println("Update light!!");
    // Serial.printf("data = %s, pointer = %p, pointer to = %p\n", mqtt_payload, &mqtt_payload, mqtt_payload);

    lv_event_send(ui_Label26, (lv_event_code_t)MY_LV_EVENT_MQTT_UPDATE_LABEL, (void *)mqtt_payload);
  }
  else if (strcmp(topic, "khoitruong9802/feeds/nutnhan1") == 0)
  {
    Serial.println("Update switch!!");
    lv_event_send(ui_Switch1, (lv_event_code_t)MY_LV_EVENT_MQTT_UPDATE_SWITCH, (void *)mqtt_payload);
  }
  else if (strcmp(topic, "khoitruong9802/feeds/nutnhan2") == 0)
  {
    Serial.println("Update switch!!");
    lv_event_send(ui_Switch2, (lv_event_code_t)MY_LV_EVENT_MQTT_UPDATE_SWITCH, (void *)mqtt_payload);
  }
  // else if (strcmp(topic, "khoitruong9802/feeds/devices") == 0)
  // {
  //   DynamicJsonDocument doc(1024);                                   // Tạo một bộ đệm động cho tài liệu JSON
  //   DeserializationError error = deserializeJson(doc, mqtt_payload); // Phân tích JSON

  //   // Kiểm tra lỗi phân tích
  //   if (error)
  //   {
  //     Serial.print("deserializeJson() failed: ");
  //     Serial.println(error.c_str());
  //     return;
  //   }

  //   // Trích xuất các giá trị từ JSON
  //   const char *station_id = doc["station_id"];
  //   const char *station_name = doc["station_name"];
  //   JsonArray devices = doc["devices"];

  //   // Serial.print("Station ID: ");
  //   // Serial.println(station_id);
  //   // Serial.print("Station Name: ");
  //   // Serial.println(station_name);

  //   Serial.println("Devices:");
  //   for (JsonObject device : devices)
  //   {
  //     const char *device_id = device["device_id"];
  //     const char *device_name = device["device_name"];
  //     uint8_t *device_value = new uint8_t(device["device_value"]);

  //     // Serial.print("Device ID: ");
  //     // Serial.println(device_id);
  //     // Serial.print("Device name: ");
  //     // Serial.println(device_name);
  //     // Serial.print("Device value: ");
  //     // Serial.println(*device_value);

  //     if (strcmp(device_id, "pump_0001") == 0)
  //     {
  //       lv_event_send(ui_Switch1, (lv_event_code_t)MY_LV_EVENT_MQTT_UPDATE_SWITCH, (void *)device_value);
  //     }
  //     else if (strcmp(device_id, "pump_0002") == 0)
  //     {
  //       lv_event_send(ui_Switch2, (lv_event_code_t)MY_LV_EVENT_MQTT_UPDATE_SWITCH, (void *)device_value);
  //     }
  //   }
  //   Serial.println("Update switch!!");
  // }
}

uint8_t connect_mqtt()
{
  unsigned long startTime = millis(); // Get the current time
  uint8_t connect_ok = 1;
  client.setServer(mqtt_server, mqtt_port);
  while (millis() - startTime < MQTT_TIMEOUT && !client.connected())
  {
    Serial.println("Connecting to MQTT broker...");
    if (client.connect("ij34j32oj523kn6lk32n6ljoiij", mqtt_user, mqtt_password))
    {
      Serial.println("Connected to MQTT broker!");
      if (client.subscribe(topic_nutnhan1) && client.subscribe(topic_nutnhan2) && client.subscribe(topic_cambien1) && client.subscribe(topic_cambien2) && client.subscribe(topic_cambien3))
      {
        client.setCallback(callback);
        Serial.println("Subcribe to topic successfully!");
        connect_ok = 1;
      }
      else
      {
        Serial.println("Subcribe fail!");
        connect_ok = 0;
      }
    }
    else
    {
      Serial.print("Failed with state ");
      Serial.println(client.state());
      delay(500);
    }
  }
  if (!client.connected())
  {
    connect_ok = 0;
  }
  return connect_ok;
}

void mqtt_service(void *parameter)
{
  for (;;)
  {
    if (WiFi.status() != WL_CONNECTED)
    {
      unsigned long startTime = millis(); // Get the current time
      while (millis() - startTime < WIFI_MQTT_TIMEOUT && WiFi.status() != WL_CONNECTED)
      {
        // Connect to wifi
        Serial.println("Wifi disconnected!! Connect wifi to use MQTT");
        delay(100);
        continue;
      }
      if (WiFi.status() != WL_CONNECTED)
      {
        uint8_t *connected = new uint8_t(0);
        lv_event_send(ui_Panel40, (lv_event_code_t)MY_LV_EVENT_MQTT_CONNECT_OK, (void *)connected);
        vTaskDelete(NULL);
      }
    }
    if (!client.connected())
    {
      // Connect to MQTT broker
      uint8_t connect_ok = connect_mqtt();
      uint8_t *connected = new uint8_t(connect_ok);
      lv_event_send(ui_Panel40, (lv_event_code_t)MY_LV_EVENT_MQTT_CONNECT_OK, (void *)connected);
      if (connect_ok == 0)
      {
        vTaskDelete(NULL);
      }
    }
    // else {
    //   Serial.println("Mqtt client connected");
    // }
    client.loop();
    delay(100);
  }
}
