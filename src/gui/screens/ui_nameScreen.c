// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: m5core2

#include "../ui.h"

void ui_name_screen_init(void)
{
    ui_name = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_name, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);      /// Flags
    lv_obj_set_scrollbar_mode(ui_name, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_bg_color(ui_name, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_name, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_name, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_name, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NameScheduleItemScreen = lv_obj_create(ui_name);
    lv_obj_set_width(ui_NameScheduleItemScreen, 320);
    lv_obj_set_height(ui_NameScheduleItemScreen, 240);
    lv_obj_set_align(ui_NameScheduleItemScreen, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_NameScheduleItemScreen,
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_scroll_dir(ui_NameScheduleItemScreen, LV_DIR_VER);
    lv_obj_set_style_radius(ui_NameScheduleItemScreen, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NameScheduleItemScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NameScheduleItemScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelCloseButtonNameScheduleItem = lv_obj_create(ui_NameScheduleItemScreen);
    lv_obj_set_width(ui_PanelCloseButtonNameScheduleItem, 30);
    lv_obj_set_height(ui_PanelCloseButtonNameScheduleItem, 30);
    lv_obj_set_x(ui_PanelCloseButtonNameScheduleItem, 136);
    lv_obj_set_y(ui_PanelCloseButtonNameScheduleItem, -100);
    lv_obj_set_align(ui_PanelCloseButtonNameScheduleItem, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelCloseButtonNameScheduleItem, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelCloseButtonNameScheduleItem, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelCloseButtonNameScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelCloseButtonNameScheduleItem = lv_label_create(ui_PanelCloseButtonNameScheduleItem);
    lv_obj_set_width(ui_LabelCloseButtonNameScheduleItem, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelCloseButtonNameScheduleItem, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelCloseButtonNameScheduleItem, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelCloseButtonNameScheduleItem, "X");
    lv_obj_set_style_text_color(ui_LabelCloseButtonNameScheduleItem, lv_color_hex(0xFFFFFF),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelCloseButtonNameScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelTextAreaNameScheduleItem = lv_obj_create(ui_NameScheduleItemScreen);
    lv_obj_set_width(ui_PanelTextAreaNameScheduleItem, 300);
    lv_obj_set_height(ui_PanelTextAreaNameScheduleItem, 50);
    lv_obj_set_x(ui_PanelTextAreaNameScheduleItem, 0);
    lv_obj_set_y(ui_PanelTextAreaNameScheduleItem, 20);
    lv_obj_set_align(ui_PanelTextAreaNameScheduleItem, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_PanelTextAreaNameScheduleItem, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelTextAreaNameScheduleItem, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelTextAreaNameScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelTextAreaNameScheduleItem, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelTextAreaNameScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_PanelTextAreaNameScheduleItem, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_PanelTextAreaNameScheduleItem, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_PanelTextAreaNameScheduleItem, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_PanelTextAreaNameScheduleItem, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextAreaNameScheduleItem = lv_textarea_create(ui_PanelTextAreaNameScheduleItem);
    lv_obj_set_width(ui_TextAreaNameScheduleItem, 290);
    lv_obj_set_height(ui_TextAreaNameScheduleItem, 40);
    lv_obj_set_align(ui_TextAreaNameScheduleItem, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_TextAreaNameScheduleItem, " ");
    lv_textarea_set_placeholder_text(ui_TextAreaNameScheduleItem, "Enter here...");

    ui_KeyboardNameScheduleItem = lv_keyboard_create(ui_NameScheduleItemScreen);
    lv_obj_set_width(ui_KeyboardNameScheduleItem, 310);
    lv_obj_set_height(ui_KeyboardNameScheduleItem, 149);
    lv_obj_set_x(ui_KeyboardNameScheduleItem, 0);
    lv_obj_set_y(ui_KeyboardNameScheduleItem, 10);
    lv_obj_set_align(ui_KeyboardNameScheduleItem, LV_ALIGN_BOTTOM_MID);
    lv_keyboard_set_textarea(ui_KeyboardNameScheduleItem, ui_TextAreaNameScheduleItem);

    ui_LabelTitleNameScheduleItem = lv_label_create(ui_name);
    lv_obj_set_width(ui_LabelTitleNameScheduleItem, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelTitleNameScheduleItem, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelTitleNameScheduleItem, 0);
    lv_obj_set_y(ui_LabelTitleNameScheduleItem, 12);
    lv_obj_set_align(ui_LabelTitleNameScheduleItem, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_LabelTitleNameScheduleItem, "Name");
    lv_obj_set_style_text_color(ui_LabelTitleNameScheduleItem, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTitleNameScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_PanelCloseButtonNameScheduleItem, ui_event_PanelCloseButtonNameScheduleItem, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TextAreaNameScheduleItem, ui_event_TextAreaNameScheduleItem, LV_EVENT_ALL, NULL);

}
