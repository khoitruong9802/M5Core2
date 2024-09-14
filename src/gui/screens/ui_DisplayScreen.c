// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: m5core2

#include "../ui.h"

void ui_DisplayScreen_screen_init(void)
{
    ui_DisplayScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_DisplayScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_DisplayScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DisplayScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_DisplayScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_DisplayScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel37 = lv_obj_create(ui_DisplayScreen);
    lv_obj_set_width(ui_Panel37, 320);
    lv_obj_set_height(ui_Panel37, 240);
    lv_obj_set_align(ui_Panel37, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel37, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel37, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel37, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel37, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel48 = lv_obj_create(ui_DisplayScreen);
    lv_obj_set_width(ui_Panel48, 270);
    lv_obj_set_height(ui_Panel48, 200);
    lv_obj_set_align(ui_Panel48, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Panel48, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Panel48, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_scroll_dir(ui_Panel48, LV_DIR_VER);
    lv_obj_set_style_radius(ui_Panel48, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel48, lv_color_hex(0x282828), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel48, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel48, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel48, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label28 = lv_label_create(ui_Panel48);
    lv_obj_set_width(ui_Label28, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label28, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label28, 88);
    lv_obj_set_y(ui_Label28, -7);
    lv_obj_set_align(ui_Label28, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label28, "Brightness");
    lv_obj_set_style_text_color(ui_Label28, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label28, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label28, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel38 = lv_obj_create(ui_Panel48);
    lv_obj_set_width(ui_Panel38, 260);
    lv_obj_set_height(ui_Panel38, 34);
    lv_obj_set_x(ui_Panel38, -1);
    lv_obj_set_y(ui_Panel38, 29);
    lv_obj_set_align(ui_Panel38, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel38, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel38, lv_color_hex(0x525252), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel38, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui_Panel38, true, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Panel38, &ui_img_brightness_bar_icon_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel38, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel38, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Slider3 = lv_slider_create(ui_Panel38);
    lv_slider_set_range(ui_Slider3, 20, 240);
    lv_slider_set_value(ui_Slider3, 128, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Slider3) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Slider3, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_Slider3, 189);
    lv_obj_set_height(ui_Slider3, 24);
    lv_obj_set_align(ui_Slider3, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_Slider3, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider3, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Slider3, lv_color_hex(0xC8C8C8), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Slider3, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Slider3, 1, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Label30 = lv_label_create(ui_Panel48);
    lv_obj_set_width(ui_Label30, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label30, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label30, 88);
    lv_obj_set_y(ui_Label30, -7);
    lv_obj_set_align(ui_Label30, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label30, "Color");
    lv_obj_set_style_text_color(ui_Label30, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label30, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label30, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Dropdown1 = lv_dropdown_create(ui_Panel48);
    lv_dropdown_set_options(ui_Dropdown1, "16 bits pixel\n8 bits pixel");
    lv_obj_set_width(ui_Dropdown1, 260);
    lv_obj_set_height(ui_Dropdown1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Dropdown1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Dropdown1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_font(ui_Dropdown1, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);



    lv_obj_add_event_cb(ui_Slider3, ui_event_Slider3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_DisplayScreen, ui_event_DisplayScreen, LV_EVENT_ALL, NULL);

}
