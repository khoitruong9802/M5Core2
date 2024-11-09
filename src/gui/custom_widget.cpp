#include "custom_widget.h"
#include <M5Unified.h>

#include "../services/wifi_service.h"
#include "../global.h"
#include "ui.h"

static void ta_event_cb(lv_event_t *e);

static lv_obj_t *kb;
lv_obj_t *enter_password_panel;
lv_obj_t *wifi_name_label;
lv_obj_t *esc_btn;
lv_obj_t *esc_label;
lv_obj_t *sinking_label;
static void ui_event_esc_btn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED)
    {
        print(PRINTLN,"Button escape clicked");
        lv_indev_wait_release(lv_indev_get_act());
        _ui_flag_modify(enter_password_panel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}

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
  lv_obj_set_pos(pwd_ta, 5, 15);
  lv_obj_add_event_cb(pwd_ta, ta_event_cb, LV_EVENT_ALL, NULL);

  /* Create the "sinking" label as a child of the textarea */
  sinking_label = lv_label_create(pwd_ta);
  lv_label_set_text(sinking_label, "Enter Password");
  lv_obj_set_style_text_color(sinking_label, lv_palette_main(LV_PALETTE_GREY), 0); // Optional: change color
  lv_obj_align(sinking_label, LV_ALIGN_TOP_LEFT, 5, 8);  // Initial position inside textarea

  /*Create a label and position it above the text box*/
  lv_obj_t *pwd_label = lv_label_create(enter_password_panel);
  lv_label_set_text(pwd_label, "");
  lv_obj_set_style_text_color(pwd_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_align_to(pwd_label, pwd_ta, LV_ALIGN_OUT_TOP_LEFT, 0, -5);
  lv_obj_set_style_text_font(pwd_label, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

  wifi_name_label = lv_label_create(enter_password_panel);
  lv_label_set_text(wifi_name_label, "");
  lv_obj_set_style_text_color(wifi_name_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(wifi_name_label, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_align_to(wifi_name_label, pwd_label, LV_ALIGN_OUT_RIGHT_MID, 0, 0);
  
  /*Create a escape button to back to the previous screen*/
  esc_btn = lv_btn_create(enter_password_panel);
  lv_obj_set_width(esc_btn, 30);
  lv_obj_set_height(esc_btn, 30);
  lv_obj_set_x(esc_btn, 140);
  lv_obj_set_y(esc_btn, -102);
  lv_obj_set_align(esc_btn, LV_ALIGN_CENTER);
  lv_obj_add_flag(esc_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
  lv_obj_clear_flag(esc_btn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
  lv_obj_set_style_bg_color(esc_btn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(esc_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(esc_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_width(esc_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_spread(esc_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_add_event_cb(esc_btn, ui_event_esc_btn, LV_EVENT_ALL, NULL);

  esc_label = lv_label_create(esc_btn);
  lv_obj_set_width(esc_label, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(esc_label, LV_SIZE_CONTENT);    /// 1
  lv_obj_set_align(esc_label, LV_ALIGN_CENTER);
  lv_label_set_text(esc_label, "X");
  lv_obj_set_style_text_font(esc_label, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

  /*Create a keyboard*/
  kb = lv_keyboard_create(enter_password_panel);
  lv_obj_set_size(kb, 320, 150);

  lv_keyboard_set_textarea(kb, pwd_ta); /*Focus it on one of the text areas to start*/
}

static void ta_event_cb(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *ta = lv_event_get_target(e);
  if (code == LV_EVENT_CLICKED || code == LV_EVENT_FOCUSED) {
    /*Focus on the clicked text area*/
    lv_obj_add_flag(sinking_label, LV_OBJ_FLAG_HIDDEN);
    if (kb != NULL) lv_keyboard_set_textarea(kb, ta);
  }

  else if (code == LV_EVENT_READY) {
    WifiCredentials *wifiCredentials = new WifiCredentials;
    // Assign the username and password
    strncpy(wifiCredentials->username, lv_label_get_text(wifi_name_label), sizeof(wifiCredentials->username));
    wifiCredentials->username[sizeof(wifiCredentials->username) - 1] = '\0'; // Null-terminate just in case
    strncpy(wifiCredentials->password, lv_textarea_get_text(ta), sizeof(wifiCredentials->password));
    wifiCredentials->password[sizeof(wifiCredentials->password) - 1] = '\0'; // Null-terminate just in case
    // Save the credentials to the database
    print(PRINTF,"username: %s, password: %s\n", wifiCredentials->username, wifiCredentials->password);
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