// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: m5core2

#include "../ui.h"

void ui_EndDate_screen_init(void)
{
    ui_EndDate = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_EndDate, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);      /// Flags
    lv_obj_set_scrollbar_mode(ui_EndDate, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_bg_color(ui_EndDate, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_EndDate, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_EndDate, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_EndDate, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_EndDateScheduleItemScreen = lv_obj_create(ui_EndDate);
    lv_obj_set_width(ui_EndDateScheduleItemScreen, 320);
    lv_obj_set_height(ui_EndDateScheduleItemScreen, 240);
    lv_obj_set_align(ui_EndDateScheduleItemScreen, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_EndDateScheduleItemScreen,
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_scroll_dir(ui_EndDateScheduleItemScreen, LV_DIR_VER);
    lv_obj_set_style_radius(ui_EndDateScheduleItemScreen, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_EndDateScheduleItemScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_EndDateScheduleItemScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonOKEndDateScheduleItem = lv_btn_create(ui_EndDateScheduleItemScreen);
    lv_obj_set_width(ui_ButtonOKEndDateScheduleItem, 50);
    lv_obj_set_height(ui_ButtonOKEndDateScheduleItem, 30);
    lv_obj_set_x(ui_ButtonOKEndDateScheduleItem, -130);
    lv_obj_set_y(ui_ButtonOKEndDateScheduleItem, -100);
    lv_obj_set_align(ui_ButtonOKEndDateScheduleItem, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonOKEndDateScheduleItem, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonOKEndDateScheduleItem, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonOKEndDateScheduleItem, lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonOKEndDateScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelOKEndDateScheduleItem = lv_label_create(ui_ButtonOKEndDateScheduleItem);
    lv_obj_set_width(ui_LabelOKEndDateScheduleItem, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelOKEndDateScheduleItem, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelOKEndDateScheduleItem, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelOKEndDateScheduleItem, "OK");
    lv_obj_set_style_text_font(ui_LabelOKEndDateScheduleItem, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTitleEndDateScheduleItem = lv_label_create(ui_EndDateScheduleItemScreen);
    lv_obj_set_width(ui_LabelTitleEndDateScheduleItem, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelTitleEndDateScheduleItem, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelTitleEndDateScheduleItem, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_LabelTitleEndDateScheduleItem, "End Date");
    lv_obj_set_style_text_color(ui_LabelTitleEndDateScheduleItem, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTitleEndDateScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CalendarEndDateScheduleItem = lv_calendar_create(ui_EndDateScheduleItemScreen);
    lv_obj_t * ui_CalendarEndDateScheduleItem_header = lv_calendar_header_arrow_create(ui_CalendarEndDateScheduleItem);
    lv_obj_set_width(ui_CalendarEndDateScheduleItem, 300);
    lv_obj_set_height(ui_CalendarEndDateScheduleItem, 200);
    lv_obj_set_x(ui_CalendarEndDateScheduleItem, 0);
    lv_obj_set_y(ui_CalendarEndDateScheduleItem, 25);
    lv_obj_set_align(ui_CalendarEndDateScheduleItem, LV_ALIGN_CENTER);

    ui_ButtonCancelEndDateScheduleItem = lv_btn_create(ui_EndDateScheduleItemScreen);
    lv_obj_set_width(ui_ButtonCancelEndDateScheduleItem, 50);
    lv_obj_set_height(ui_ButtonCancelEndDateScheduleItem, 30);
    lv_obj_set_x(ui_ButtonCancelEndDateScheduleItem, 130);
    lv_obj_set_y(ui_ButtonCancelEndDateScheduleItem, -100);
    lv_obj_set_align(ui_ButtonCancelEndDateScheduleItem, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonCancelEndDateScheduleItem, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonCancelEndDateScheduleItem, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonCancelEndDateScheduleItem, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonCancelEndDateScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelCancelEndDateScheduleItem = lv_label_create(ui_ButtonCancelEndDateScheduleItem);
    lv_obj_set_width(ui_LabelCancelEndDateScheduleItem, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelCancelEndDateScheduleItem, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelCancelEndDateScheduleItem, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelCancelEndDateScheduleItem, "Cancel");
    lv_obj_set_style_text_font(ui_LabelCancelEndDateScheduleItem, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_ButtonOKEndDateScheduleItem, ui_event_ButtonOKEndDateScheduleItem, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonCancelEndDateScheduleItem, ui_event_ButtonCancelEndDateScheduleItem, LV_EVENT_ALL, NULL);
        lv_obj_add_event_cb(ui_CalendarEndDateScheduleItem, ui_event_CalendarEndDateScheduleItem, LV_EVENT_ALL, NULL);

}