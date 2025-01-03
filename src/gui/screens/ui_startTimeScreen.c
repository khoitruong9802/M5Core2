// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: m5core2

#include "../ui.h"

void ui_startTime_screen_init(void)
{
    ui_startTime = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_startTime, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);      /// Flags
    lv_obj_set_scrollbar_mode(ui_startTime, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_bg_color(ui_startTime, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_startTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_startTime, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_startTime, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_StartTimeScheduleItemScreen = lv_obj_create(ui_startTime);
    lv_obj_set_width(ui_StartTimeScheduleItemScreen, 320);
    lv_obj_set_height(ui_StartTimeScheduleItemScreen, 240);
    lv_obj_set_align(ui_StartTimeScheduleItemScreen, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_StartTimeScheduleItemScreen,
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_scroll_dir(ui_StartTimeScheduleItemScreen, LV_DIR_VER);
    lv_obj_set_style_radius(ui_StartTimeScheduleItemScreen, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_StartTimeScheduleItemScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_StartTimeScheduleItemScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTitleStartTimeScheduleItem = lv_label_create(ui_StartTimeScheduleItemScreen);
    lv_obj_set_width(ui_LabelTitleStartTimeScheduleItem, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelTitleStartTimeScheduleItem, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelTitleStartTimeScheduleItem, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_LabelTitleStartTimeScheduleItem, "Start Time");
    lv_obj_set_style_text_color(ui_LabelTitleStartTimeScheduleItem, lv_color_hex(0xFFFFFF),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTitleStartTimeScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_RollerHourStartTimeScheduleItem = lv_roller_create(ui_StartTimeScheduleItemScreen);
    lv_roller_set_options(ui_RollerHourStartTimeScheduleItem,
                          "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23",
                          LV_ROLLER_MODE_NORMAL);
    lv_roller_set_selected(ui_RollerHourStartTimeScheduleItem, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_RollerHourStartTimeScheduleItem, 120);
    lv_obj_set_height(ui_RollerHourStartTimeScheduleItem, 55);
    lv_obj_set_x(ui_RollerHourStartTimeScheduleItem, -70);
    lv_obj_set_y(ui_RollerHourStartTimeScheduleItem, -20);
    lv_obj_set_align(ui_RollerHourStartTimeScheduleItem, LV_ALIGN_CENTER);
    lv_obj_set_style_text_color(ui_RollerHourStartTimeScheduleItem, lv_color_hex(0x616161),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_RollerHourStartTimeScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_RollerHourStartTimeScheduleItem, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RollerHourStartTimeScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_RollerHourStartTimeScheduleItem, lv_color_hex(0x000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_RollerHourStartTimeScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_RollerHourStartTimeScheduleItem, lv_color_hex(0xFFFFFF),
                                LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_RollerHourStartTimeScheduleItem, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_RollerHourStartTimeScheduleItem, &lv_font_montserrat_48,
                               LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_RollerHourStartTimeScheduleItem, lv_color_hex(0x000000),
                              LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RollerHourStartTimeScheduleItem, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_LabelColonSymbolStartTimeScheduleItem = lv_label_create(ui_StartTimeScheduleItemScreen);
    lv_obj_set_width(ui_LabelColonSymbolStartTimeScheduleItem, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelColonSymbolStartTimeScheduleItem, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelColonSymbolStartTimeScheduleItem, 0);
    lv_obj_set_y(ui_LabelColonSymbolStartTimeScheduleItem, -30);
    lv_obj_set_align(ui_LabelColonSymbolStartTimeScheduleItem, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelColonSymbolStartTimeScheduleItem, ":");
    lv_obj_set_style_text_color(ui_LabelColonSymbolStartTimeScheduleItem, lv_color_hex(0xFFFFFF),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelColonSymbolStartTimeScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelColonSymbolStartTimeScheduleItem, &lv_font_montserrat_48,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_RollerMinuteStartTimeScheduleItem = lv_roller_create(ui_StartTimeScheduleItemScreen);
    lv_roller_set_options(ui_RollerMinuteStartTimeScheduleItem,
                          "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59",
                          LV_ROLLER_MODE_NORMAL);
    lv_roller_set_selected(ui_RollerMinuteStartTimeScheduleItem, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_RollerMinuteStartTimeScheduleItem, 120);
    lv_obj_set_height(ui_RollerMinuteStartTimeScheduleItem, 55);
    lv_obj_set_x(ui_RollerMinuteStartTimeScheduleItem, 70);
    lv_obj_set_y(ui_RollerMinuteStartTimeScheduleItem, -20);
    lv_obj_set_align(ui_RollerMinuteStartTimeScheduleItem, LV_ALIGN_CENTER);
    lv_obj_set_style_text_color(ui_RollerMinuteStartTimeScheduleItem, lv_color_hex(0x616161),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_RollerMinuteStartTimeScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_RollerMinuteStartTimeScheduleItem, lv_color_hex(0x000000),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RollerMinuteStartTimeScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_RollerMinuteStartTimeScheduleItem, lv_color_hex(0x000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_RollerMinuteStartTimeScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_RollerMinuteStartTimeScheduleItem, lv_color_hex(0xFFFFFF),
                                LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_RollerMinuteStartTimeScheduleItem, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_RollerMinuteStartTimeScheduleItem, &lv_font_montserrat_48,
                               LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_RollerMinuteStartTimeScheduleItem, lv_color_hex(0x000000),
                              LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RollerMinuteStartTimeScheduleItem, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_ButtonOKStartTimeScheduleItem = lv_btn_create(ui_StartTimeScheduleItemScreen);
    lv_obj_set_width(ui_ButtonOKStartTimeScheduleItem, 80);
    lv_obj_set_height(ui_ButtonOKStartTimeScheduleItem, 40);
    lv_obj_set_x(ui_ButtonOKStartTimeScheduleItem, -100);
    lv_obj_set_y(ui_ButtonOKStartTimeScheduleItem, 90);
    lv_obj_set_align(ui_ButtonOKStartTimeScheduleItem, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonOKStartTimeScheduleItem, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonOKStartTimeScheduleItem, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonOKStartTimeScheduleItem, lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonOKStartTimeScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelOKStartTimeScheduleItem = lv_label_create(ui_ButtonOKStartTimeScheduleItem);
    lv_obj_set_width(ui_LabelOKStartTimeScheduleItem, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelOKStartTimeScheduleItem, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelOKStartTimeScheduleItem, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelOKStartTimeScheduleItem, "OK");

    ui_ButtonCancelStartTimeScheduleItem = lv_btn_create(ui_StartTimeScheduleItemScreen);
    lv_obj_set_width(ui_ButtonCancelStartTimeScheduleItem, 80);
    lv_obj_set_height(ui_ButtonCancelStartTimeScheduleItem, 40);
    lv_obj_set_x(ui_ButtonCancelStartTimeScheduleItem, 100);
    lv_obj_set_y(ui_ButtonCancelStartTimeScheduleItem, 90);
    lv_obj_set_align(ui_ButtonCancelStartTimeScheduleItem, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonCancelStartTimeScheduleItem, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonCancelStartTimeScheduleItem, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonCancelStartTimeScheduleItem, lv_color_hex(0xFF0000),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonCancelStartTimeScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelCancelStartTimeScheduleItem = lv_label_create(ui_ButtonCancelStartTimeScheduleItem);
    lv_obj_set_width(ui_LabelCancelStartTimeScheduleItem, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelCancelStartTimeScheduleItem, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelCancelStartTimeScheduleItem, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelCancelStartTimeScheduleItem, "Cancel");

    lv_obj_add_event_cb(ui_ButtonOKStartTimeScheduleItem, ui_event_ButtonOKStartTimeScheduleItem, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonCancelStartTimeScheduleItem, ui_event_ButtonCancelStartTimeScheduleItem, LV_EVENT_ALL,
                        NULL);

}
