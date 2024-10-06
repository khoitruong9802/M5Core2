// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: m5core2

#include "ui.h"
#include <M5Unified.h>
#include "global.h"
#include "../services/mqtt_service.h"
#include "../services/wifi_service.h"
#include "../m5helper/brightness.h"
#include "services/ota_service.h"



const char *get_json_device(uint8_t device1_status, uint8_t device2_status) {
    char *result = new char[256];
    snprintf(result, 256, "{\"station_id\":\"WATER_0001\",\"station_name\":\"WATER 0001\",\"devices\":[{\"device_id\":\"pump_0001\",\"device_name\":\"pump_0001\",\"device_value\":%d},{\"device_id\":\"pump_0002\",\"device_name\":\"pump_0002\",\"device_value\":%d}]}", device1_status, device2_status);
    return result;
}

void button2_on(lv_event_t *e)
{
    // Your code here
    client.publish("khoitruong9802/feeds/nutnhan2", "1");

    // const char *publish_data = get_json_device(0, 1);
    // Serial.println(publish_data);
    // client.publish("khoitruong9802/feeds/devices", publish_data);
    // delete[] publish_data;
}

void button2_off(lv_event_t *e)
{
    // Your code
    client.publish("khoitruong9802/feeds/nutnhan2", "0");
}

void button1_on(lv_event_t *e)
{
    // Your code here
    client.publish("khoitruong9802/feeds/nutnhan1", "1");
}

void button1_off(lv_event_t *e)
{
    // Your code here
    client.publish("khoitruong9802/feeds/nutnhan1", "0");
}

void change_brightness(lv_event_t *e)
{
    // Your code here
    lv_obj_t *slider = lv_event_get_target(e);
    uint8_t brightness = (int)lv_slider_get_value(slider);
    set_brightness(brightness);
}

void change_screen_mqtt(lv_event_t *e)
{
    // Your code here
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        if (WiFi.status() != WL_CONNECTED)
        {
            _ui_flag_modify(ui_Panel29, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        }
        else
        {
            TaskHandle_t mqtt_task = xTaskGetHandle("mqtt_service");
            if (mqtt_task != NULL)
            {
                Serial.println("Mqtt has created");
                _ui_screen_change(&ui_MqttScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_MqttScreen_screen_init);
            }
            else
            {
                xTaskCreate(mqtt_service, "mqtt_service", 4096, NULL, 1, NULL);
                _ui_flag_modify(ui_Panel40, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
            }
        }
    }
}

void cancel_start_mqtt(lv_event_t *e)
{
    // Your code here
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_flag_modify(ui_Panel40, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        TaskHandle_t mqtt_task = xTaskGetHandle("mqtt_service");
        vTaskDelete(mqtt_task);
    }
}

void scan_network(lv_event_t *e)
{
    // Your code here
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        TaskHandle_t scan_wifi_task = xTaskGetHandle("scan_wifi");
        if (scan_wifi_task != NULL)
        {
            Serial.println("scan_wifi has created");
        }
        else
        {
            xTaskCreatePinnedToCore(scan_wifi, "scan_wifi", 8192, NULL, 5, NULL, 0);
        }
        _ui_screen_change(&ui_WifiScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_WifiScreen_screen_init);
    }
}

void change_screen_ota(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    _ui_screen_change(&ui_OtaScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_OtaScreen_screen_init);
    TaskHandle_t ota_task = xTaskGetHandle("ota_update");
    if (ota_task == NULL)
    {
        if (WiFi.status() == WL_CONNECTED)
        {
            String filename = getLatestFirmwareFileName(web_server);
            for(;;)
            {
                if (!SPIFFS.begin(true)) 
                {  // true to format the file system if mounting fails
                    Serial.println("SPIFFS Mount Failed");
                } else 
                {
                    Serial.println("SPIFFS Mount Success");
                    break;
                }
            }
            File file = SPIFFS.open("/firmware_version.txt", "r");
            if (!file) 
            {
                Serial.println("Failed to open version file for checking");

            } else 
            {
                Serial.println("File opened successfully");
                String line = file.readStringUntil('\n');
                file.close();
                Serial.println("The original:");
                Serial.println(line);
                Serial.println("The new:");
                Serial.println(filename);
                String name_of_old_file;
                String name_of_new_file;
                for(int i = 0; i <  filename.length() &&  i < line.length(); i++){
                    name_of_new_file += filename[i];
                    name_of_old_file += line[i];
                }
                if(name_of_new_file != name_of_old_file || name_of_old_file == NULL)
                {
                    _ui_flag_modify(ui_Panel102, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
                } 
                else
                {
                    _ui_flag_modify(ui_Panel104, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
                    Serial.println("No change!");
                }
            }
            
        }
        else
        {
            // remove flag of ui_Panel106 to show  the panel with the message about wifi has no connect
            _ui_flag_modify(ui_Panel106, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);

        }
    }
}

void handle_out_ota_page()
{
    TaskHandle_t ota_task = xTaskGetHandle("ota_update");
    if(ota_task != NULL) 
    {
        vTaskDelete(ota_task);
    }
    // Handle UI of OTA Page
    if (!lv_obj_has_flag(ui_Panel104, LV_OBJ_FLAG_HIDDEN))
    {
        _ui_flag_modify(ui_Panel104, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
    if (!lv_obj_has_flag(ui_Panel102, LV_OBJ_FLAG_HIDDEN))
    {
        _ui_flag_modify(ui_Panel102, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
    if(!lv_obj_has_flag(ui_Panel93, LV_OBJ_FLAG_HIDDEN))
    {
        _ui_flag_modify(ui_Panel93, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
    if(!lv_obj_has_flag(ui_Panel106, LV_OBJ_FLAG_HIDDEN))
    {
        _ui_flag_modify(ui_Panel106, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}

void handle_start_ota()
{
    _ui_flag_modify(ui_Panel93, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    if (!lv_obj_has_flag(ui_Panel102, LV_OBJ_FLAG_HIDDEN))
    {
        _ui_flag_modify(ui_Panel102, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
    TaskHandle_t ota_task = xTaskGetHandle("ota_update");
    xTaskCreate(ota_update,"ota_update",8192,NULL,1,&ota_task);
}
