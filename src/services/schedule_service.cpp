#include "schedule_service.h"
#include "esp_heap_caps.h"
// #include "esp_psram.h"
#include "../gui/ui.h"
#include "../utils/http.h"


void updateJsonGlobalArray()
{
    char serverURL[150]; // Adjust size if needed based on the URL length
    snprintf(serverURL, sizeof(serverURL), "%s/api/v1/fertilizer-device/1/schedule?page=%d&limit=3", web_server_official, currentPage);
    String response = http_get_data(serverURL);
    jsonString = "";
    jsonString = response;

}
int getMaxScheduleId()
{
    using SpiRamJsonDocument = BasicJsonDocument<SpiRamAllocator>;
    SpiRamJsonDocument jsonDocGlobal(1048576);

    DeserializationError error = deserializeJson(jsonDocGlobal, jsonString);   
    if (error) 
    {
        Serial.println(error.c_str());
    }

    // Access the JSON array
    JsonArray jsonArray = jsonDocGlobal.as<JsonArray>();
    int max_schedule_id = 0;
    // Get the schedule item data
    for(JsonObject obj : jsonArray) 
    {
        int schedule_id = obj["id"].as<int>();
        if (schedule_id > max_schedule_id)
        {
            max_schedule_id = schedule_id;
        }
    }
    // Cleanup and free resources manually when you're done
    jsonDocGlobal.clear();  // Clear the JsonDocument to free memory
    jsonDocGlobal.shrinkToFit();  // Reduces the capacity to zero, if possible   
    return max_schedule_id;   

}
static void ScheduleItem_Dropdown_handle(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    char buf[64];
    lv_dropdown_get_selected_str(obj, buf, sizeof(buf));
    lv_dropdown_set_text(obj, buf);
}

