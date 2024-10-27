#include "mqtt_service.h"

#include <ArduinoJson.h>
#include <lvgl.h>

#include "../global.h"
#include "../gui/update/ui_update.h"

#define MQTT_TIMEOUT 5000      // ms
#define WIFI_MQTT_TIMEOUT 500  // ms

// MQTT broker details
const char *mqtt_server = "io.adafruit.com";
const int mqtt_port = 1883;
const char *mqtt_user = "";
const char *mqtt_password = "";

const char *topic_devices = "khoitruong9802/feeds/devices";
const char *topic_nutnhan1 = "khoitruong9802/feeds/nutnhan1";
const char *topic_nutnhan2 = "khoitruong9802/feeds/nutnhan2";
const char *topic_cambien1 = "khoitruong9802/feeds/cambien1";
const char *topic_cambien2 = "khoitruong9802/feeds/cambien2";
const char *topic_cambien3 = "khoitruong9802/feeds/cambien3";

// Initialize the WiFi and MQTT clients
WiFiClient espClient;
PubSubClient client(espClient);

void callback(char *topic, uint8_t *payload, unsigned int length) {
  // char *mqtt_topic = new char[strlen(topic) + 1];
  // strcpy(mqtt_topic, topic);

  uint8_t mqtt_payload[length + 1];
  memcpy(mqtt_payload, payload, length);
  mqtt_payload[length] = '\0';

  print(PRINTF, "Message received: %s from %s\n", mqtt_payload, topic);

  if (strcmp(topic, "khoitruong9802/feeds/cambien1") == 0) {
    print(PRINTLN, "Update temp!!");

    ui_update_mqtt_sensor_label(ui_Label22, mqtt_payload);
  } else if (strcmp(topic, "khoitruong9802/feeds/cambien2") == 0) {
    print(PRINTLN, "Update humi!!");

    ui_update_mqtt_sensor_label(ui_Label27, mqtt_payload);
  } else if (strcmp(topic, "khoitruong9802/feeds/cambien3") == 0) {
    print(PRINTLN, "Update light!!");

    ui_update_mqtt_sensor_label(ui_Label26, mqtt_payload);
  } else if (strcmp(topic, "khoitruong9802/feeds/nutnhan1") == 0) {
    print(PRINTLN, "Update switch!!");

    ui_update_mqtt_device_switch(ui_Switch1, mqtt_payload);
  } else if (strcmp(topic, "khoitruong9802/feeds/nutnhan2") == 0) {
    print(PRINTLN, "Update switch!!");

    ui_update_mqtt_device_switch(ui_Switch2, mqtt_payload);
  }
}

uint8_t connect_mqtt() {
  unsigned long startTime = millis();  // Get the current time
  uint8_t connect_ok = 1;
  client.setServer(mqtt_server, mqtt_port);
  while (millis() - startTime < MQTT_TIMEOUT && !client.connected()) {
    print(PRINTLN, "Connecting to MQTT broker...");
    if (client.connect("ij34j32oj523kn6lk32n6ljoiij", mqtt_user, mqtt_password)) {
      print(PRINTLN, "Connected to MQTT broker!");
      if (client.subscribe(topic_nutnhan1) && client.subscribe(topic_nutnhan2) && client.subscribe(topic_cambien1) && client.subscribe(topic_cambien2) && client.subscribe(topic_cambien3)) {
        client.setCallback(callback);
        print(PRINTLN, "Subcribe to topic successfully!");
        connect_ok = 1;
      } else {
        print(PRINTLN, "Subcribe fail!");
        connect_ok = 0;
      }
    } else {
      print(PRINT, "Failed with state ");
      print(PRINTLN, std::to_string(client.state()).c_str());
      delay(500);
    }
  }
  if (!client.connected()) {
    connect_ok = 0;
  }
  return connect_ok;
}

void mqtt_service(void *parameter) {
  for (;;) {
    if (WiFi.status() != WL_CONNECTED) {
      unsigned long startTime = millis();  // Get the current time
      while (millis() - startTime < WIFI_MQTT_TIMEOUT && WiFi.status() != WL_CONNECTED) {
        // Connect to wifi
        print(PRINTLN, "Wifi disconnected!! Connect wifi to use MQTT");
        delay(100);
        continue;
      }
      if (WiFi.status() != WL_CONNECTED) {
        uint8_t connected = 0;
        ui_update_mqtt_connect_ok(connected);
        vTaskDelete(NULL);
      }
    }
    if (!client.connected()) {
      // Connect to MQTT broker
      uint8_t connected = connect_mqtt();
      ui_update_mqtt_connect_ok(connected);
      if (connected == 0) {
        vTaskDelete(NULL);
      }
    }
    // else {
    //   print(PRINTLN,"Mqtt client connected");
    // }
    client.loop();
    delay(100);
  }
}
