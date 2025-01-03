// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: m5core2

#include "../ui.h"

void ui_ThresHoldItemScreen1_screen_init(void)
{
    ui_ThresHoldItemScreen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ThresHoldItemScreen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ThresHoldItemContainer1 = lv_obj_create(ui_ThresHoldItemScreen1);
    lv_obj_set_width(ui_ThresHoldItemContainer1, 320);
    lv_obj_set_height(ui_ThresHoldItemContainer1, 240);
    lv_obj_set_align(ui_ThresHoldItemContainer1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ThresHoldItemContainer1,
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_scroll_dir(ui_ThresHoldItemContainer1, LV_DIR_VER);
    lv_obj_set_style_radius(ui_ThresHoldItemContainer1, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ThresHoldItemContainer1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ThresHoldItemContainer1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTitleThresHoldItem1 = lv_label_create(ui_ThresHoldItemContainer1);
    lv_obj_set_width(ui_LabelTitleThresHoldItem1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelTitleThresHoldItem1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelTitleThresHoldItem1, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_LabelTitleThresHoldItem1, "Temperature Min");
    lv_obj_set_style_text_color(ui_LabelTitleThresHoldItem1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTitleThresHoldItem1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelButtonXThresHoldItem1 = lv_obj_create(ui_ThresHoldItemContainer1);
    lv_obj_set_width(ui_PanelButtonXThresHoldItem1, 30);
    lv_obj_set_height(ui_PanelButtonXThresHoldItem1, 30);
    lv_obj_set_x(ui_PanelButtonXThresHoldItem1, 136);
    lv_obj_set_y(ui_PanelButtonXThresHoldItem1, -100);
    lv_obj_set_align(ui_PanelButtonXThresHoldItem1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelButtonXThresHoldItem1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelButtonXThresHoldItem1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelButtonXThresHoldItem1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelButtonXThresHoldItem1 = lv_label_create(ui_PanelButtonXThresHoldItem1);
    lv_obj_set_width(ui_LabelButtonXThresHoldItem1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelButtonXThresHoldItem1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelButtonXThresHoldItem1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelButtonXThresHoldItem1, "X");
    lv_obj_set_style_text_color(ui_LabelButtonXThresHoldItem1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelButtonXThresHoldItem1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_KeyboardThresHoldItem1 = lv_keyboard_create(ui_ThresHoldItemContainer1);
    lv_keyboard_set_mode(ui_KeyboardThresHoldItem1, LV_KEYBOARD_MODE_NUMBER);
    lv_obj_set_width(ui_KeyboardThresHoldItem1, 310);
    lv_obj_set_height(ui_KeyboardThresHoldItem1, 149);
    lv_obj_set_x(ui_KeyboardThresHoldItem1, 0);
    lv_obj_set_y(ui_KeyboardThresHoldItem1, 10);
    lv_obj_set_align(ui_KeyboardThresHoldItem1, LV_ALIGN_BOTTOM_MID);

    ui_PanelThresHoldItemContainer1 = lv_obj_create(ui_ThresHoldItemContainer1);
    lv_obj_set_width(ui_PanelThresHoldItemContainer1, 300);
    lv_obj_set_height(ui_PanelThresHoldItemContainer1, 50);
    lv_obj_set_x(ui_PanelThresHoldItemContainer1, 0);
    lv_obj_set_y(ui_PanelThresHoldItemContainer1, -60);
    lv_obj_set_align(ui_PanelThresHoldItemContainer1, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PanelThresHoldItemContainer1, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_PanelThresHoldItemContainer1, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_PanelThresHoldItemContainer1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelThresHoldItemContainer1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelThresHoldItemContainer1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelThresHoldItemContainer1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelThresHoldItemContainer1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_PanelThresHoldItemContainer1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_PanelThresHoldItemContainer1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_PanelThresHoldItemContainer1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_PanelThresHoldItemContainer1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextAreaThresHoldItem1 = lv_textarea_create(ui_PanelThresHoldItemContainer1);
    lv_obj_set_width(ui_TextAreaThresHoldItem1, 226);
    lv_obj_set_height(ui_TextAreaThresHoldItem1, 37);
    lv_obj_set_x(ui_TextAreaThresHoldItem1, 7);
    lv_obj_set_y(ui_TextAreaThresHoldItem1, 26);
    lv_obj_set_align(ui_TextAreaThresHoldItem1, LV_ALIGN_CENTER);



    lv_obj_add_event_cb(ui_PanelButtonXThresHoldItem1, ui_event_PanelButtonXThresHoldItem1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TextAreaThresHoldItem1, ui_event_TextAreaThresHoldItem1, LV_EVENT_ALL, NULL);
    lv_keyboard_set_textarea(ui_KeyboardThresHoldItem1, ui_TextAreaThresHoldItem1);

}
