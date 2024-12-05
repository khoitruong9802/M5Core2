// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: m5core2

#include "../ui.h"

void ui_farmScreen_screen_init(void)
{
    ui_farmScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_farmScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_farmScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_farmScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_farmScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_farmScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_farmScreen_screen = lv_obj_create(ui_farmScreen);
    lv_obj_set_width(ui_farmScreen_screen, 320);
    lv_obj_set_height(ui_farmScreen_screen, 240);
    lv_obj_set_align(ui_farmScreen_screen, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_farmScreen_screen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_farmScreen_screen, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_farmScreen_screen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_farmScreen_screen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelfarmScreen_screen = lv_obj_create(ui_farmScreen_screen);
    lv_obj_set_width(ui_PanelfarmScreen_screen, 270);
    lv_obj_set_height(ui_PanelfarmScreen_screen, 200);
    lv_obj_set_align(ui_PanelfarmScreen_screen, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PanelfarmScreen_screen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_PanelfarmScreen_screen, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_scroll_dir(ui_PanelfarmScreen_screen, LV_DIR_VER);
    lv_obj_set_style_radius(ui_PanelfarmScreen_screen, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelfarmScreen_screen, lv_color_hex(0x282828), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelfarmScreen_screen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelfarmScreen_screen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelfarmScreen_screen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelDeviceItemFarmScreen = lv_obj_create(ui_PanelfarmScreen_screen);
    lv_obj_set_width(ui_PanelDeviceItemFarmScreen, 250);
    lv_obj_set_height(ui_PanelDeviceItemFarmScreen, 50);
    lv_obj_set_x(ui_PanelDeviceItemFarmScreen, 0);
    lv_obj_set_y(ui_PanelDeviceItemFarmScreen, 2);
    lv_obj_set_align(ui_PanelDeviceItemFarmScreen, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PanelDeviceItemFarmScreen, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_PanelDeviceItemFarmScreen, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelDeviceItemFarmScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelDeviceItemFarmScreen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelDeviceItemFarmScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelDeviceItemFarmScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelDeviceItemFarmScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_PanelDeviceItemFarmScreen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_PanelDeviceItemFarmScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_PanelDeviceItemFarmScreen, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_PanelDeviceItemFarmScreen, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelDeviceItemFarmScreen, lv_color_hex(0x353535), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_PanelDeviceItemFarmScreen, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImgDeviceItemFarmScreen = lv_img_create(ui_PanelDeviceItemFarmScreen);
    lv_img_set_src(ui_ImgDeviceItemFarmScreen, &ui_img_device_png);
    lv_obj_set_width(ui_ImgDeviceItemFarmScreen, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ImgDeviceItemFarmScreen, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ImgDeviceItemFarmScreen, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImgDeviceItemFarmScreen, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgDeviceItemFarmScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelDeviceItemFarmScreen = lv_label_create(ui_PanelDeviceItemFarmScreen);
    lv_obj_set_width(ui_LabelDeviceItemFarmScreen, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelDeviceItemFarmScreen, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelDeviceItemFarmScreen, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelDeviceItemFarmScreen, "Devices");
    lv_obj_set_style_text_color(ui_LabelDeviceItemFarmScreen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelDeviceItemFarmScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelDeviceItemFarmScreen, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelScheduleItemFarmScreen = lv_obj_create(ui_PanelfarmScreen_screen);
    lv_obj_set_width(ui_PanelScheduleItemFarmScreen, 250);
    lv_obj_set_height(ui_PanelScheduleItemFarmScreen, 50);
    lv_obj_set_x(ui_PanelScheduleItemFarmScreen, 0);
    lv_obj_set_y(ui_PanelScheduleItemFarmScreen, 2);
    lv_obj_set_align(ui_PanelScheduleItemFarmScreen, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PanelScheduleItemFarmScreen, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_PanelScheduleItemFarmScreen, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelScheduleItemFarmScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelScheduleItemFarmScreen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelScheduleItemFarmScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelScheduleItemFarmScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelScheduleItemFarmScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_PanelScheduleItemFarmScreen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_PanelScheduleItemFarmScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_PanelScheduleItemFarmScreen, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_PanelScheduleItemFarmScreen, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelScheduleItemFarmScreen, lv_color_hex(0x353535), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_PanelScheduleItemFarmScreen, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImgScheduleItemFarmScreen = lv_img_create(ui_PanelScheduleItemFarmScreen);
    lv_img_set_src(ui_ImgScheduleItemFarmScreen, &ui_img_scheduler_icon_png);
    lv_obj_set_width(ui_ImgScheduleItemFarmScreen, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ImgScheduleItemFarmScreen, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ImgScheduleItemFarmScreen, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImgScheduleItemFarmScreen, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgScheduleItemFarmScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelScheduleItemFarmScreen = lv_label_create(ui_PanelScheduleItemFarmScreen);
    lv_obj_set_width(ui_LabelScheduleItemFarmScreen, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelScheduleItemFarmScreen, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelScheduleItemFarmScreen, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelScheduleItemFarmScreen, "Schedules");
    lv_obj_set_style_text_color(ui_LabelScheduleItemFarmScreen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelScheduleItemFarmScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelScheduleItemFarmScreen, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelHistoryItemFarmScreen = lv_obj_create(ui_PanelfarmScreen_screen);
    lv_obj_set_width(ui_PanelHistoryItemFarmScreen, 250);
    lv_obj_set_height(ui_PanelHistoryItemFarmScreen, 50);
    lv_obj_set_x(ui_PanelHistoryItemFarmScreen, 0);
    lv_obj_set_y(ui_PanelHistoryItemFarmScreen, 2);
    lv_obj_set_align(ui_PanelHistoryItemFarmScreen, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PanelHistoryItemFarmScreen, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_PanelHistoryItemFarmScreen, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelHistoryItemFarmScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelHistoryItemFarmScreen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelHistoryItemFarmScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelHistoryItemFarmScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelHistoryItemFarmScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_PanelHistoryItemFarmScreen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_PanelHistoryItemFarmScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_PanelHistoryItemFarmScreen, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_PanelHistoryItemFarmScreen, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelHistoryItemFarmScreen, lv_color_hex(0x353535), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_PanelHistoryItemFarmScreen, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImgHistoryItemFarmScreen = lv_img_create(ui_PanelHistoryItemFarmScreen);
    lv_img_set_src(ui_ImgHistoryItemFarmScreen, &ui_img_chart_png);
    lv_obj_set_width(ui_ImgHistoryItemFarmScreen, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ImgHistoryItemFarmScreen, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ImgHistoryItemFarmScreen, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImgHistoryItemFarmScreen, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgHistoryItemFarmScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelHistoryItemFarmScreen = lv_label_create(ui_PanelHistoryItemFarmScreen);
    lv_obj_set_width(ui_LabelHistoryItemFarmScreen, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelHistoryItemFarmScreen, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelHistoryItemFarmScreen, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelHistoryItemFarmScreen, "Information");
    lv_obj_set_style_text_color(ui_LabelHistoryItemFarmScreen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHistoryItemFarmScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHistoryItemFarmScreen, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_PanelLoadingFarmScreen = lv_obj_create(ui_farmScreen);
    lv_obj_set_width(ui_PanelLoadingFarmScreen, 240);
    lv_obj_set_height(ui_PanelLoadingFarmScreen, 180);
    lv_obj_set_align(ui_PanelLoadingFarmScreen, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PanelLoadingFarmScreen, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_PanelLoadingFarmScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_SpinnerLoadingFarm = lv_spinner_create(ui_PanelLoadingFarmScreen, 1000, 90);
    lv_obj_set_width(ui_SpinnerLoadingFarm, 80);
    lv_obj_set_height(ui_SpinnerLoadingFarm, 80);
    lv_obj_set_align(ui_SpinnerLoadingFarm, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_SpinnerLoadingFarm, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    ui_PanelHeaderLoadingFarm = lv_obj_create(ui_PanelLoadingFarmScreen);
    lv_obj_set_width(ui_PanelHeaderLoadingFarm, 240);
    lv_obj_set_height(ui_PanelHeaderLoadingFarm, 35);
    lv_obj_set_x(ui_PanelHeaderLoadingFarm, 0);
    lv_obj_set_y(ui_PanelHeaderLoadingFarm, -71);
    lv_obj_set_align(ui_PanelHeaderLoadingFarm, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelHeaderLoadingFarm, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelHeaderLoadingFarm, lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelHeaderLoadingFarm, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelHeaderLoadingFarm, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelHeaderLoadingFarm, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonHeaderLoadingFarm = lv_btn_create(ui_PanelHeaderLoadingFarm);
    // lv_obj_set_width(ui_ButtonHeaderLoadingFarm, 40);
    // lv_obj_set_height(ui_ButtonHeaderLoadingFarm, 35);
    // lv_obj_set_x(ui_ButtonHeaderLoadingFarm, 97);
    // lv_obj_set_y(ui_ButtonHeaderLoadingFarm, 0);
    // lv_obj_set_align(ui_ButtonHeaderLoadingFarm, LV_ALIGN_CENTER);
    // lv_obj_add_flag(ui_ButtonHeaderLoadingFarm, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    // lv_obj_clear_flag(ui_ButtonHeaderLoadingFarm, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    // ui_LabelHeaderLoadingFarm = lv_label_create(ui_ButtonHeaderLoadingFarm);
    // lv_obj_set_width(ui_LabelHeaderLoadingFarm, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_LabelHeaderLoadingFarm, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_align(ui_LabelHeaderLoadingFarm, LV_ALIGN_CENTER);
    // lv_label_set_text(ui_LabelHeaderLoadingFarm, "X");
    // lv_obj_set_style_text_font(ui_LabelHeaderLoadingFarm, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelMesageLoadingFarm = lv_label_create(ui_PanelLoadingFarmScreen);
    lv_obj_set_width(ui_LabelMesageLoadingFarm, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelMesageLoadingFarm, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelMesageLoadingFarm, 0);
    lv_obj_set_y(ui_LabelMesageLoadingFarm, 65);
    lv_obj_set_align(ui_LabelMesageLoadingFarm, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelMesageLoadingFarm, "Connecting.......");
    lv_obj_set_style_text_font(ui_LabelMesageLoadingFarm, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelNotification1FarmScreen = lv_obj_create(ui_farmScreen);
    lv_obj_set_width(ui_PanelNotification1FarmScreen, 240);
    lv_obj_set_height(ui_PanelNotification1FarmScreen, 140);
    lv_obj_set_align(ui_PanelNotification1FarmScreen, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PanelNotification1FarmScreen, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_PanelNotification1FarmScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelMessageNotification1Farm = lv_label_create(ui_PanelNotification1FarmScreen);
    lv_obj_set_width(ui_LabelMessageNotification1Farm, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelMessageNotification1Farm, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelMessageNotification1Farm, 0);
    lv_obj_set_y(ui_LabelMessageNotification1Farm, 16);
    lv_obj_set_align(ui_LabelMessageNotification1Farm, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelMessageNotification1Farm, "Connection to mqtt\nbroker failed!!\nPlease try again");
    lv_obj_set_style_text_font(ui_LabelMessageNotification1Farm, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelHeaderNotification1Farm = lv_obj_create(ui_PanelNotification1FarmScreen);
    lv_obj_set_width(ui_PanelHeaderNotification1Farm, 240);
    lv_obj_set_height(ui_PanelHeaderNotification1Farm, 35);
    lv_obj_set_x(ui_PanelHeaderNotification1Farm, 1);
    lv_obj_set_y(ui_PanelHeaderNotification1Farm, -51);
    lv_obj_set_align(ui_PanelHeaderNotification1Farm, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelHeaderNotification1Farm, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelHeaderNotification1Farm, lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelHeaderNotification1Farm, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelHeaderNotification1Farm, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelHeaderNotification1Farm, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonCloseHeaderNotification1Farm = lv_btn_create(ui_PanelHeaderNotification1Farm);
    lv_obj_set_width(ui_ButtonCloseHeaderNotification1Farm, 40);
    lv_obj_set_height(ui_ButtonCloseHeaderNotification1Farm, 35);
    lv_obj_set_x(ui_ButtonCloseHeaderNotification1Farm, 97);
    lv_obj_set_y(ui_ButtonCloseHeaderNotification1Farm, 0);
    lv_obj_set_align(ui_ButtonCloseHeaderNotification1Farm, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonCloseHeaderNotification1Farm, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonCloseHeaderNotification1Farm, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelCloseHeaderNotification1Farm = lv_label_create(ui_ButtonCloseHeaderNotification1Farm);
    lv_obj_set_width(ui_LabelCloseHeaderNotification1Farm, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelCloseHeaderNotification1Farm, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelCloseHeaderNotification1Farm, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelCloseHeaderNotification1Farm, "X");
    lv_obj_set_style_text_font(ui_LabelCloseHeaderNotification1Farm, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_PanelDeviceItemFarmScreen, ui_event_PanelDeviceItemFarmScreen, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelScheduleItemFarmScreen, ui_event_PanelScheduleItemFarmScreen, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelHistoryItemFarmScreen, ui_event_PanelHistoryItemFarmScreen, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonCloseHeaderNotification1Farm, ui_event_ButtonCloseHeaderNotification1Farm, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_farmScreen, ui_event_farmScreen, LV_EVENT_ALL, NULL);

}