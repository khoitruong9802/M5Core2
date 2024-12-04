// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: m5core2

#include "../ui.h"

void ui_SoidEC_screen_init(void)
{
    ui_SoidEC = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SoidEC, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_SoidEC, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SoidEC, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SoidEC, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SoidEC, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SoidECScreen = lv_obj_create(ui_SoidEC);
    lv_obj_set_width(ui_SoidECScreen, 320);
    lv_obj_set_height(ui_SoidECScreen, 240);
    lv_obj_set_align(ui_SoidECScreen, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_SoidECScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SoidECScreen, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SoidECScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SoidECScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChartSoidEC = lv_chart_create(ui_SoidECScreen);
    lv_obj_set_width(ui_ChartSoidEC, 249);
    lv_obj_set_height(ui_ChartSoidEC, 155);
    lv_obj_set_x(ui_ChartSoidEC, 0);
    lv_obj_set_y(ui_ChartSoidEC, 20);
    lv_obj_set_align(ui_ChartSoidEC, LV_ALIGN_CENTER);
    lv_chart_set_type(ui_ChartSoidEC, LV_CHART_TYPE_LINE);
    lv_chart_set_point_count(ui_ChartSoidEC, 8);
    lv_chart_set_axis_tick(ui_ChartSoidEC, LV_CHART_AXIS_PRIMARY_X, 1, 0, 8, 2, true, 50);
    lv_chart_set_axis_tick(ui_ChartSoidEC, LV_CHART_AXIS_PRIMARY_Y, 2, 5, 11, 2, true, 50);
    lv_chart_set_axis_tick(ui_ChartSoidEC, LV_CHART_AXIS_SECONDARY_Y, 10, 5, 5, 2, false, 25);
    lv_chart_series_t * ui_ChartSoidEC_series_1 = lv_chart_add_series(ui_ChartSoidEC, lv_color_hex(0x808080),
                                                                      LV_CHART_AXIS_PRIMARY_Y);
    static lv_coord_t ui_ChartSoidEC_series_1_array[] = { 10, 20, 4, 80, 40, 70, 25, 96 };
    lv_chart_set_ext_y_array(ui_ChartSoidEC, ui_ChartSoidEC_series_1, ui_ChartSoidEC_series_1_array);



    ui_LabelSoidEC = lv_label_create(ui_SoidECScreen);
    lv_obj_set_width(ui_LabelSoidEC, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelSoidEC, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelSoidEC, 0);
    lv_obj_set_y(ui_LabelSoidEC, -90);
    lv_obj_set_align(ui_LabelSoidEC, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelSoidEC, "Soid EC");
    lv_obj_set_style_text_color(ui_LabelSoidEC, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSoidEC, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSoidEC, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

}
