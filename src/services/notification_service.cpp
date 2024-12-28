#include "notification_service.h"
#include "esp_heap_caps.h"
// #include "esp_psram.h"
#include "../gui/ui.h"
#include "../utils/http.h"

void notification_service_init(void *parameter)
{
    for(;;)
    {
        // Checking does mutex is available
        if (xSemaphoreTake(lvgl_mutex,  pdMS_TO_TICKS(10)) == pdTRUE)
        {
                //TODO
            char serverURL[150]; // Adjust size if needed based on the URL length
            currentWateringHistoryPage = 1;
            snprintf(serverURL, sizeof(serverURL), "%s/api/v1/notification", web_server_official);
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
            JsonArray jsonArray = jsonDocGlobal.as<JsonArray>();
            int idx = 0;
            for (const char * message : jsonArray)
            {
                if(idx == 0)
                {
                    lv_label_set_text(ui_LabelNotificationItem1, message);
                    lv_obj_clear_flag(ui_PanelNotificationItem1, LV_OBJ_FLAG_HIDDEN);

                }
                else if(idx == 1)
                {
                    lv_label_set_text(ui_LabelNotificationItem2, message);
                    lv_obj_clear_flag(ui_PanelNotificationItem2, LV_OBJ_FLAG_HIDDEN);

                }
                else if(idx == 2)
                {
                    lv_label_set_text(ui_LabelNotificationItem3, message);
                    lv_obj_clear_flag(ui_PanelNotificationItem3, LV_OBJ_FLAG_HIDDEN);

                }
                else if(idx == 3)
                {
                    lv_label_set_text(ui_LabelNotificationItem4, message);
                    lv_obj_clear_flag(ui_PanelNotificationItem4, LV_OBJ_FLAG_HIDDEN);

                }
                else if(idx == 4)
                {
                    lv_label_set_text(ui_LabelNotificationItem5, message);   
                    lv_obj_clear_flag(ui_PanelNotificationItem5, LV_OBJ_FLAG_HIDDEN);
                }
                idx++;
                
            }
            lv_obj_add_flag(ui_PanelLoadingNotificationScreen, LV_OBJ_FLAG_HIDDEN);
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