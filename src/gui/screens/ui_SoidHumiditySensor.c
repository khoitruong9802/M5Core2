// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: m5core2

#include "../ui.h"

void ui_SoidHumiditySensor_screen_init(void)
{
    ui_SoidHumiditySensor = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SoidHumiditySensor, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_SoidHumiditySensor, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SoidHumiditySensor, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SoidHumiditySensor, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SoidHumiditySensor, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SoidHumiditySensorScreen = lv_obj_create(ui_SoidHumiditySensor);
    lv_obj_set_width(ui_SoidHumiditySensorScreen, 320);
    lv_obj_set_height(ui_SoidHumiditySensorScreen, 240);
    lv_obj_set_align(ui_SoidHumiditySensorScreen, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_SoidHumiditySensorScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SoidHumiditySensorScreen, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SoidHumiditySensorScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SoidHumiditySensorScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChartSoidHumiditySensor = lv_chart_create(ui_SoidHumiditySensorScreen);
    lv_obj_set_width(ui_ChartSoidHumiditySensor, 249);
    lv_obj_set_height(ui_ChartSoidHumiditySensor, 155);
    lv_obj_set_x(ui_ChartSoidHumiditySensor, 0);
    lv_obj_set_y(ui_ChartSoidHumiditySensor, 20);
    lv_obj_set_align(ui_ChartSoidHumiditySensor, LV_ALIGN_CENTER);
    lv_chart_set_type(ui_ChartSoidHumiditySensor, LV_CHART_TYPE_LINE);
    lv_chart_set_point_count(ui_ChartSoidHumiditySensor, 8);
    lv_chart_set_axis_tick(ui_ChartSoidHumiditySensor, LV_CHART_AXIS_PRIMARY_X, 1, 0, 8, 2, true, 50);
    lv_chart_set_axis_tick(ui_ChartSoidHumiditySensor, LV_CHART_AXIS_PRIMARY_Y, 2, 5, 11, 2, true, 50);
    lv_chart_set_axis_tick(ui_ChartSoidHumiditySensor, LV_CHART_AXIS_SECONDARY_Y, 10, 5, 5, 2, false, 25);
    ui_ChartSoidHumiditySensor_series_1 = lv_chart_add_series(ui_ChartSoidHumiditySensor,
                                                                                  lv_color_hex(0x808080), LV_CHART_AXIS_PRIMARY_Y);
    static lv_coord_t ui_ChartSoidHumiditySensor_series_1_array[] = { 10, 20, 4, 80, 40, 70, 25, 96 };
    lv_chart_set_ext_y_array(ui_ChartSoidHumiditySensor, ui_ChartSoidHumiditySensor_series_1,
                             ui_ChartSoidHumiditySensor_series_1_array);



    ui_LabelTitleSoidHumiditySensor = lv_label_create(ui_SoidHumiditySensorScreen);
    lv_obj_set_width(ui_LabelTitleSoidHumiditySensor, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelTitleSoidHumiditySensor, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelTitleSoidHumiditySensor, 0);
    lv_obj_set_y(ui_LabelTitleSoidHumiditySensor, -90);
    lv_obj_set_align(ui_LabelTitleSoidHumiditySensor, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelTitleSoidHumiditySensor, "Humidity");
    lv_obj_set_style_text_color(ui_LabelTitleSoidHumiditySensor, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTitleSoidHumiditySensor, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTitleSoidHumiditySensor, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_SoidHumiditySensor, ui_event_SoidHumiditySensor, LV_EVENT_ALL, NULL);

}
