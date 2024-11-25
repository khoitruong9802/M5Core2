#include "schedule_service.h"
#include "esp_heap_caps.h"
// #include "esp_psram.h"
#include "../gui/ui.h"
#include "../utils/http.h"

static void ScheduleItem_Dropdown_handle(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    char buf[64];
    lv_dropdown_get_selected_str(obj, buf, sizeof(buf));
    lv_dropdown_set_text(obj, buf);
}

void renderScheduleItemUI(const char * schedule_name,
    const char * description,
    uint16_t area,
    uint16_t priority,
    const char* water_quantity,
    const char * schedule_type,
    const char * schedule_start_time,
    const char * schedule_stop_time,
    const char * schedule_start_day,
    const char * schedule_end_day,
    const char* days_list[7],
    int days_count
)
{
    // Generate UI for Schedule Item Screen
    lv_label_set_text(ui_LabelNameScheduleItem, schedule_name);
    lv_label_set_text(ui_LabelDescriptionScheduleItem, description);
    lv_dropdown_set_selected(ui_DropdownAreaScheduleItem, area);
    lv_slider_set_value(ui_SliderPriorityScheduleItem, priority, LV_ANIM_OFF);

    lv_label_set_text(ui_LabelWaterQuantityScheduleItem, water_quantity);
    lv_label_set_text(ui_LabelScheduleStartTimeScheduleItem, schedule_start_time);
    lv_label_set_text(ui_LabelScheduleEndTimeScheduleItem, schedule_stop_time);
    uint16_t type_idx = 0;
    if (strcmp(schedule_type, "once") == 0) 
    {
        type_idx = 0;
        lv_obj_clear_flag(ui_PanelScheduleDateContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_add_flag(ui_PanelScheduleStartDateContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_add_flag(ui_PanelScheduleEndDateContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_add_flag(ui_PanelScheduleWeekContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
    } 
    else if (strcmp(schedule_type, "daily") == 0) 
    {
        type_idx = 1;
        lv_obj_add_flag(ui_PanelScheduleDateContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelScheduleStartDateContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelScheduleEndDateContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_add_flag(ui_PanelScheduleWeekContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
    } 
    else if (strcmp(schedule_type, "weekly") == 0) 
    {
        type_idx = 2;
        lv_obj_add_flag(ui_PanelScheduleDateContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelScheduleStartDateContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelScheduleEndDateContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelScheduleWeekContainerScheduleItem, LV_OBJ_FLAG_HIDDEN); 
    }
    lv_dropdown_set_selected(ui_DropdownScheduleRepeatScheduleItem, type_idx);
    lv_label_set_text(ui_LabelScheduleDateScheduleItem, schedule_start_day);
    lv_label_set_text(ui_LabelScheduleStartDateScheduleItem, schedule_end_day);
    lv_label_set_text(ui_LabelScheduleEndDateScheduleItem, schedule_end_day);

    for(int i = 0; i < days_count; i++) 
    {
        if(strcmp(days_list[i], "Monday") == 0)
        {
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemMondayScheduleItem, lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else if(strcmp(days_list[i], "Tuesday") == 0)
        {
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemTuesdayScheduleItem, lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else if(strcmp(days_list[i], "Wednesday") == 0)
        {
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemWednesdayScheduleItem, lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else if(strcmp(days_list[i], "Thursday") == 0)
        {
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemThursdayScheduleItem, lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else if(strcmp(days_list[i], "Friday") == 0)
        {
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemFridayScheduleItem, lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else if(strcmp(days_list[i], "Saturday") == 0)
        {
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemSaturdayScheduleItem, lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else if(strcmp(days_list[i], "Sunday") == 0)
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
    const char * schedule_name;
    const char * description;
    uint16_t area;
    uint16_t priority;
    const char * water_quantity;
    const char * schedule_type;
    const char * schedule_start_time;
    const char * schedule_stop_time;
    const char * schedule_start_day;
    const char * schedule_end_day;
    const char* days_list[7];
    int days_count = 0; 
    // Get the schedule item data
    for(JsonObject obj : jsonArray) {
        int id = obj["id"];
        if(schedule_id == id) {
            // Extracting other values as you did previously with null checks.
            
            // Check if schedule_name key is not null
            if (obj["schedule_name"].is<const char*>()) {
                schedule_name = obj["schedule_name"].as<const char*>();
            } else {
                schedule_name = " ";  // Set a default value or handle appropriately
            }

            // Check if description key is not null
            if (obj["description"].is<const char*>()) {
                description = obj["description"].as<const char*>();
            } else {
                description = " ";
            }

            // Extract area
            if (obj["area"].is<int>()) {
                area = obj["area"].as<int>() - 1;
            } else {
                area = 0;  // Indicate that the area value is missing or invalid
            }

            // Extract priority
            if (obj["priority"].is<int>()) {
                priority = obj["priority"].as<uint16_t>() - 1;
            } else {
                priority = 0;  // Default value or handle appropriately
            }

            // Extract water quantity
            if (obj["water_quantity"].is<int>()) {
                int water_quantity_int = obj["water_quantity"].as<int>();
                char buffer[10];
                itoa(water_quantity_int, buffer, 10 );
                water_quantity = buffer;
            } else {
                water_quantity = " ";  // Set default or handle appropriately
            }

            // Check each element in the schedule to avoid null pointers
            if (obj["start_time"].is<const char*>()) {
                schedule_start_time = obj["start_time"].as<const char*>();
            } else {
                schedule_start_time = " ";
            }

            if (obj["stop_time"].is<const char*>()) {
                schedule_stop_time = obj["stop_time"].as<const char*>();
            } else {
                schedule_stop_time = " ";
            }

            if (obj["schedule_type"].is<const char*>()) {
                schedule_type = obj["schedule_type"].as<const char*>();
            } else {
                schedule_type = " ";
            }

            if (obj["start_day"].is<const char*>()) {
                schedule_start_day = obj["start_day"].as<const char*>();
            } else {
                schedule_start_day = " ";
            }

            if (obj["end_day"].is<const char*>()) {
                schedule_end_day = obj["end_day"].as<const char*>();
            } else {
                schedule_end_day = " ";
            }

            // Extract the "days" array inside the "schedule" object, if it exists
            if (obj["days"].is<JsonArray>()) {
                JsonArray daysArray = obj["days"].as<JsonArray>();

                // Clear the `days_list` and reset the counter
                days_count = 0;

                // Iterate over the "days" array and store the values in `days_list`
                for (const char* day : daysArray) {
                    if (day != nullptr && days_count < 7) { // Ensure we don't exceed our array size
                        days_list[days_count] = day;
                        days_count++;
                    }
                }
            } else {
                days_count = 0; // No days available
            }

            break;  // Exit the loop once the desired object is found.
        }
    }
    for(;;)
    {
        // Checking does mutex is available
        if (xSemaphoreTake(lvgl_mutex,  pdMS_TO_TICKS(10)) == pdTRUE)
        {
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemMondayScheduleItem, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemTuesdayScheduleItem, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemWednesdayScheduleItem, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemThursdayScheduleItem, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemFridayScheduleItem, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemSaturdayScheduleItem, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_PanelScheduleWeekItemSundayScheduleItem, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_task_handler();
            renderScheduleItemUI(schedule_name, description, area, priority, water_quantity, schedule_type, schedule_start_time, schedule_stop_time, schedule_start_day, schedule_end_day, days_list, days_count);
            lv_obj_add_flag(ui_PanelLoadingScheduleItemScreen, LV_OBJ_FLAG_HIDDEN);
            lv_task_handler();
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

static void schedule_item_click_event_handler(lv_event_t * e)
{
    lv_obj_t * panel = lv_event_get_target(e);
    // Get the schedule ID or metadata associated with this panel
    int schedule_id = (int)(uintptr_t)lv_event_get_user_data(e);
    current_schedule_id = schedule_id;

    // You could use the schedule ID to pull the detailed information from memory, 
    // for example, fetching from an array or JSON data stored locally.

    // Call a function to display the detailed information screen
    lv_obj_clear_flag(ui_PanelLoadingScheduleItemScreen, LV_OBJ_FLAG_HIDDEN);    
    lv_obj_scroll_to_x(ui_PanelScheduleItemContainerScreen, 0, LV_ANIM_OFF);
    lv_obj_scroll_to_y(ui_PanelScheduleItemContainerScreen, 0, LV_ANIM_OFF);       
    lv_task_handler();
    _ui_screen_change(&ui_scheduleItemScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_ScheduleItemScreen_screen_init);
    TaskHandle_t scheItem_task = xTaskGetHandle("scheItem_task");
    if(scheItem_task == NULL)
    {
        xTaskCreate(handleScheduleItemUI, "scheItem_task", 8192, (void *)(uintptr_t)schedule_id, 1, &scheItem_task);
    }
}

void renderNavigateSchedulePage(int numberOfElement)
{
    int numberOfPage = numberOfElement / 5;
    for(int i = 0; i < 20; i++)
    {
        ui_Panel2 = lv_obj_create(ui_TitleScheduleScreen);
        lv_obj_set_width(ui_Panel2, 35);
        lv_obj_set_height(ui_Panel2, 35);
        lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
        lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

        ui_Label3 = lv_label_create(ui_Panel2);
        lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
        lv_label_set_text(ui_Label3, "1");
    }
}


void renderScheduleUI(int id, const char *time, int flow1, int flow2, int flow3, const char * schedule_type) 
{  
    
    ui_PanelScheduleItem = lv_obj_create(ui_ScheduleContainer);
    lv_obj_set_width(ui_PanelScheduleItem, 285);
    lv_obj_set_height(ui_PanelScheduleItem, 50);
    lv_obj_set_x(ui_PanelScheduleItem, 0);
    lv_obj_set_y(ui_PanelScheduleItem, -45);
    lv_obj_set_align(ui_PanelScheduleItem, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PanelScheduleItem, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_PanelScheduleItem, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelScheduleItem, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelScheduleItem, lv_color_hex(0xC8C8C8), LV_PART_MAIN | LV_STATE_PRESSED); //Light Gray
    lv_obj_set_style_bg_opa(ui_PanelScheduleItem, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    lv_obj_add_event_cb(ui_PanelScheduleItem, schedule_item_click_event_handler, LV_EVENT_CLICKED, (void *)id);
    lv_obj_t * ui_LabelScheduleItem = lv_label_create(ui_PanelScheduleItem);
    lv_obj_set_width(ui_LabelScheduleItem, 60);   /// 1
    lv_obj_set_height(ui_LabelScheduleItem, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelScheduleItem, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelScheduleItem, time);
    lv_obj_set_style_text_font(ui_LabelScheduleItem, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * ui_PanelScheduleItemIngredient = lv_obj_create(ui_PanelScheduleItem);
    lv_obj_set_width(ui_PanelScheduleItemIngredient, 75);
    lv_obj_set_height(ui_PanelScheduleItemIngredient, 50);
    lv_obj_set_x(ui_PanelScheduleItemIngredient, 2);
    lv_obj_set_y(ui_PanelScheduleItemIngredient, 0);
    lv_obj_set_align(ui_PanelScheduleItemIngredient, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PanelScheduleItemIngredient, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_PanelScheduleItemIngredient, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_SPACE_EVENLY);
    lv_obj_clear_flag(ui_PanelScheduleItemIngredient, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_opa(ui_PanelScheduleItemIngredient, LV_OPA_TRANSP, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_PanelScheduleItemIngredient, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_PanelScheduleItemIngredient, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelScheduleItemIngredient, LV_OPA_TRANSP, LV_PART_MAIN | LV_STATE_DEFAULT); //set object to transparent color


    int num = flow1;
    char buffer[10];           // Ensure buffer is large enough to hold the string representation
    itoa(num, buffer, 10);     // Convert the int to a string (base 10)
    const char *str = buffer;  // Now 'str' is a const char* pointing to the string
    lv_obj_t * ui_LabelScheduleItemIngredient1 = lv_label_create(ui_PanelScheduleItemIngredient);
    lv_obj_set_width(ui_LabelScheduleItemIngredient1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelScheduleItemIngredient1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelScheduleItemIngredient1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelScheduleItemIngredient1, str);
    lv_obj_set_style_bg_color(ui_LabelScheduleItemIngredient1, lv_color_hex(0xFECACA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LabelScheduleItemIngredient1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_LabelScheduleItemIngredient1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_LabelScheduleItemIngredient1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_LabelScheduleItemIngredient1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_LabelScheduleItemIngredient1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    num = flow2;
    itoa(num, buffer, 10);  // Convert the int to a string (base 10)
    str = buffer;           // Now 'str' is a const char* pointing to the string

    lv_obj_t * ui_LabelScheduleItemIngredient2 = lv_label_create(ui_PanelScheduleItemIngredient);
    lv_obj_set_width(ui_LabelScheduleItemIngredient2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelScheduleItemIngredient2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelScheduleItemIngredient2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelScheduleItemIngredient2, str);
    lv_obj_set_style_bg_color(ui_LabelScheduleItemIngredient2, lv_color_hex(0xBFDBFE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LabelScheduleItemIngredient2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_LabelScheduleItemIngredient2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_LabelScheduleItemIngredient2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_LabelScheduleItemIngredient2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_LabelScheduleItemIngredient2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    num = flow3;
    itoa(num, buffer, 10);  // Convert the int to a string (base 10)
    str = buffer;           // Now 'str' is a const char* pointing to the string

    lv_obj_t * ui_LabelScheduleItemIngredient3 = lv_label_create(ui_PanelScheduleItemIngredient);
    lv_obj_set_width(ui_LabelScheduleItemIngredient3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelScheduleItemIngredient3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelScheduleItemIngredient3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelScheduleItemIngredient3, str);
    lv_obj_set_style_bg_color(ui_LabelScheduleItemIngredient3, lv_color_hex(0xFEF08A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LabelScheduleItemIngredient3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_LabelScheduleItemIngredient3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_LabelScheduleItemIngredient3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_LabelScheduleItemIngredient3, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_LabelScheduleItemIngredient3, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * ui_LabelScheduleItemTimer = lv_label_create(ui_PanelScheduleItem);
    lv_obj_set_width(ui_LabelScheduleItemTimer, 75);   /// 1
    lv_obj_set_height(ui_LabelScheduleItemTimer, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelScheduleItemTimer, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelScheduleItemTimer, schedule_type);
    lv_obj_set_style_text_font(ui_LabelScheduleItemTimer, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);


    lv_obj_t * ui_SwitchScheduleItem = lv_switch_create(ui_PanelScheduleItem);
    lv_obj_set_width(ui_SwitchScheduleItem, 50);
    lv_obj_set_height(ui_SwitchScheduleItem, 25);
    lv_obj_set_align(ui_SwitchScheduleItem, LV_ALIGN_CENTER);
}



void handleScheduleUI(void *parameter)
{
    String response = http_get_data("http://192.168.0.101:3000/data");
    String jsonString;
    JsonDocument jsonDocGlobal;

    jsonString = response;
    DeserializationError error = deserializeJson(jsonDocGlobal, jsonString);
    if (error) 
    {
    Serial.println(error.c_str());
    }

    // Access the JSON array
    jsonArray = jsonDocGlobal.as<JsonArray>();
    Serial.println(jsonArray);
    int numberOfElement = jsonArray.size();
    for(;;)
    {
        print(PRINTLN, "Schedule UI task is running!"); 
        // Checking does mutex is available
        if (xSemaphoreTake(lvgl_mutex,  pdMS_TO_TICKS(10)) == pdTRUE)
        {
            if(lv_obj_is_valid(ui_TitleScheduleScreen) == true)
            {
                lv_obj_t *child = lv_obj_get_child(ui_TitleScheduleScreen, 0);
                if(child == NULL)
                {
                    renderNavigateSchedulePage(numberOfElement);
                }
            }
            if(lv_obj_is_valid(ui_ScheduleContainer) == true)
            {
                lv_obj_t *child = lv_obj_get_child(ui_ScheduleContainer, 0);
                if(child == NULL)
                {
                    for (JsonObject obj : jsonArray) 
                    {
                        int id = obj["id"];
                        const char *time = obj["start_time"];
                        int flow1 = obj["flow1"];
                        int flow2 = obj["flow2"];
                        int flow3 = obj["flow3"];
                        const char * schedule_type = obj["schedule_type"];
                        const char * schedule_status = obj["status"];
                        //TO DO

                        renderScheduleUI(id, time, flow1, flow2, flow3, schedule_type);
                    }
                }
            }
            else
            {
                print(PRINTLN, "ui_ScheduleContainer is not valid!");
            }
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