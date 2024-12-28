#include "schedule_history.h"
#include "esp_heap_caps.h"
// #include "esp_psram.h"
#include "../gui/ui.h"
#include "../utils/http.h"



void initNavigateSchedulePage(int numberOfPage)
{

    if(numberOfPage >= 1)
    {
        lv_obj_clear_flag(ui_PanelItem1HeaderWateringHistory, LV_OBJ_FLAG_HIDDEN);
    }
    if(numberOfPage >= 2)
    {
        lv_obj_clear_flag(ui_PanelItem2HeaderWateringHistory, LV_OBJ_FLAG_HIDDEN);
    }
    if(numberOfPage >= 3)
    {
        lv_obj_clear_flag(ui_PanelItem3HeaderWateringHistory, LV_OBJ_FLAG_HIDDEN);
    }
    lv_obj_set_style_bg_color(ui_PanelItem1HeaderWateringHistory, lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelItem2HeaderWateringHistory, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelItem3HeaderWateringHistory, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    currentPage = 1;
    lv_task_handler();
}

void updateItem0(const char * schedule_name, int result, const char * Area, const char * start_time, const char * stop_time)
{
    lv_label_set_text(ui_LabelNameWateringHistoryItem1, schedule_name);
    const char * result_cstr;
    if (result == 1)
    {
        result_cstr = "SUCCESS";
    }
    else
    {
        result_cstr = "FAILED";
    }
    lv_label_set_text(ui_LabelResultWaterQuantityWateringHistoryItem1, result_cstr);
    lv_label_set_text(ui_LabelAreaWateringHistoryItem1, Area);
    lv_label_set_text(ui_LabelStartTimeWateringHistoryItem1, start_time);
    lv_label_set_text(ui_LabelEndTimeWateringHistoryItem1, stop_time);
}

void updateItem1(const char * schedule_name, int result, const char * Area, const char * start_time, const char * stop_time)
{
    lv_label_set_text(ui_LabelNameWateringHistoryItem2, schedule_name);
    const char * result_cstr;
    if (result == 1)
    {
        result_cstr = "SUCCESS";
    }
    else
    {
        result_cstr = "FAILED";
    }
    lv_label_set_text(ui_LabelResultWaterQuantityWateringHistoryItem2, result_cstr);
    lv_label_set_text(ui_LabelAreaWateringHistoryItem2, Area);
    lv_label_set_text(ui_LabelStartTimeWateringHistoryItem2, start_time);
    lv_label_set_text(ui_LabelEndTimeWateringHistoryItem2, stop_time);
}

void updateItem2(const char * schedule_name, int result, const char * Area, const char * start_time, const char * stop_time)
{
    lv_label_set_text(ui_LabelNameWateringHistoryItem3, schedule_name);
    const char * result_cstr;
    if (result == 1)
    {
        result_cstr = "SUCCESS";
    }
    else
    {
        result_cstr = "FAILED";
    }
    lv_label_set_text(ui_LabelResultWaterQuantityWateringHistoryItem3, result_cstr);
    lv_label_set_text(ui_LabelAreaWateringHistoryItem3, Area);
    lv_label_set_text(ui_LabelStartTimeWateringHistoryItem3, start_time);
    lv_label_set_text(ui_LabelEndTimeWateringHistoryItem3, stop_time);
}


void HistoryUI(void *parameter)
{
    for(;;)
    {
        // Checking does mutex is available
        if (xSemaphoreTake(lvgl_mutex,  pdMS_TO_TICKS(10)) == pdTRUE)
        {
            //TODO
            char serverURL[150]; // Adjust size if needed based on the URL length
            currentWateringHistoryPage = 1;
            snprintf(serverURL, sizeof(serverURL), "%s/api/v1/schedule-history?page=%d&limit=3", web_server_official, currentWateringHistoryPage);
            // Serial.println(serverURL); 
            String response = http_get_data(serverURL);
            jsonString = response;
            using SpiRamJsonDocument = BasicJsonDocument<SpiRamAllocator>;
            SpiRamJsonDocument jsonDocGlobal(1048576);

            DeserializationError error = deserializeJson(jsonDocGlobal, jsonString);
            if (error) 
            {
                Serial.println(error.c_str());
            }

            // Treat `jsonDocGlobal` as a JSON object since `total_pages` is at the top level
            JsonObject jsonObject = jsonDocGlobal.as<JsonObject>();
            JsonArray dataArray = jsonObject["data"].as<JsonArray>();
            totalWateringHistoryPage = jsonObject["total_pages"];
            initNavigateSchedulePage(totalWateringHistoryPage);

            //TODO
            int i = 0;
            for(JsonObject obj:dataArray)
            {
                const char * schedule_name = obj["schedule_name"].as<const char *>();
                const char *start_time = obj["start_time"].as<const char *>();
                const char *stop_time = obj["stop_time"].as<const char *>();
                int result = obj["result"].as<int>();
                const char * Area = obj["area"].as<const char *>();
                if(i == 0)
                {
                    updateItem0(schedule_name, result, Area, start_time, stop_time);
                }
                else if(i == 1)
                {
                    updateItem1(schedule_name, result, Area, start_time, stop_time);
                }
                else if(i == 2)
                {
                    updateItem2(schedule_name, result, Area, start_time, stop_time);
                }
                i++;
            }
            // End task handling    
            lv_obj_add_flag(ui_PanelLoadingWateringHistoryScreen, LV_OBJ_FLAG_HIDDEN);
            // Cleanup and free resources manually when you're done
            jsonDocGlobal.clear();  // Clear the JsonDocument to free memory
            jsonDocGlobal.shrinkToFit();  // Reduces the capacity to zero, if possible         
            xSemaphoreGive(lvgl_mutex);
            vTaskDelete(NULL);
        }
        else
        {
            print(PRINTLN, "mutex is not available. Waiting in the next time...");
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
    }
}