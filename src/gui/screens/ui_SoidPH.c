// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: m5core2

#include "../ui.h"

void ui_SoidPH_screen_init(void)
{
    ui_SoidPH = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SoidPH, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_SoidPH, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SoidPH, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SoidPH, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SoidPH, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SoidPHScreen = lv_obj_create(ui_SoidPH);
    lv_obj_set_width(ui_SoidPHScreen, 320);
    lv_obj_set_height(ui_SoidPHScreen, 240);
    lv_obj_set_align(ui_SoidPHScreen, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_SoidPHScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SoidPHScreen, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SoidPHScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SoidPHScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChartSoidPH = lv_chart_create(ui_SoidPHScreen);
    lv_obj_set_width(ui_ChartSoidPH, 249);
    lv_obj_set_height(ui_ChartSoidPH, 155);
    lv_obj_set_x(ui_ChartSoidPH, 0);
    lv_obj_set_y(ui_ChartSoidPH, 20);
    lv_obj_set_align(ui_ChartSoidPH, LV_ALIGN_CENTER);
    lv_chart_set_type(ui_ChartSoidPH, LV_CHART_TYPE_LINE);
    lv_chart_set_point_count(ui_ChartSoidPH, 8);
    lv_chart_set_axis_tick(ui_ChartSoidPH, LV_CHART_AXIS_PRIMARY_X, 1, 0, 8, 2, true, 50);
    lv_chart_set_axis_tick(ui_ChartSoidPH, LV_CHART_AXIS_PRIMARY_Y, 2, 5, 11, 2, true, 50);
    lv_chart_set_axis_tick(ui_ChartSoidPH, LV_CHART_AXIS_SECONDARY_Y, 10, 5, 5, 2, false, 25);
    lv_chart_series_t * ui_ChartSoidPH_series_1 = lv_chart_add_series(ui_ChartSoidPH, lv_color_hex(0x808080),
                                                                      LV_CHART_AXIS_PRIMARY_Y);
    static lv_coord_t ui_ChartSoidPH_series_1_array[] = { 10, 20, 4, 80, 40, 70, 25, 96 };
    lv_chart_set_ext_y_array(ui_ChartSoidPH, ui_ChartSoidPH_series_1, ui_ChartSoidPH_series_1_array);



    ui_labelTitleSoidPH = lv_label_create(ui_SoidPHScreen);
    lv_obj_set_width(ui_labelTitleSoidPH, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelTitleSoidPH, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelTitleSoidPH, 0);
    lv_obj_set_y(ui_labelTitleSoidPH, -90);
    lv_obj_set_align(ui_labelTitleSoidPH, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelTitleSoidPH, "Soid PH");
    lv_obj_set_style_text_color(ui_labelTitleSoidPH, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_labelTitleSoidPH, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_labelTitleSoidPH, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

}
