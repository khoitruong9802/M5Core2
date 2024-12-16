#include "threshold_service.h"
#include "esp_heap_caps.h"
#include "../gui/ui.h"
#include "../utils/http.h"

void handleThresHold(void *parameter)
{
    for(;;)
    {
        if (xSemaphoreTake(lvgl_mutex,  pdMS_TO_TICKS(10)) == pdTRUE)
        {
            int min_temperature = 0;
            int max_temperature = 0;
            int min_kali = 0;
            int max_kali = 0;
            int min_photpho = 0;
            int max_photpho = 0;
            int min_nito = 0;
            int max_nito = 0;
            char serverURL[150]; // Adjust size if needed based on the URL length
            snprintf(serverURL, sizeof(serverURL), "%s/api/v1/threshold", web_server_official);
            // Serial.println(serverURL);
            String response = http_get_data(serverURL);
            jsonString = response;

            using SpiRamJsonDocument = BasicJsonDocument<SpiRamAllocator>;
            SpiRamJsonDocument jsonDocGlobal(1048576);

            DeserializationError error = deserializeJson(jsonDocGlobal, response);
            if (error) 
            {
                Serial.println(error.c_str());
            }
            JsonArray jsonArray = jsonDocGlobal.as<JsonArray>();
            for(JsonObject obj : jsonArray)
            {
                int id = obj["id"];
                if(id == current_area_threshold)
                {
                    min_temperature = obj["min_temperature"];
                    max_temperature = obj["max_temperature"];
                    min_kali = obj["min_kali"];
                    max_kali = obj["max_kali"];
                    min_photpho = obj["min_photpho"];
                    max_photpho = obj["max_photpho"];
                    min_nito = obj["min_nito"];
                    max_nito = obj["max_nito"];
                    break;
                }
            }
            char buffer[10];
            itoa(min_temperature, buffer, 10 );
            const char *str = buffer;
            lv_label_set_text(ui_LabelTemperature1, str);

            itoa(max_temperature, buffer, 10 );
            str = buffer;
            lv_label_set_text(ui_LabelTemperature2, str);

            itoa(min_kali, buffer, 10 );
            str = buffer;
            lv_label_set_text(ui_LabelKali1, str);

            itoa(max_kali, buffer, 10 );
            str = buffer;
            lv_label_set_text(ui_LabelKali2, str);

            itoa(min_photpho, buffer, 10 );
            str = buffer;
            lv_label_set_text(ui_LabelPhotpho1, str);

            itoa(max_photpho, buffer, 10 );
            str = buffer;
            lv_label_set_text(ui_LabelPhotpho2, str);

            itoa(min_nito, buffer, 10 );
            str = buffer;
            lv_label_set_text(ui_LabelNito1, str);

            itoa(max_nito, buffer, 10 );
            str = buffer;
            lv_label_set_text(ui_LabelNito2, str);

            //print entire variable min max

            lv_obj_add_flag(ui_PanelLoadingThresHoldItem, LV_OBJ_FLAG_HIDDEN);
            lv_task_handler();
            response.clear();
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