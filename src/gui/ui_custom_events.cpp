#include "ui_custom_events.h"
#include <M5Unified.h>
#include "../services/wifi_service.h"

uint32_t MY_LV_EVENT_MQTT_CONNECT_OK = lv_event_register_id();
uint32_t MY_LV_EVENT_MQTT_UPDATE_LABEL = lv_event_register_id();
uint32_t MY_LV_EVENT_MQTT_UPDATE_SWITCH = lv_event_register_id();
uint32_t MY_LV_EVENT_RTC_UPDATE_LABEL = lv_event_register_id();
uint32_t MY_LV_EVENT_WIFI_OFF = lv_event_register_id();
uint32_t MY_LV_EVENT_WIFI_ON = lv_event_register_id();
uint32_t MY_LV_EVENT_CHANGE_SCREEN = lv_event_register_id();
uint32_t MY_LV_EVENT_BACK_SCREEN = lv_event_register_id();
uint32_t MY_LV_EVENT_SCAN_WIFI = lv_event_register_id();

void mqtt_connect_ok_handler(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    uint8_t *data = (uint8_t *)e->param;
    Serial.printf("data = %d, pointer = %p, pointer to = %p\n", *data, &data, data);
    if (event_code == MY_LV_EVENT_MQTT_CONNECT_OK)
    {
        if (*data == 0)
        {
            _ui_screen_change(&ui_AppScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_AppScreen_screen_init);
            _ui_flag_modify(target, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
            _ui_flag_modify(ui_Panel42, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        }
        else if (*data == 1)
        {
            _ui_flag_modify(target, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
            _ui_screen_change(&ui_MqttScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_MqttScreen_screen_init);
        }
    }
    delete[] data;
}

void mqtt_update_handler(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    char *data = (char *)e->param;
    Serial.printf("data = %s, pointer = %p, pointer to = %p\n", data, &data, data);
    if (event_code == MY_LV_EVENT_MQTT_UPDATE_LABEL)
    {
        _ui_label_set_property(target, _UI_LABEL_PROPERTY_TEXT, data);
    }
    else if (event_code == MY_LV_EVENT_MQTT_UPDATE_SWITCH)
    {
        if (strcmp(data, "0") == 0)
        {
            _ui_state_modify(target, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
        }
        else if (strcmp(data, "1") == 0)
        {
            _ui_state_modify(target, LV_STATE_CHECKED, _UI_MODIFY_STATE_ADD);
        }
    }
    delete[] data;
}

void rtc_update_handler(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    char *data = (char *)e->param;
    Serial.printf("data = %s, pointer = %p, pointer to = %p\n", data, &data, data);
    if (event_code == MY_LV_EVENT_RTC_UPDATE_LABEL)
    {
        _ui_label_set_property(target, _UI_LABEL_PROPERTY_TEXT, data);
    }
    delete[] data;
}

void wifi_update_handler(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == MY_LV_EVENT_WIFI_OFF)
    {
        _ui_flag_modify(ui_Image2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
    else if (event_code == MY_LV_EVENT_WIFI_ON)
    {
        _ui_flag_modify(ui_Image2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}

void change_screen_handler(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t *target = lv_event_get_target(e);
    if (event_code == MY_LV_EVENT_CHANGE_SCREEN)
    {
        _ui_screen_change(&ui_MainScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_MainScreen_screen_init);
    }
}

void back_screen_handler(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t *target = lv_event_get_target(e);
    if (event_code == MY_LV_EVENT_BACK_SCREEN)
    {
        Serial.println("back screen handler");
        if (lv_scr_act() == ui_AppScreen)
        {
            _ui_screen_change(&ui_MainScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_MainScreen_screen_init);
        }
        else if (lv_scr_act() == ui_AboutScreen)
        {
            _ui_screen_change(&ui_AppScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_AppScreen_screen_init);
        }
        else if (lv_scr_act() == ui_MqttScreen)
        {
            _ui_screen_change(&ui_AppScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_AppScreen_screen_init);
        }
        else if (lv_scr_act() == ui_SettingsScreen)
        {
            _ui_screen_change(&ui_AppScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_AppScreen_screen_init);
        }
        else if (lv_scr_act() == ui_SensorsScreen)
        {
            _ui_screen_change(&ui_MqttScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_MqttScreen_screen_init);
        }
        else if (lv_scr_act() == ui_ManualScreen)
        {
            _ui_screen_change(&ui_MqttScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_MqttScreen_screen_init);
        }
        else if (lv_scr_act() == ui_WifiScreen)
        {
            _ui_screen_change(&ui_SettingsScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_SettingsScreen_screen_init);
        }
        else if (lv_scr_act() == ui_DisplayScreen)
        {
            _ui_screen_change(&ui_SettingsScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_SettingsScreen_screen_init);
        }
    }
}

void scan_wifi_handler(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    ListOfWifi *list_of_wifi = (ListOfWifi *)e->param;
    Serial.println("in scan wifi handler");
    // Serial.printf("data = %s, pointer = %p, pointer to = %p\n", data, &data, data);
    if (event_code == MY_LV_EVENT_SCAN_WIFI)
    {
        for (int i = 0; i < *list_of_wifi->number_of_wifi; i++) {
            Serial.printf("%s\n", list_of_wifi->name_of_wifi[i]);
        }
        // lv_obj_t * wifi_list = lv_btnmatrix_create(ui_Panel26);
        // lv_btnmatrix_set_map(wifi_list, list_of_wifi->name_of_wifi);
        // lv_obj_align(wifi_list, LV_ALIGN_CENTER, 0, 0);
    }
    
    for (int i = 0; i < *list_of_wifi->number_of_wifi; i++)
    {
        delete[] list_of_wifi->name_of_wifi[i];
    }
    delete[] list_of_wifi->name_of_wifi;
    delete list_of_wifi->number_of_wifi;
    delete list_of_wifi;
}