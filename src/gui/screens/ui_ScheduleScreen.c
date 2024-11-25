// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: m5core2

#include "../ui.h"

void ui_ScheduleScreen_screen_init(void)
{
    ui_ScheduleScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScheduleScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_MainScheduleScreen = lv_obj_create(ui_ScheduleScreen);
    lv_obj_set_width(ui_MainScheduleScreen, 320);
    lv_obj_set_height(ui_MainScheduleScreen, 240);
    lv_obj_set_align(ui_MainScheduleScreen, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_MainScheduleScreen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_MainScheduleScreen, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_MainScheduleScreen, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_MainScheduleScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_MainScheduleScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TitleScheduleScreen = lv_obj_create(ui_MainScheduleScreen);
    lv_obj_set_width(ui_TitleScheduleScreen, LV_SIZE_CONTENT);
    lv_obj_set_style_max_width(ui_TitleScheduleScreen, 260, 0);
    lv_obj_set_height(ui_TitleScheduleScreen, 40);
    lv_obj_set_align(ui_TitleScheduleScreen, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_TitleScheduleScreen, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_TitleScheduleScreen, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_add_flag(ui_TitleScheduleScreen,
                    LV_OBJ_FLAG_SCROLL_ON_FOCUS | LV_OBJ_FLAG_SCROLL_WITH_ARROW | LV_OBJ_FLAG_SCROLL_ONE);    /// Flags
    lv_obj_set_scroll_dir(ui_TitleScheduleScreen, LV_DIR_HOR);
    lv_obj_scroll_to_x(ui_TitleScheduleScreen, 0, LV_ANIM_OFF);
    lv_obj_set_style_bg_color(ui_TitleScheduleScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TitleScheduleScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_TitleScheduleScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_TitleScheduleScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_TitleScheduleScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_TitleScheduleScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_TitleScheduleScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_TitleScheduleScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_TitleScheduleScreen, lv_color_hex(0xFFFFFF), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_TitleScheduleScreen, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    // Create the scrollable container below the title
    ui_ScheduleContainer = lv_obj_create(ui_MainScheduleScreen);
    lv_obj_clear_flag(ui_ScheduleContainer, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_width(ui_ScheduleContainer, 290);   // Set the width to fit within the main screen
    lv_obj_set_height(ui_ScheduleContainer, LV_SIZE_CONTENT);  // Let the height adapt based on the content
    lv_obj_set_flex_flow(ui_ScheduleContainer, LV_FLEX_FLOW_COLUMN);  // Arrange children vertically
    lv_obj_set_align(ui_ScheduleContainer, LV_ALIGN_TOP_MID);  // Align container in the middle of the main schedule screen
    lv_obj_set_scroll_dir(ui_ScheduleContainer, LV_DIR_VER);   // Enable vertical scrolling
    lv_obj_set_scroll_snap_y(ui_ScheduleContainer, LV_SCROLL_SNAP_CENTER);  // Snap to the center while scrolling
    lv_obj_set_style_bg_opa(ui_ScheduleContainer, LV_OPA_TRANSP, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ScheduleContainer, 5, LV_PART_MAIN | LV_STATE_DEFAULT); // Padding for better spacing
    // Remove the frame/border of the container
    lv_obj_set_style_border_width(ui_ScheduleContainer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);  // Set border width to 0
    lv_obj_set_style_border_opa(ui_ScheduleContainer, LV_OPA_TRANSP, LV_PART_MAIN | LV_STATE_DEFAULT);  // Set border opacity to transparent

    lv_obj_add_event_cb(ui_ScheduleScreen, ui_event_ScheduleScreen, LV_EVENT_ALL, NULL);




}