void renderScheduleItemUI(
    int schedule_id,
    const char * schedule_name,
    const char * description,
    uint16_t area,
    uint16_t priority,
    const char * flow1,
    const char * flow2,
    const char * flow3,
    const char * schedule_type,
    const char * schedule_start_time,
    const char * schedule_stop_time,
    const char * schedule_start_day,
    const char * schedule_end_day,
    int days_list[7],
    int days_count
)
{
    // Generate UI for Schedule Item Screen
    char buffer[20];           // Ensure buffer is large enough to hold the string representation
    itoa(schedule_id, buffer, 10);     // Convert the int to a string (base 10)
    const char *str = buffer;
    lv_label_set_text(ui_LabelNameScheduleItem, schedule_name);
    lv_label_set_text(ui_LabelDescriptionScheduleItem, description);
    lv_dropdown_set_selected(ui_DropdownAreaScheduleItem, area);
    lv_slider_set_value(ui_SliderPriorityScheduleItem, priority, LV_ANIM_OFF);

    lv_label_set_text(ui_LabelFlow1ScheduleItem, flow1);
    lv_label_set_text(ui_LabelFlow2ScheduleItem, flow2);
    lv_label_set_text(ui_LabelFlow3ScheduleItem, flow3);
    lv_label_set_text(ui_LabelScheduleStartTimeScheduleItem, schedule_start_time);
    lv_label_set_text(ui_LabelScheduleEndTimeScheduleItem, schedule_stop_time);
    uint16_t type_idx = 0;
    if (strcmp(schedule_type, "Once") == 0) 
    {
        type_idx = 0;
        lv_obj_clear_flag(ui_PanelScheduleDateContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_add_flag(ui_PanelScheduleStartDateContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_add_flag(ui_PanelScheduleEndDateContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_add_flag(ui_PanelScheduleWeekContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
    } 
    else if (strcmp(schedule_type, "Daily") == 0) 
    {
        type_idx = 1;
        lv_obj_add_flag(ui_PanelScheduleDateContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelScheduleStartDateContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelScheduleEndDateContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_add_flag(ui_PanelScheduleWeekContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
    } 
    else if (strcmp(schedule_type, "Weekly") == 0) 
    {
        type_idx = 2;
        lv_obj_add_flag(ui_PanelScheduleDateContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelScheduleStartDateContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelScheduleEndDateContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelScheduleWeekContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
    }
    lv_dropdown_set_selected(ui_DropdownScheduleRepeatScheduleItem, type_idx);
    lv_label_set_text(ui_LabelScheduleDateScheduleItem, schedule_start_day);
    lv_label_set_text(ui_LabelScheduleStartDateScheduleItem, schedule_start_day);
    lv_label_set_text(ui_LabelScheduleEndDateScheduleItem, schedule_end_day);

    for(int i = 0; i < days_count; i++) 
    {
        if(days_list[i] == 2)
        {
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemMondayScheduleItem, lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else if(days_list[i] == 3)
        {
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemTuesdayScheduleItem, lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else if(days_list[i] == 4)
        {
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemWednesdayScheduleItem, lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else if(days_list[i] == 5)
        {
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemThursdayScheduleItem, lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else if(days_list[i] == 6)
        {
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemFridayScheduleItem, lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else if(days_list[i] == 7)
        {
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemSaturdayScheduleItem, lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else if(days_list[i] == 8)
        {
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemSundayScheduleItem, lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    lv_task_handler();
    
}

void handleScheduleItemUI(void * parameter)
{
    // Get the schedule item
    int schedule_id = (int)(uintptr_t)parameter;
    current_schedule_id = schedule_id;
    for(;;)
    {
        // Checking does mutex is available
        if (xSemaphoreTake(lvgl_mutex,  pdMS_TO_TICKS(10)) == pdTRUE)
        {
            const char * schedule_name;
            const char * description;
            uint16_t area;
            uint16_t priority;
            const char * flow1;
            const char * flow2;
            const char * flow3;
            const char * schedule_type;
            const char * schedule_start_time;
            const char * schedule_stop_time;
            const char * schedule_start_day;
            const char * schedule_end_day;
            int days_list[7];
            int days_count = 0; 
            // Get the schedule item data
            using SpiRamJsonDocument = BasicJsonDocument<SpiRamAllocator>;
            SpiRamJsonDocument jsonDocGlobal(1048576);

            DeserializationError error = deserializeJson(jsonDocGlobal, jsonString);
            if (error) 
            {
            Serial.println(error.c_str());
            }

            // Access the JSON array
            JsonObject jsonObject = jsonDocGlobal.as<JsonObject>();
            JsonArray dataArray = jsonObject["data"].as<JsonArray>();
            if(schedule_id == -1)
            {
                schedule_name = "";
                description = "";
                area = 0;
                priority = 0;
                flow1 = "";
                flow2 = "";
                flow3 = "";
                schedule_type = "Once";
                schedule_start_time = "08:00";
                schedule_stop_time = "09:00";
                //Handle for day by getting current time
                uint16_t year = (uint16_t)get_current_year();
                uint16_t month = (uint16_t)get_current_month();
                uint16_t day = (uint16_t)get_current_day();
                schedule_start_day = formatDate(year, month, day);
                schedule_end_day = schedule_start_day;
            }
            else
            {
                // Get the schedule item data
                for(JsonObject obj : dataArray) 
                {
                    int id = obj["id"];
                    if(schedule_id == id) 
                    {
                        // Extracting other values as you did previously with null checks.
                        
                        // Check if schedule_name key is not null
                        if (obj["description"].is<const char*>())
                        {
                            schedule_name = obj["schedule_name"].as<const char*>();
                        }
                        else
                        {
                            schedule_name = " ";
                        }
                        
                        
                        // Check if description key is not null
                        if (obj["description"].is<const char*>())
                        {
                            description = obj["description"].as<const char*>();
                        } else {
                            description = " ";
                        }

                        // Extract area
                        if (obj["area"].is<int>())
                        {
                            area = obj["area"].as<int>() - 1;
                        } else {
                            area = 0;  // Indicate that the area value is missing or invalid
                        }

                        // Extract priority
                        if (obj["priority"].is<int>())
                        {
                            priority = obj["priority"].as<uint16_t>() - 1;
                        } else {
                            priority = 0;  // Default value or handle appropriately
                        }

                        // Extract flow1
                        if (obj["flow1"].is<int>())
                        {
                            int flow1_int = obj["flow1"].as<int>();
                            char buffer[10];
                            itoa(flow1_int, buffer, 10 );
                            flow1 = buffer;
                        } else {
                            flow1 = " ";  // Set default or handle appropriately
                        }

                        // Extract flow 2
                        if (obj["flow2"].is<int>())
                        {
                            int flow2_int = obj["flow2"].as<int>();
                            char buffer[10];
                            itoa(flow2_int, buffer, 10 );
                            flow2 = buffer;
                        } else {
                            flow2 = " ";  // Set default or handle appropriately
                        }

                        // Extract flow 3
                        if (obj["flow3"].is<int>())
                        {
                            int flow3_int = obj["flow3"].as<int>();
                            char buffer[10];
                            itoa(flow3_int, buffer, 10 );
                            flow3 = buffer;
                        } else 
                        {
                            flow3 = " ";  // Set default or handle appropriately
                        }

                        // Check each element in the schedule to avoid null pointers
                        if (obj["start_time"].is<const char*>())
                        {
                            schedule_start_time = obj["start_time"].as<const char*>();
                        } else 
                        {
                            schedule_start_time = " ";
                        }
                        if (obj["stop_time"].is<const char*>())
                        {
                            schedule_stop_time = obj["stop_time"].as<const char*>();
                        } else 
                        {
                            schedule_stop_time = " ";
                        }

                        if (obj["schedule_type"].is<const char*>())
                        {
                            schedule_type = obj["schedule_type"].as<const char*>();
                        } else 
                        {
                            schedule_type = " ";
                        }

                        if (obj["start_day"].is<const char*>())
                        {
                            schedule_start_day = obj["start_day"].as<const char*>();
                        } else 
                        {
                            schedule_start_day = " ";
                        }

                        if (obj["end_day"].is<const char*>())
                        {
                            schedule_end_day = obj["end_day"].as<const char*>();
                        } else 
                        {
                            schedule_end_day = " ";
                        }

                        // Extract the "days" array inside the "schedule" object, if it exists
                        if (obj["days"].is<JsonArray>())
                        {
                            JsonArray daysArray = obj["days"].as<JsonArray>();

                            // Clear the `days_list` and reset the counter
                            days_count = 0;

                            // Iterate over the "days" array and store the values in `days_list`
                            for (int day : daysArray)
                            {
                                if (days_count < 7)
                                { // Ensure we don't exceed our array size
                                    days_list[days_count] = day;
                                    days_count++;
                                }
                            }
                        } else 
                        {
                            days_count = 0; // No days available
                        }

                        break;  // Exit the loop once the desired object is found.
                    }
                }        
            }
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemMondayScheduleItem, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemTuesdayScheduleItem, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemWednesdayScheduleItem, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemThursdayScheduleItem, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemFridayScheduleItem, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemSaturdayScheduleItem, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemSundayScheduleItem, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_task_handler();
            renderScheduleItemUI(schedule_id, schedule_name, description, area, priority, flow1, flow2, flow3, schedule_type, schedule_start_time, schedule_stop_time, schedule_start_day, schedule_end_day, days_list, days_count);
            lv_obj_add_flag(ui_PanelLoadingScheduleItemScreen, LV_OBJ_FLAG_HIDDEN);
            lv_task_handler();
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

void ScheduleItemContainerClickedHandler(int schedule_id)
{
    // You could use the schedule ID to pull the detailed information from memory, 
    // for example, fetching from an array or JSON data stored locally.

    // Call a function to display the detailed information screen
    lv_obj_clear_flag(ui_PanelLoadingScheduleItemScreen, LV_OBJ_FLAG_HIDDEN);
    lv_obj_scroll_to_y(ui_PanelScheduleItemContainerScreen, 0, LV_ANIM_OFF);
    _ui_screen_change(&ui_scheduleItemScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_ScheduleItemScreen_screen_init);
    lv_task_handler();
    TaskHandle_t scheItem_task = xTaskGetHandle("scheItem_task");
    if(scheItem_task == NULL)
    {
        xTaskCreate(handleScheduleItemUI, "scheItem_task", 8192, (void *)(uintptr_t)schedule_id, 1, &scheItem_task);
    }
}

static void ui_event_PanelScheduleItemContainer0Clicked(lv_event_t * e)
{
    lv_obj_t * panel = lv_event_get_target(e);
    // Get the schedule ID or metadata associated with this panel
    int schedule_id = jsonScheduleItemList[0].schedule_id;
    ScheduleItemContainerClickedHandler(schedule_id);
}

static void ui_event_PanelScheduleItemContainer1Clicked(lv_event_t * e)
{
    lv_obj_t * panel = lv_event_get_target(e);
    // Get the schedule ID or metadata associated with this panel
    int schedule_id = jsonScheduleItemList[1].schedule_id;

    ScheduleItemContainerClickedHandler(schedule_id);
}

static void ui_event_PanelScheduleItemContainer2Clicked(lv_event_t * e)
{
    lv_obj_t * panel = lv_event_get_target(e);
    // Get the schedule ID or metadata associated with this panel
    int schedule_id = jsonScheduleItemList[2].schedule_id;

    ScheduleItemContainerClickedHandler(schedule_id);
}

static void ui_event_PanelScheduleItemContainer3Clicked(lv_event_t * e)
{
    lv_obj_t * panel = lv_event_get_target(e);
    // Get the schedule ID or metadata associated with this panel
    int schedule_id = jsonScheduleItemList[3].schedule_id;

    ScheduleItemContainerClickedHandler(schedule_id);
}

static void ui_event_PanelScheduleItemContainer4Clicked(lv_event_t * e)
{
    lv_obj_t * panel = lv_event_get_target(e);
    // Get the schedule ID or metadata associated with this panel
    int schedule_id = jsonScheduleItemList[4].schedule_id;

    ScheduleItemContainerClickedHandler(schedule_id);
}

void SwitchScheduleItemHandler(int idx)
{
    lv_state_t state = lv_obj_get_state(jsonScheduleItemList[idx].ui_SwitchScheduleItem);
    
    // Get the schedule ID or metadata associated with this panel
    int schedule_id = jsonScheduleItemList[idx].schedule_id;
    StaticJsonDocument<1024> jsonPayloadDoc;
    if (state & LV_STATE_CHECKED) 
    {
        jsonPayloadDoc["status"] = 1;
    } 
    else 
    {
        jsonPayloadDoc["status"] = 0;
    }   
    // get web server
    char serverURL[150]; // Adjust size if needed based on the URL length
    snprintf(serverURL, sizeof(serverURL), "%s/api/v1/schedule/%d", web_server_official, schedule_id);
    // Serial.println(serverURL);
    
    String jsonPayload;
    serializeJson(jsonPayloadDoc, jsonPayload);
    sendPutRequest(serverURL, jsonPayload.c_str());
}

static void ui_event_SwitchScheduleItemContainer0Clicked(lv_event_t * e)
{
    SwitchScheduleItemHandler(0);
}

static void ui_event_SwitchScheduleItemContainer1Clicked(lv_event_t * e)
{
    SwitchScheduleItemHandler(1);
}

static void ui_event_SwitchScheduleItemContainer2Clicked(lv_event_t * e)
{
    SwitchScheduleItemHandler(2);
}


void updateFromScheduleItem (void *parameter)
{
    char serverURL[150]; // Adjust size if needed based on the URL length
    snprintf(serverURL, sizeof(serverURL), "%s/api/v1/fertilizer-device/1/schedule?page=%d&limit=3", web_server_official, currentPage);
    String response = http_get_data(serverURL);

    using SpiRamJsonDocument = BasicJsonDocument<SpiRamAllocator>;
    jsonString = response;
    SpiRamJsonDocument jsonDocGlobal(1048576);

    DeserializationError error = deserializeJson(jsonDocGlobal, jsonString);
    if (error) 
    {
    Serial.println(error.c_str());
    }
    lv_task_handler();
    // Access the JSON array
    JsonObject jsonObject = jsonDocGlobal.as<JsonObject>();
    int total_pages = jsonObject["total_pages"].as<int>();

    if(numberOfPage != total_pages)
    {
        numberOfPage = total_pages;
        if(currentPage > numberOfPage)
        {
            // Hidden all objects
            lv_obj_add_flag(ui_PanelPageItemTitleScheduleScreen[0], LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_PanelPageItemTitleScheduleScreen[1], LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_PanelPageItemTitleScheduleScreen[2], LV_OBJ_FLAG_HIDDEN);
            currentPage = currentPage - 1;
            int idx_current_page = currentPage % 3;
            if(idx_current_page == 0)
            {
                lv_obj_clear_flag(ui_PanelPageItemTitleScheduleScreen[0], LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(ui_PanelPageItemTitleScheduleScreen[1], LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(ui_PanelPageItemTitleScheduleScreen[2], LV_OBJ_FLAG_HIDDEN);
                lv_obj_set_style_bg_color(ui_PanelPageItemTitleScheduleScreen[0], lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(ui_PanelPageItemTitleScheduleScreen[1], lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(ui_PanelPageItemTitleScheduleScreen[2], lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
                char buffer[20];           // Ensure buffer is large enough to hold the string representation
                itoa(currentPage, buffer, 10);     // Convert the int to a string (base 10)
                const char *str = buffer;  // Now 'str' is a const char* pointing to the string
                lv_label_set_text(ui_LabelPageItemTitleScheduleScreen[2], str);
                itoa((currentPage - 1), buffer, 10);     // Convert the int to a string (base 10)
                str = buffer;  // Now 'str' is a const char* pointing to the string
                lv_label_set_text(ui_LabelPageItemTitleScheduleScreen[1], str);
                itoa((currentPage - 2), buffer, 10);     // Convert the int to a string (base 10)
                str = buffer;  // Now 'str' is a const char* pointing to the string
                lv_label_set_text(ui_LabelPageItemTitleScheduleScreen[0], str);
                
            }
            else if(idx_current_page == 1)
            {
                lv_obj_clear_flag(ui_PanelPageItemTitleScheduleScreen[0], LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_PanelPageItemTitleScheduleScreen[1], LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_PanelPageItemTitleScheduleScreen[2], LV_OBJ_FLAG_HIDDEN);
                lv_obj_set_style_bg_color(ui_PanelPageItemTitleScheduleScreen[0], lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(ui_PanelPageItemTitleScheduleScreen[1], lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(ui_PanelPageItemTitleScheduleScreen[2], lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);            
            }
            else if(idx_current_page == 2)
            {
                Serial.println("a3");
                lv_obj_clear_flag(ui_PanelPageItemTitleScheduleScreen[0], LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(ui_PanelPageItemTitleScheduleScreen[1], LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_PanelPageItemTitleScheduleScreen[2], LV_OBJ_FLAG_HIDDEN);
                lv_obj_set_style_bg_color(ui_PanelPageItemTitleScheduleScreen[0], lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(ui_PanelPageItemTitleScheduleScreen[1], lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(ui_PanelPageItemTitleScheduleScreen[2], lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);            
            }
            lv_task_handler();
        }
        else
        {
            int idx_flag = currentPage % 3;
            if(idx_flag == 1)
            {
                if(numberOfPage - currentPage < 2)
                {
                    lv_obj_add_flag(ui_PanelPageItemTitleScheduleScreen[0], LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_PanelPageItemTitleScheduleScreen[1], LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_PanelPageItemTitleScheduleScreen[2], LV_OBJ_FLAG_HIDDEN);
                    for(int i = currentPage; i <= numberOfPage; i++)
                    {
                        int index = (i % 3) - 1;
                        lv_obj_clear_flag(ui_PanelPageItemTitleScheduleScreen[index], LV_OBJ_FLAG_HIDDEN);
                    }                
                }
            }
            else if(idx_flag == 2)
            {
                if(numberOfPage - currentPage < 1)
                {
                    lv_obj_add_flag(ui_PanelPageItemTitleScheduleScreen[2], LV_OBJ_FLAG_HIDDEN);             
                }                
            }
        }
    }

    for(;;)
    {
        print(PRINTLN, "Schedule UI task is running!"); 
        // Checking does mutex is available
        if (xSemaphoreTake(lvgl_mutex,  pdMS_TO_TICKS(10)) == pdTRUE)
        {
            updatePageScheduleItem(currentPage);
            lv_obj_add_flag(ui_PanelLoadingScheduleScreen, LV_OBJ_FLAG_HIDDEN);
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

void removeButtonHandler(int index)
{
    lv_state_t state = lv_obj_get_state(jsonScheduleItemList[index].ui_ButtonRemoveScheduleListItem);
    // Get the schedule ID or metadata associated with this panel
    int schedule_id = jsonScheduleItemList[index].schedule_id;

    
    sendDeleteRequest(schedule_id);

    lv_obj_clear_flag(ui_PanelLoadingScheduleScreen, LV_OBJ_FLAG_HIDDEN);
    _ui_screen_change(&ui_ScheduleScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_ScheduleScreen_screen_init);
    lv_task_handler();
    TaskHandle_t schedule_task = xTaskGetHandle("schedule_task");
    if(schedule_task == NULL)
    {
        void *taskStackMemory = heap_caps_malloc(8192, MALLOC_CAP_SPIRAM); // Allocating in PSRAM

        if (taskStackMemory != nullptr)
        {
            BaseType_t result = xTaskCreatePinnedToCore(
                updateFromScheduleItem,  // Function to execute
                "schedule_task",   // Task name
                8192,              // Stack size in bytes
                NULL,              // Task parameter
                1,                 // Priority
                &schedule_task,    // Task handle
                1                  // Core
            );

            if (result == pdPASS)
{
                Serial.println("Task created successfully in PSRAM.");
            } else {
                Serial.println("Failed to create task.");
                free(taskStackMemory); // Free memory if task creation failed
            }
        } else {
            Serial.println("Failed to allocate memory for the task stack in PSRAM.");
        }
    }
}

static void ui_event_ButtonRemoveScheduleItemContainer0Clicked(lv_event_t * e)
{
    removeButtonHandler(0);
}

static void ui_event_ButtonRemoveScheduleItemContainer1Clicked(lv_event_t * e)
{
    removeButtonHandler(1);
}

static void ui_event_ButtonRemoveScheduleItemContainer2Clicked(lv_event_t * e)
{
    removeButtonHandler(2);
}

static void ui_event_ButtonRemoveScheduleItemContainer3Clicked(lv_event_t * e)
{
    removeButtonHandler(3);
}

static void ui_event_ButtonRemoveScheduleItemContainer4Clicked(lv_event_t * e)
{
    removeButtonHandler(4);
}

void renderNavigateSchedulePage(int numberOfPage)
{
    for(int i = 0; i < numberOfPage && i < 3; i++)
    {
        int num = i + 1;
        char buffer[20];           // Ensure buffer is large enough to hold the string representation
        itoa(num, buffer, 10);     // Convert the int to a string (base 10)
        const char *str = buffer;  // Now 'str' is a const char* pointing to the string
        lv_label_set_text(ui_LabelPageItemTitleScheduleScreen[i], str);
        lv_obj_clear_flag(ui_PanelPageItemTitleScheduleScreen[i], LV_OBJ_FLAG_HIDDEN);
    }
    lv_obj_set_style_bg_color(ui_PanelPageItemTitleScheduleScreen[0], lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelPageItemTitleScheduleScreen[1], lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelPageItemTitleScheduleScreen[2], lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    currentPage = 1;
    lv_task_handler();
}


void renderScheduleUI(int index, int id, const char * name, const char *time, int priority, const char * schedule_type, int schedule_status) 
{  
    jsonScheduleItemList[index].schedule_id = id;
    
    jsonScheduleItemList[index].ui_PanelScheduleItemContainer = lv_obj_create(ui_ScheduleContainer);
    lv_obj_set_width(jsonScheduleItemList[index].ui_PanelScheduleItemContainer, 300);
    lv_obj_set_height(jsonScheduleItemList[index].ui_PanelScheduleItemContainer, 90);
    lv_obj_set_align(jsonScheduleItemList[index].ui_PanelScheduleItemContainer, LV_ALIGN_CENTER);
    lv_obj_clear_flag(jsonScheduleItemList[index].ui_PanelScheduleItemContainer, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(jsonScheduleItemList[index].ui_PanelScheduleItemContainer, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(jsonScheduleItemList[index].ui_PanelScheduleItemContainer, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(jsonScheduleItemList[index].ui_PanelScheduleItemContainer, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(jsonScheduleItemList[index].ui_PanelScheduleItemContainer, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    jsonScheduleItemList[index].ui_PanelScheduleItem = lv_obj_create(jsonScheduleItemList[index].ui_PanelScheduleItemContainer);
    lv_obj_set_width(jsonScheduleItemList[index].ui_PanelScheduleItem, 285);
    lv_obj_set_height(jsonScheduleItemList[index].ui_PanelScheduleItem, 80);
    lv_obj_set_x(jsonScheduleItemList[index].ui_PanelScheduleItem, 0);
    lv_obj_set_y(jsonScheduleItemList[index].ui_PanelScheduleItem, 0);
    lv_obj_set_align(jsonScheduleItemList[index].ui_PanelScheduleItem, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(jsonScheduleItemList[index].ui_PanelScheduleItem, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(jsonScheduleItemList[index].ui_PanelScheduleItem, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(jsonScheduleItemList[index].ui_PanelScheduleItem, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(jsonScheduleItemList[index].ui_PanelScheduleItem, lv_color_hex(0xC8C8C8), LV_PART_MAIN | LV_STATE_PRESSED); //Light Gray
    lv_obj_set_style_bg_opa(jsonScheduleItemList[index].ui_PanelScheduleItem, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    jsonScheduleItemList[index].ui_LabelScheduleItem = lv_label_create(jsonScheduleItemList[index].ui_PanelScheduleItem);
    lv_obj_set_width(jsonScheduleItemList[index].ui_LabelScheduleItem, 60);   /// 1
    lv_obj_set_height(jsonScheduleItemList[index].ui_LabelScheduleItem, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(jsonScheduleItemList[index].ui_LabelScheduleItem, LV_ALIGN_CENTER);
    lv_label_set_text(jsonScheduleItemList[index].ui_LabelScheduleItem, time);
    lv_obj_set_style_text_font(jsonScheduleItemList[index].ui_LabelScheduleItem, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    jsonScheduleItemList[index].ui_PanelScheduleItemIngredientPriority = lv_obj_create(jsonScheduleItemList[index].ui_PanelScheduleItem);
    lv_obj_set_width(jsonScheduleItemList[index].ui_PanelScheduleItemIngredientPriority, 75);
    lv_obj_set_height(jsonScheduleItemList[index].ui_PanelScheduleItemIngredientPriority, 50);
    lv_obj_set_x(jsonScheduleItemList[index].ui_PanelScheduleItemIngredientPriority, 2);
    lv_obj_set_y(jsonScheduleItemList[index].ui_PanelScheduleItemIngredientPriority, 0);
    lv_obj_set_align(jsonScheduleItemList[index].ui_PanelScheduleItemIngredientPriority, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(jsonScheduleItemList[index].ui_PanelScheduleItemIngredientPriority, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(jsonScheduleItemList[index].ui_PanelScheduleItemIngredientPriority, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_SPACE_EVENLY);
    lv_obj_clear_flag(jsonScheduleItemList[index].ui_PanelScheduleItemIngredientPriority, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_opa(jsonScheduleItemList[index].ui_PanelScheduleItemIngredientPriority, LV_OPA_TRANSP, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(jsonScheduleItemList[index].ui_PanelScheduleItemIngredientPriority, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(jsonScheduleItemList[index].ui_PanelScheduleItemIngredientPriority, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(jsonScheduleItemList[index].ui_PanelScheduleItemIngredientPriority, LV_OPA_TRANSP, LV_PART_MAIN | LV_STATE_DEFAULT); //set object to transparent color


    const char * priority_ctr = convertPriorityToCstr(priority);    
    jsonScheduleItemList[index].ui_LabelScheduleItemPriority = lv_label_create(jsonScheduleItemList[index].ui_PanelScheduleItemIngredientPriority);
    lv_obj_set_width(jsonScheduleItemList[index].ui_LabelScheduleItemPriority, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(jsonScheduleItemList[index].ui_LabelScheduleItemPriority, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(jsonScheduleItemList[index].ui_LabelScheduleItemPriority, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(jsonScheduleItemList[index].ui_LabelScheduleItemPriority, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(jsonScheduleItemList[index].ui_LabelScheduleItemPriority, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_text(jsonScheduleItemList[index].ui_LabelScheduleItemPriority, priority_ctr);

    jsonScheduleItemList[index].ui_LabelScheduleItemTimer = lv_label_create(jsonScheduleItemList[index].ui_PanelScheduleItem);
    lv_obj_set_width(jsonScheduleItemList[index].ui_LabelScheduleItemTimer, 75);   /// 1
    lv_obj_set_height(jsonScheduleItemList[index].ui_LabelScheduleItemTimer, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(jsonScheduleItemList[index].ui_LabelScheduleItemTimer, LV_ALIGN_CENTER);
    lv_label_set_text(jsonScheduleItemList[index].ui_LabelScheduleItemTimer, schedule_type);
    lv_obj_set_style_text_font(jsonScheduleItemList[index].ui_LabelScheduleItemTimer, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);


    jsonScheduleItemList[index].ui_SwitchScheduleItem = lv_switch_create(jsonScheduleItemList[index].ui_PanelScheduleItem);
    lv_obj_add_state(jsonScheduleItemList[index].ui_SwitchScheduleItem, schedule_status == 1 ? LV_STATE_CHECKED : LV_STATE_DEFAULT);
    lv_obj_set_width(jsonScheduleItemList[index].ui_SwitchScheduleItem, 70);
    lv_obj_set_height(jsonScheduleItemList[index].ui_SwitchScheduleItem, 35);
    lv_obj_set_align(jsonScheduleItemList[index].ui_SwitchScheduleItem, LV_ALIGN_CENTER);
    // lv_obj_add_flag(jsonScheduleItemList[index].ui_SwitchScheduleItem, LV_OBJ_FLAG_HIDDEN);

    jsonScheduleItemList[index].ui_ButtonRemoveScheduleListItem = lv_btn_create(jsonScheduleItemList[index].ui_PanelScheduleItem);
    lv_obj_set_width(jsonScheduleItemList[index].ui_ButtonRemoveScheduleListItem, 50);
    lv_obj_set_height(jsonScheduleItemList[index].ui_ButtonRemoveScheduleListItem, 50);
    lv_obj_set_x(jsonScheduleItemList[index].ui_ButtonRemoveScheduleListItem, 110);
    lv_obj_set_y(jsonScheduleItemList[index].ui_ButtonRemoveScheduleListItem, 0);
    lv_obj_set_align(jsonScheduleItemList[index].ui_ButtonRemoveScheduleListItem, LV_ALIGN_CENTER);
    lv_obj_add_flag(jsonScheduleItemList[index].ui_ButtonRemoveScheduleListItem, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(jsonScheduleItemList[index].ui_ButtonRemoveScheduleListItem, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(jsonScheduleItemList[index].ui_ButtonRemoveScheduleListItem, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(jsonScheduleItemList[index].ui_ButtonRemoveScheduleListItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(jsonScheduleItemList[index].ui_ButtonRemoveScheduleListItem, &ui_img_trash_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(jsonScheduleItemList[index].ui_ButtonRemoveScheduleListItem, LV_OBJ_FLAG_HIDDEN);

    jsonScheduleItemList[index].ui_LabelNameScheduleListItem = lv_label_create(jsonScheduleItemList[index].ui_PanelScheduleItemContainer);
    lv_obj_set_width(jsonScheduleItemList[index].ui_LabelNameScheduleListItem, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(jsonScheduleItemList[index].ui_LabelNameScheduleListItem, LV_SIZE_CONTENT);    /// 1
    lv_label_set_text(jsonScheduleItemList[index].ui_LabelNameScheduleListItem, name);
    lv_obj_set_style_text_color(jsonScheduleItemList[index].ui_LabelNameScheduleListItem, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(jsonScheduleItemList[index].ui_LabelNameScheduleListItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(jsonScheduleItemList[index].ui_LabelNameScheduleListItem, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    if(index == 0)
    {
        lv_obj_add_event_cb(jsonScheduleItemList[0].ui_PanelScheduleItem , ui_event_PanelScheduleItemContainer0Clicked, LV_EVENT_CLICKED, NULL);
        lv_obj_add_event_cb(jsonScheduleItemList[0].ui_SwitchScheduleItem , ui_event_SwitchScheduleItemContainer0Clicked, LV_EVENT_CLICKED, NULL);
        lv_obj_add_event_cb(jsonScheduleItemList[0].ui_ButtonRemoveScheduleListItem , ui_event_ButtonRemoveScheduleItemContainer0Clicked, LV_EVENT_CLICKED, NULL);
    }
    else
    if(index == 1)
    {
        lv_obj_add_event_cb(jsonScheduleItemList[1].ui_PanelScheduleItem , ui_event_PanelScheduleItemContainer1Clicked, LV_EVENT_CLICKED, NULL);
        lv_obj_add_event_cb(jsonScheduleItemList[1].ui_SwitchScheduleItem , ui_event_SwitchScheduleItemContainer1Clicked, LV_EVENT_CLICKED, NULL);
        lv_obj_add_event_cb(jsonScheduleItemList[1].ui_ButtonRemoveScheduleListItem , ui_event_ButtonRemoveScheduleItemContainer1Clicked, LV_EVENT_CLICKED, NULL);
    }
    else
    if(index == 2)
    {
        lv_obj_add_event_cb(jsonScheduleItemList[2].ui_PanelScheduleItem , ui_event_PanelScheduleItemContainer2Clicked, LV_EVENT_CLICKED, NULL);
        lv_obj_add_event_cb(jsonScheduleItemList[2].ui_SwitchScheduleItem , ui_event_SwitchScheduleItemContainer2Clicked, LV_EVENT_CLICKED, NULL);
        lv_obj_add_event_cb(jsonScheduleItemList[2].ui_ButtonRemoveScheduleListItem , ui_event_ButtonRemoveScheduleItemContainer2Clicked, LV_EVENT_CLICKED, NULL);
    }
}


void handleScheduleUI(void *parameter)
{
    for(;;)
    {
        // Checking does mutex is available
        if (xSemaphoreTake(lvgl_mutex,  pdMS_TO_TICKS(10)) == pdTRUE)
        {

            currentPage = 1;
            char serverURL[150]; // Adjust size if needed based on the URL length
            snprintf(serverURL, sizeof(serverURL), "%s/api/v1/fertilizer-device/1/schedule?page=%d&limit=3", web_server_official, currentPage);
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

            // Treat `jsonDocGlobal` as a JSON object since `total_pages` is at the top level
            JsonObject jsonObject = jsonDocGlobal.as<JsonObject>();
            numberOfElement = jsonObject["total_count"];
            numberOfPage = jsonObject["total_pages"];
            renderNavigateSchedulePage(numberOfPage);
            if(lv_obj_is_valid(ui_ScheduleContainer) == true)
            {
                JsonArray dataArray = jsonObject["data"].as<JsonArray>();
                lv_obj_t *child = lv_obj_get_child(ui_ScheduleContainer, 0);
                if(child == NULL)
                {
                    int i = 0;
                    for(JsonObject obj : dataArray)
                    {
                        const char * name = obj["schedule_name"].as<const char *>();
                        int id = obj["id"].as<int>();
                        const char *time_draft = obj["start_time"].as<const char *>();
                        const char * time = convertTimeToHHMM(time_draft);
                        int priority = obj["priority"].as<int>();
                        const char * schedule_type = obj["schedule_type"].as<const char *>();
                        int schedule_status = obj["status"].as<int>();
                        // TO DO
                        renderScheduleUI(i, id, name, time, priority, schedule_type, schedule_status);
                        i++;
                    }
                }
                else
                {
                    updateItemforScheduleScreen(true, 0);
                    int i = 0;
                    for(JsonObject obj : dataArray)
                    {
                        if(i < 3)
                        {
                            const char * name = obj["schedule_name"].as<const char *>();
                            int id = obj["id"].as<int>();
                            const char *time_draft = obj["start_time"].as<const char *>();
                            const char * time = convertTimeToHHMM(time_draft);
                            int priority = obj["priority"].as<int>();
                            const char * schedule_type = obj["schedule_type"].as<const char *>();
                            int schedule_status = obj["status"].as<int>();
                            // TO DO
                            jsonScheduleItemList[i].schedule_id = id;
                            lv_label_set_text(jsonScheduleItemList[i].ui_LabelNameScheduleListItem, name);
                            lv_label_set_text(jsonScheduleItemList[i].ui_LabelScheduleItem, time);
                            const char * priority_ctr = convertPriorityToCstr(priority);  
                            lv_label_set_text(jsonScheduleItemList[i].ui_LabelScheduleItemPriority, priority_ctr);
                            lv_label_set_text(jsonScheduleItemList[i].ui_LabelScheduleItemTimer, schedule_type);
                            lv_obj_clear_flag(jsonScheduleItemList[i].ui_PanelScheduleItemContainer, LV_OBJ_FLAG_HIDDEN);
                            
                        }
                        else
                        {
                            break;
                        }
                        i++;
                    }
                }
            }
            else
            {
                print(PRINTLN, "ui_ScheduleContainer is not valid!");
            }
            lv_obj_add_flag(ui_PanelLoadingScheduleScreen, LV_OBJ_FLAG_HIDDEN);
            // Cleanup and free resources manually when you're done
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
