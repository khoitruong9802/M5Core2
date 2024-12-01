// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: m5core2

#include "../ui.h"

void ui_Flow2_screen_init(void)
{
    ui_Flow2 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Flow2, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);    /// Flags
    lv_obj_set_scrollbar_mode(ui_Flow2, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_bg_color(ui_Flow2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Flow2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Flow2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Flow2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Flow2ScheduleItemScreen = lv_obj_create(ui_Flow2);
    lv_obj_set_width(ui_Flow2ScheduleItemScreen, 320);
    lv_obj_set_height(ui_Flow2ScheduleItemScreen, 240);
    lv_obj_set_align(ui_Flow2ScheduleItemScreen, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Flow2ScheduleItemScreen,
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_scroll_dir(ui_Flow2ScheduleItemScreen, LV_DIR_VER);
    lv_obj_set_style_radius(ui_Flow2ScheduleItemScreen, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Flow2ScheduleItemScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Flow2ScheduleItemScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTitleFlow2ScheduleItem = lv_label_create(ui_Flow2ScheduleItemScreen);
    lv_obj_set_width(ui_LabelTitleFlow2ScheduleItem, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelTitleFlow2ScheduleItem, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelTitleFlow2ScheduleItem, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_LabelTitleFlow2ScheduleItem, "Flow 2");
    lv_obj_set_style_text_color(ui_LabelTitleFlow2ScheduleItem, lv_color_hex(0xFFFFFF),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTitleFlow2ScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelCloseButtonFlow2ScheduleItem = lv_obj_create(ui_Flow2ScheduleItemScreen);
    lv_obj_set_width(ui_PanelCloseButtonFlow2ScheduleItem, 30);
    lv_obj_set_height(ui_PanelCloseButtonFlow2ScheduleItem, 30);
    lv_obj_set_x(ui_PanelCloseButtonFlow2ScheduleItem, 136);
    lv_obj_set_y(ui_PanelCloseButtonFlow2ScheduleItem, -100);
    lv_obj_set_align(ui_PanelCloseButtonFlow2ScheduleItem, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelCloseButtonFlow2ScheduleItem, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelCloseButtonFlow2ScheduleItem, lv_color_hex(0x000000),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelCloseButtonFlow2ScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelCloseButtonFlow2ScheduleItem = lv_label_create(ui_PanelCloseButtonFlow2ScheduleItem);
    lv_obj_set_width(ui_LabelCloseButtonFlow2ScheduleItem, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelCloseButtonFlow2ScheduleItem, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelCloseButtonFlow2ScheduleItem, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelCloseButtonFlow2ScheduleItem, "X");
    lv_obj_set_style_text_color(ui_LabelCloseButtonFlow2ScheduleItem, lv_color_hex(0xFFFFFF),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelCloseButtonFlow2ScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_PanelTextAreaFlow2ScheduleItem = lv_obj_create(ui_Flow2ScheduleItemScreen);
    lv_obj_set_width(ui_PanelTextAreaFlow2ScheduleItem, 300);
    lv_obj_set_height(ui_PanelTextAreaFlow2ScheduleItem, 50);
    lv_obj_set_x(ui_PanelTextAreaFlow2ScheduleItem, 0);
    lv_obj_set_y(ui_PanelTextAreaFlow2ScheduleItem, -60);
    lv_obj_set_align(ui_PanelTextAreaFlow2ScheduleItem, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PanelTextAreaFlow2ScheduleItem, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_PanelTextAreaFlow2ScheduleItem, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_PanelTextAreaFlow2ScheduleItem, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelTextAreaFlow2ScheduleItem, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelTextAreaFlow2ScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelTextAreaFlow2ScheduleItem, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelTextAreaFlow2ScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_PanelTextAreaFlow2ScheduleItem, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_PanelTextAreaFlow2ScheduleItem, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_PanelTextAreaFlow2ScheduleItem, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_PanelTextAreaFlow2ScheduleItem, 0, LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_TextAreaFlow2ScheduleItem = lv_textarea_create(ui_PanelTextAreaFlow2ScheduleItem);
    lv_obj_set_width(ui_TextAreaFlow2ScheduleItem, 226);
    lv_obj_set_height(ui_TextAreaFlow2ScheduleItem, 37);
    lv_obj_set_x(ui_TextAreaFlow2ScheduleItem, 7);
    lv_obj_set_y(ui_TextAreaFlow2ScheduleItem, 26);
    lv_obj_set_align(ui_TextAreaFlow2ScheduleItem, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_TextAreaFlow2ScheduleItem, "111");
    lv_textarea_set_placeholder_text(ui_TextAreaFlow2ScheduleItem, "Enter here...");

    ui_LabelUnitFlow2ScheduleItem = lv_label_create(ui_PanelTextAreaFlow2ScheduleItem);
    lv_obj_set_width(ui_LabelUnitFlow2ScheduleItem, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelUnitFlow2ScheduleItem, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelUnitFlow2ScheduleItem, 121);
    lv_obj_set_y(ui_LabelUnitFlow2ScheduleItem, 34);
    lv_obj_set_align(ui_LabelUnitFlow2ScheduleItem, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_LabelUnitFlow2ScheduleItem, "(l)");
    lv_obj_set_style_text_color(ui_LabelUnitFlow2ScheduleItem, lv_color_hex(0xFFFFFF),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelUnitFlow2ScheduleItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelUnitFlow2ScheduleItem, &lv_font_montserrat_20,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_KeyboardFlow2ScheduleItem = lv_keyboard_create(ui_Flow2ScheduleItemScreen);
    lv_keyboard_set_mode(ui_KeyboardFlow2ScheduleItem, LV_KEYBOARD_MODE_NUMBER);
    lv_obj_set_width(ui_KeyboardFlow2ScheduleItem, 310);
    lv_obj_set_height(ui_KeyboardFlow2ScheduleItem, 149);
    lv_obj_set_x(ui_KeyboardFlow2ScheduleItem, 0);
    lv_obj_set_y(ui_KeyboardFlow2ScheduleItem, 10);
    lv_obj_set_align(ui_KeyboardFlow2ScheduleItem, LV_ALIGN_BOTTOM_MID);

    lv_obj_add_event_cb(ui_PanelCloseButtonFlow2ScheduleItem, ui_event_PanelCloseButtonFlow2ScheduleItem,
                        LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TextAreaFlow2ScheduleItem, ui_event_TextAreaFlow2ScheduleItem, LV_EVENT_ALL, NULL);
    lv_keyboard_set_textarea(ui_KeyboardFlow2ScheduleItem, ui_TextAreaFlow2ScheduleItem);

}