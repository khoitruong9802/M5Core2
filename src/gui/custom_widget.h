#pragma once
#include <lvgl.h>

extern lv_obj_t *enter_password_panel;
extern lv_obj_t *custom_ui_ListOfWifi;
extern lv_obj_t *wifi_name_label;
extern lv_obj_t *esc_btn;
extern lv_obj_t *esc_label;
void list_wifi_widget_init();
void enter_password_widget_init();