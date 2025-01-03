// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: m5core2

#include "../ui.h"

void ui_startDate_screen_init(void)
{
    ui_startDate = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_startDate, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);      /// Flags
    lv_obj_set_scrollbar_mode(ui_startDate, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_bg_color(ui_startDate, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_startDate, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_startDate, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_startDate, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_StartDateScheduleItemScreen = lv_obj_create(ui_startDate);
    lv_obj_set_width(ui_StartDateScheduleItemScreen, 320);
    lv_obj_set_height(ui_StartDateScheduleItemScreen, 240);
    lv_obj_set_align(ui_StartDateScheduleItemScreen, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_StartDateScheduleItemScreen,
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_scroll_dir(ui_StartDateScheduleItemScreen, LV_DIR_VER);
    lv_obj_set_style_radius(ui_StartDateScheduleItemScreen, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_StartDateScheduleItemScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_StartDateScheduleItemScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonOKStartDateScheduleItem = lv_btn_create(ui_StartDateScheduleItemScreen);
    lv_obj_set_width(ui_ButtonOKStartDateScheduleItem, 50);
    lv_obj_set_height(ui_ButtonOKStartDateScheduleItem, 30);
    lv_obj_set_x(ui_ButtonOKStartDateScheduleItem, -130);
    lv_obj_set_y(ui_ButtonOKStartDateScheduleItem, -100);
    lv_obj_set_align(ui_ButtonOKStartDateScheduleItem, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonOKStartDateScheduleItem, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonOKStartDateScheduleItem, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonOKStartDateScheduleItem, lv_color_hex(0x4264FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonOKStartDateScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelOKStartDateScheduleItem = lv_label_create(ui_ButtonOKStartDateScheduleItem);
    lv_obj_set_width(ui_LabelOKStartDateScheduleItem, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelOKStartDateScheduleItem, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelOKStartDateScheduleItem, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelOKStartDateScheduleItem, "OK");
    lv_obj_set_style_text_font(ui_LabelOKStartDateScheduleItem, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTitleStartDateScheduleItem = lv_label_create(ui_StartDateScheduleItemScreen);
    lv_obj_set_width(ui_LabelTitleStartDateScheduleItem, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelTitleStartDateScheduleItem, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelTitleStartDateScheduleItem, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_LabelTitleStartDateScheduleItem, "Start Date");
    lv_obj_set_style_text_color(ui_LabelTitleStartDateScheduleItem, lv_color_hex(0xFFFFFF),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTitleStartDateScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CalendarStartDateScheduleItem = lv_calendar_create(ui_StartDateScheduleItemScreen);
    lv_obj_t * ui_CalendarStartDateScheduleItem_header = lv_calendar_header_arrow_create(ui_CalendarStartDateScheduleItem);
    lv_obj_set_width(ui_CalendarStartDateScheduleItem, 300);
    lv_obj_set_height(ui_CalendarStartDateScheduleItem, 200);
    lv_obj_set_x(ui_CalendarStartDateScheduleItem, 0);
    lv_obj_set_y(ui_CalendarStartDateScheduleItem, 25);
    lv_obj_set_align(ui_CalendarStartDateScheduleItem, LV_ALIGN_CENTER);

    ui_ButtonCancelStartDateScheduleItem = lv_btn_create(ui_StartDateScheduleItemScreen);
    lv_obj_set_width(ui_ButtonCancelStartDateScheduleItem, 50);
    lv_obj_set_height(ui_ButtonCancelStartDateScheduleItem, 30);
    lv_obj_set_x(ui_ButtonCancelStartDateScheduleItem, 130);
    lv_obj_set_y(ui_ButtonCancelStartDateScheduleItem, -100);
    lv_obj_set_align(ui_ButtonCancelStartDateScheduleItem, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonCancelStartDateScheduleItem, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonCancelStartDateScheduleItem, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonCancelStartDateScheduleItem, lv_color_hex(0xFF0000),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonCancelStartDateScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelCancelStartDateScheduleItem = lv_label_create(ui_ButtonCancelStartDateScheduleItem);
    lv_obj_set_width(ui_LabelCancelStartDateScheduleItem, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelCancelStartDateScheduleItem, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelCancelStartDateScheduleItem, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelCancelStartDateScheduleItem, "Cancel");
    lv_obj_set_style_text_font(ui_LabelCancelStartDateScheduleItem, &lv_font_montserrat_12,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_ButtonOKStartDateScheduleItem, ui_event_ButtonOKStartDateScheduleItem, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonCancelStartDateScheduleItem, ui_event_ButtonCancelStartDateScheduleItem, LV_EVENT_ALL,
                        NULL);
    lv_obj_add_event_cb(ui_CalendarStartDateScheduleItem, ui_event_CalendarStartDateScheduleItem, LV_EVENT_ALL, NULL);

}
