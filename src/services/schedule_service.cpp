#include "schedule_service.h"
#include "esp_heap_caps.h"
// #include "esp_psram.h"
#include "../gui/ui.h"
#include "../utils/http.h"


static void schedule_item_click_event_handler(lv_event_t * e)
{
    lv_obj_t * panel = lv_event_get_target(e);
    // Get the schedule ID or metadata associated with this panel
    int schedule_id = (int)lv_event_get_user_data(e);

    // You could use the schedule ID to pull the detailed information from memory, 
    // for example, fetching from an array or JSON data stored locally.

    // Call a function to display the detailed information screen
    Serial.println(schedule_id);
    ui_ScheduleItemScreen_screen_init(schedule_id);
}

void renderUi(int id, const char *time, int flow1, int flow2, int flow3, const char * schedule_type) 
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

    Serial.println(time);
    Serial.println(flow1);
    Serial.println(flow2);
    Serial.println(flow3);
}



void handleScheduleUI(void *parameter)
{
    JsonDocument doc;
    String response = http_get_data("http://192.168.0.112:3000/data");

    DeserializationError error = deserializeJson(doc, response);
    if (error) 
    {
    Serial.println(error.c_str());
    }

    // Access the JSON array
    jsonArray = doc.as<JsonArray>();


    for(;;)
    {
        // Checking does mutex is available
        if (xSemaphoreTake(lvgl_mutex,  pdMS_TO_TICKS(10)) == pdTRUE)
        {
            print(PRINTLN, "mutex is available for schedule UI task. Beginning...");
            // Iterate over each JSON object in the array
            print(PRINTLN, "Start to clean all old LVGL objects");
            deleteObject();
            for (JsonObject obj : jsonArray) 
            {
                int id = obj["id"];
                const char *time = obj["schedule"]["start_time"];
                int flow1 = obj["flow1"];
                int flow2 = obj["flow2"];
                int flow3 = obj["flow3"];
                const char * schedule_type = obj["schedule"]["type"];
                const char * schedule_status = obj["schedule"]["status"];
                //TO DO

                renderUi(id, time, flow1, flow2, flow3, schedule_type);
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