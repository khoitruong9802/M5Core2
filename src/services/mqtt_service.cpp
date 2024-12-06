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

const char *topic_notification = "18faa0dd7a927906cb3e/feeds/notification";

const char *topic_temp1 = "18faa0dd7a927906cb3e/feeds/area1/temp";
const char *topic_humi1 = "18faa0dd7a927906cb3e/feeds/area1/humi";
const char *topic_kali1 = "18faa0dd7a927906cb3e/feeds/area1/kali";
const char *topic_nito1 = "18faa0dd7a927906cb3e/feeds/area1/nito";
const char *topic_photpho1 = "18faa0dd7a927906cb3e/feeds/area1/photpho";
const char *topic_temp2 = "18faa0dd7a927906cb3e/feeds/area2/temp";
const char *topic_humi2 = "18faa0dd7a927906cb3e/feeds/area2/humi";
const char *topic_kali2 = "18faa0dd7a927906cb3e/feeds/area2/kali";
const char *topic_nito2 = "18faa0dd7a927906cb3e/feeds/area2/nito";
const char *topic_photpho2 = "18faa0dd7a927906cb3e/feeds/area2/photpho";
const char *topic_temp3 = "18faa0dd7a927906cb3e/feeds/area3/temp";
const char *topic_humi3 = "18faa0dd7a927906cb3e/feeds/area3/humi";
const char *topic_kali3 = "18faa0dd7a927906cb3e/feeds/area3/kali";
const char *topic_nito3 = "18faa0dd7a927906cb3e/feeds/area3/nito";
const char *topic_photpho3 = "18faa0dd7a927906cb3e/feeds/area3/photpho";


// Initialize the WiFi and MQTT clients
WiFiClient espClient;
PubSubClient client(espClient);

void callback(const char* topic, uint8_t* payload, unsigned int length) {
    // Convert payload to a null-terminated string
    char mqtt_payload[length + 1];
    memcpy(mqtt_payload, payload, length);
    mqtt_payload[length] = '\0';

    // Debug print to verify the incoming message
    // printf("Message received: %s from %s\n", mqtt_payload, topic);
    // Assign the value to the corresponding variable based on the topic
    if(current_area_for_sensors == 1)
    {
      if (strcmp(topic, topic_temp1) == 0) {
          lv_label_set_text(ui_Label22, mqtt_payload);
          str_topic_temp1 = lv_label_get_text(ui_Label22);
      } else if (strcmp(topic, topic_humi1) == 0) {
          lv_label_set_text(ui_Label27, mqtt_payload);
          str_topic_humi1 = lv_label_get_text(ui_Label27);
      } else if (strcmp(topic, topic_kali1) == 0) {
          lv_label_set_text(ui_Label166, mqtt_payload);
          str_topic_kali1 = lv_label_get_text(ui_Label166);
      } else if (strcmp(topic, topic_nito1) == 0) {
          lv_label_set_text(ui_Label26, mqtt_payload);
          str_topic_nito1 = lv_label_get_text(ui_Label26);
      } else if (strcmp(topic, topic_photpho1) == 0) {
          lv_label_set_text(ui_Label16, mqtt_payload);
          str_topic_photpho1 = lv_label_get_text(ui_Label16);
      } 
    }
    else if(current_area_for_sensors == 2)
    {
      if (strcmp(topic, topic_temp2) == 0) {
          lv_label_set_text(ui_Label22, mqtt_payload);
          str_topic_temp2 = lv_label_get_text(ui_Label22);
      } else if (strcmp(topic, topic_humi2) == 0) {
          lv_label_set_text(ui_Label27, mqtt_payload);
          str_topic_humi2 = lv_label_get_text(ui_Label27);
      } else if (strcmp(topic, topic_kali2) == 0) {
          lv_label_set_text(ui_Label166, mqtt_payload);
          str_topic_kali2 = lv_label_get_text(ui_Label166);
      } else if (strcmp(topic, topic_nito2) == 0) {
          lv_label_set_text(ui_Label26, mqtt_payload);
          str_topic_nito2 = lv_label_get_text(ui_Label26);
      } else if (strcmp(topic, topic_photpho2) == 0) {
          lv_label_set_text(ui_Label16, mqtt_payload);
          str_topic_photpho2 = lv_label_get_text(ui_Label16);
      }
    }
    else if(current_area_for_sensors == 3)
    {
      if (strcmp(topic, topic_temp3) == 0) {
          lv_label_set_text(ui_Label22, mqtt_payload);
          str_topic_temp3 = lv_label_get_text(ui_Label22);
      } else if (strcmp(topic, topic_humi3) == 0) {
          lv_label_set_text(ui_Label27, mqtt_payload);
          str_topic_humi3 = lv_label_get_text(ui_Label27);
      } else if (strcmp(topic, topic_kali3) == 0) {
          lv_label_set_text(ui_Label166, mqtt_payload);
          str_topic_kali3 = lv_label_get_text(ui_Label166);
      } else if (strcmp(topic, topic_nito3) == 0) {
          lv_label_set_text(ui_Label26, mqtt_payload);
          str_topic_nito3 = lv_label_get_text(ui_Label26);
      } else if (strcmp(topic, topic_photpho3) == 0) {
          lv_label_set_text(ui_Label16, mqtt_payload);
          str_topic_photpho3 = lv_label_get_text(ui_Label16);
      }
    }
    if (strcmp(topic, topic_notification) == 0) {
      buzz_in_second();
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
      if ( client.subscribe(topic_notification) 
        && client.subscribe(topic_temp1)
        && client.subscribe(topic_humi1)
        && client.subscribe(topic_kali1)
        && client.subscribe(topic_nito1)
        && client.subscribe(topic_photpho1)
        && client.subscribe(topic_temp2)
        && client.subscribe(topic_humi2)
        && client.subscribe(topic_kali2)
        && client.subscribe(topic_nito2)
        && client.subscribe(topic_photpho2)
        && client.subscribe(topic_temp3)
        && client.subscribe(topic_humi3)
        && client.subscribe(topic_kali3)
        && client.subscribe(topic_nito3)
        && client.subscribe(topic_photpho3))
       {
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
        vTaskDelay(pdMS_TO_TICKS(1000));
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
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

void mqtt_init(void * parameter)
{

  for(;;)
  {
    if (WiFi.status() != WL_CONNECTED) 
    {
      Serial.println("waiting for wifi connected...");
      vTaskDelay(pdMS_TO_TICKS(1000));
    }
    else
    {
      client.setServer(mqtt_server, mqtt_port);
      client.setCallback(callback);

      uint8_t connect_mqtt_res = connect_mqtt();
      if(connect_mqtt_res == 0)
      {
        print(PRINTLN, "MQTT task has been deleted!!");
        vTaskDelete(NULL);
      }
      break;
    }
  }
  for(;;)
  {
    if(convert_mqtt_task == 1)
    {
      vTaskDelay(pdMS_TO_TICKS(1000));
    }
    else
    {
      if (!client.connected()) {
        connect_mqtt();
      }
      client.loop();
      vTaskDelay(pdMS_TO_TICKS(1000));
    }
  }
}
