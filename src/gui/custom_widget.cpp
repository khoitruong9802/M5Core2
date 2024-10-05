#include "custom_widget.h"

#include <M5Unified.h>

#include "../services/wifi_service.h"
#include "ui.h"

static void ta_event_cb(lv_event_t *e);

static lv_obj_t *kb;
lv_obj_t *enter_password_panel;
lv_obj_t *wifi_name_label;

void enter_password_widget_init(void) {
  enter_password_panel = lv_obj_create(ui_WifiScreen);
  lv_obj_set_width(enter_password_panel, 320);
  lv_obj_set_height(enter_password_panel, 240);
  lv_obj_set_align(enter_password_panel, LV_ALIGN_CENTER);
  lv_obj_add_flag(enter_password_panel, LV_OBJ_FLAG_HIDDEN);  /// Flags
  lv_obj_set_style_radius(enter_password_panel, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(enter_password_panel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(enter_password_panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

  /*Create the password box*/
  lv_obj_t *pwd_ta = lv_textarea_create(enter_password_panel);
  lv_textarea_set_text(pwd_ta, "");
  lv_textarea_set_password_mode(pwd_ta, true);
  lv_textarea_set_one_line(pwd_ta, true);
  lv_obj_set_pos(pwd_ta, 5, 20);
  lv_obj_add_event_cb(pwd_ta, ta_event_cb, LV_EVENT_ALL, NULL);

  /*Create a label and position it above the text box*/
  lv_obj_t *pwd_label = lv_label_create(enter_password_panel);
  lv_label_set_text(pwd_label, "Password of ");
  lv_obj_set_style_text_color(pwd_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_align_to(pwd_label, pwd_ta, LV_ALIGN_OUT_TOP_LEFT, 0, -5);

  wifi_name_label = lv_label_create(enter_password_panel);
  lv_label_set_text(wifi_name_label, "");
  lv_obj_set_style_text_color(wifi_name_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_align_to(wifi_name_label, pwd_label, LV_ALIGN_OUT_RIGHT_MID, 0, 0);

  /*Create a keyboard*/
  kb = lv_keyboard_create(enter_password_panel);
  lv_obj_set_size(kb, LV_HOR_RES, LV_VER_RES / 2);

  lv_keyboard_set_textarea(kb, pwd_ta); /*Focus it on one of the text areas to start*/
}

static void ta_event_cb(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *ta = lv_event_get_target(e);
  if (code == LV_EVENT_CLICKED || code == LV_EVENT_FOCUSED) {
    /*Focus on the clicked text area*/
    if (kb != NULL) lv_keyboard_set_textarea(kb, ta);
  }

  else if (code == LV_EVENT_READY) {
    Serial.printf("username: %s, password: %s", lv_label_get_text(wifi_name_label), lv_textarea_get_text(ta));
    WifiCredentials *wifiCredentials = new WifiCredentials;
    wifiCredentials->username = lv_label_get_text(wifi_name_label);
    wifiCredentials->password = lv_textarea_get_text(ta);
    xTaskCreatePinnedToCore(wifi_service, "wifi_service", 2048, (void *)wifiCredentials, 5, NULL, tskNO_AFFINITY);
    lv_textarea_set_text(ta, "");
    _ui_flag_modify(enter_password_panel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
  }
}

lv_obj_t *custom_ui_ListOfWifi;
void list_wifi_widget_init() {
  custom_ui_ListOfWifi = lv_list_create(ui_WifiScreen);
  lv_obj_set_size(custom_ui_ListOfWifi, 320, 240);
  lv_obj_center(custom_ui_ListOfWifi);

  /*Add buttons to the list*/
  lv_list_add_text(custom_ui_ListOfWifi, "Wifi");
}