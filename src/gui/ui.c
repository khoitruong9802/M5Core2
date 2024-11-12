// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: m5core2

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_MainScreen
void ui_MainScreen_screen_init(void);
lv_obj_t * ui_MainScreen;
lv_obj_t * ui_Panel2;
lv_obj_t * ui_header1;
lv_obj_t * ui_Image1;
lv_obj_t * ui_Image2;
lv_obj_t * ui_Slider2;
lv_obj_t * ui_Label1;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Label3;
lv_obj_t * ui_Label4;
void ui_event_Panel4(lv_event_t * e);
lv_obj_t * ui_Panel4;


// SCREEN: ui_AppScreen
void ui_AppScreen_screen_init(void);
void ui_event_AppScreen(lv_event_t * e);
lv_obj_t * ui_AppScreen;
lv_obj_t * ui_Panel5;
void ui_event_Panel6(lv_event_t * e);
lv_obj_t * ui_Panel6;
void ui_event_Panel3(lv_event_t * e);
lv_obj_t * ui_Panel3;
lv_obj_t * ui_Panel9;
lv_obj_t * ui_Label5;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_Panel7;
lv_obj_t * ui_Label6;
void ui_event_Panel11(lv_event_t * e);
lv_obj_t * ui_Panel11;
lv_obj_t * ui_Panel12;
lv_obj_t * ui_Label8;
lv_obj_t * ui_Panel8;
lv_obj_t * ui_Panel10;
lv_obj_t * ui_Label7;
void ui_event_Panel13(lv_event_t * e);
lv_obj_t * ui_Panel13;
lv_obj_t * ui_Panel14;
lv_obj_t * ui_Label10;
lv_obj_t * ui_Panel40;
lv_obj_t * ui_Spinner1;
lv_obj_t * ui_Panel41;
void ui_event_Button2(lv_event_t * e);
lv_obj_t * ui_Button2;
lv_obj_t * ui_Label35;
lv_obj_t * ui_Label34;
lv_obj_t * ui_Panel42;
lv_obj_t * ui_Label36;
lv_obj_t * ui_Panel49;
void ui_event_Button3(lv_event_t * e);
lv_obj_t * ui_Button3;
lv_obj_t * ui_Label37;
lv_obj_t * ui_Panel29;
lv_obj_t * ui_Label33;
lv_obj_t * ui_Panel39;
void ui_event_Button1(lv_event_t * e);
lv_obj_t * ui_Button1;
lv_obj_t * ui_Label31;
void ui_event_Panel90(lv_event_t * e);
lv_obj_t * ui_Panel90;
lv_obj_t * ui_Panel91;
lv_obj_t * ui_Label90;
// SCREEN: ui_SettingsScreen
void ui_SettingsScreen_screen_init(void);
void ui_event_SettingsScreen(lv_event_t * e);
lv_obj_t * ui_SettingsScreen;
lv_obj_t * ui_Panel15;
lv_obj_t * ui_Panel16;
void ui_event_Panel17(lv_event_t * e);
lv_obj_t * ui_Panel17;
lv_obj_t * ui_Panel18;
lv_obj_t * ui_Label9;
lv_obj_t * ui_Panel20;
lv_obj_t * ui_Panel21;
lv_obj_t * ui_Label11;
void ui_event_Panel24(lv_event_t * e);
lv_obj_t * ui_Panel24;
lv_obj_t * ui_Panel25;
lv_obj_t * ui_Label13;
lv_obj_t * ui_Panel22;
lv_obj_t * ui_Panel23;
lv_obj_t * ui_Label12;
lv_obj_t * ui_Panel100;
lv_obj_t * ui_Panel101;
void ui_event_Button21(lv_event_t * e);
lv_obj_t * ui_Button21;
void ui_event_Button22(lv_event_t * e);
lv_obj_t * ui_Button22;
lv_obj_t * ui_Label101;
lv_obj_t * ui_Label102;
lv_obj_t * ui_Label103;

// SCREEN: ui_AboutScreen
void ui_AboutScreen_screen_init(void);
void ui_event_AboutScreen(lv_event_t * e);
lv_obj_t * ui_AboutScreen;
lv_obj_t * ui_Panel19;
lv_obj_t * ui_Label14;


// SCREEN: ui_MqttScreen
void ui_MqttScreen_screen_init(void);
void ui_event_MqttScreen(lv_event_t * e);
lv_obj_t * ui_MqttScreen;
lv_obj_t * ui_Panel43;
lv_obj_t * ui_Panel44;
void ui_event_Panel45(lv_event_t * e);
lv_obj_t * ui_Panel45;
lv_obj_t * ui_Image3;
lv_obj_t * ui_Label23;
void ui_event_Panel46(lv_event_t * e);
lv_obj_t * ui_Panel46;
lv_obj_t * ui_Image4;
lv_obj_t * ui_Label24;
lv_obj_t * ui_Panel47;
lv_obj_t * ui_Image5;
lv_obj_t * ui_Label25;


// SCREEN: ui_SensorsScreen
void ui_SensorsScreen_screen_init(void);
void ui_event_SensorsScreen(lv_event_t * e);
lv_obj_t * ui_SensorsScreen;
lv_obj_t * ui_Panel31;
lv_obj_t * ui_Panel33;
lv_obj_t * ui_Label19;
lv_obj_t * ui_Label20;
lv_obj_t * ui_Label21;
lv_obj_t * ui_Label22;
lv_obj_t * ui_Label26;
lv_obj_t * ui_Label27;
lv_obj_t * ui_Label15;
lv_obj_t * ui_Label16;


// SCREEN: ui_ManualScreen
void ui_ManualScreen_screen_init(void);
void ui_event_ManualScreen(lv_event_t * e);
lv_obj_t * ui_ManualScreen;
lv_obj_t * ui_Panel35;
lv_obj_t * ui_Panel36;
lv_obj_t * ui_Panel28;
lv_obj_t * ui_Label32;
lv_obj_t * ui_Image6;
void ui_event_Switch1(lv_event_t * e);
lv_obj_t * ui_Switch1;
lv_obj_t * ui_Panel27;
lv_obj_t * ui_Label29;
lv_obj_t * ui_Image7;
void ui_event_Switch2(lv_event_t * e);
lv_obj_t * ui_Switch2;


// SCREEN: ui_DisplayScreen
void ui_DisplayScreen_screen_init(void);
void ui_event_DisplayScreen(lv_event_t * e);
lv_obj_t * ui_DisplayScreen;
lv_obj_t * ui_Panel37;
lv_obj_t * ui_Panel48;
lv_obj_t * ui_Label28;
lv_obj_t * ui_Panel38;
void ui_event_Slider3(lv_event_t * e);
lv_obj_t * ui_Slider3;
lv_obj_t * ui_Label30;
lv_obj_t * ui_Dropdown1;


// SCREEN: ui_WifiScreen
void ui_WifiScreen_screen_init(void);
void ui_event_WifiScreen(lv_event_t * e);
lv_obj_t * ui_WifiScreen;
lv_obj_t * ui_Panel26;
lv_obj_t * ui____initial_actions0;


// SCREEN: ui_OtaScreen
void ui_OtaScreen_screen_init(void);
void ui_event_OtaScreen(lv_event_t * e);
lv_obj_t * ui_OtaScreen;
lv_obj_t * ui_Panel92;
lv_obj_t * ui_Panel93;
lv_obj_t * ui_Spinner2;
void ui_event_Button11(lv_event_t * e);
lv_obj_t * ui_Button11;
lv_obj_t * ui_Label90;
lv_obj_t * ui_Label91;
lv_obj_t * ui_Panel94;

lv_obj_t * ui_Panel102;
lv_obj_t * ui_Panel103;
lv_obj_t * ui_Panel104;
lv_obj_t * ui_Panel105;
void ui_event_Button23(lv_event_t * e);
lv_obj_t * ui_Button23;
void ui_event_Button24(lv_event_t * e);
lv_obj_t * ui_Button24;
void ui_event_Button25(lv_event_t * e);
lv_obj_t * ui_Button25;
void ui_event_Button26(lv_event_t * e);
lv_obj_t * ui_Button26;
void ui_event_Button27(lv_event_t * e);
lv_obj_t * ui_Button27;
lv_obj_t * ui_Label104;
lv_obj_t * ui_Label105;
lv_obj_t * ui_Label106;
lv_obj_t * ui_Label107;
lv_obj_t * ui_Label108;
lv_obj_t * ui_Label109;
lv_obj_t * ui_Label110;

//  SCREEN: ui_ScheduleScreen
void ui_ScheduleScreen_screen_init(void);
void ui_event_ScheduleScreen(lv_event_t * e);
lv_obj_t *  ui_ScheduleScreen;
lv_obj_t *  ui_MainScheduleScreen;
lv_obj_t *  ui_TitleScheduleScreen;
lv_obj_t *  ui_ScheduleContainer;
lv_obj_t *  ui_PanelScheduleItem;
lv_obj_t *  ui_LabelScheduleItem;
lv_obj_t *  ui_PanelScheduleItemIngredient;
lv_obj_t *  ui_LabelScheduleItemIngredient1;
lv_obj_t *  ui_LabelScheduleItemIngredient2;
lv_obj_t *  ui_LabelScheduleItemIngredient3;
lv_obj_t *  ui_LabelScheduleItemTimer;
lv_obj_t *  ui_SwitchScheduleItem;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_Panel4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_AppScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_AppScreen_screen_init);
    }
}
void ui_event_AppScreen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_MainScreen, LV_SCR_LOAD_ANIM_FADE_ON, 250, 0, &ui_MainScreen_screen_init);
    }
}
void ui_event_Panel6(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_MainScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_MainScreen_screen_init);
    }
}
void ui_event_Panel3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_SettingsScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_SettingsScreen_screen_init);
    }
}
void ui_event_Panel11(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        schedule_screen_init(e);
    }
}
void ui_event_Panel13(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_AboutScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_AboutScreen_screen_init);
    }
}
void ui_event_Button2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Panel40, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}

void ui_event_Panel90(lv_event_t * e
){
    lv_event_code_t  event_code = lv_event_get_code(e);
    lv_obj_t * target =  lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        change_screen_ota(e);
    }
}

void ui_event_Button3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Panel42, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Panel29, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_SettingsScreen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_AppScreen, LV_SCR_LOAD_ANIM_FADE_ON, 250, 0, &ui_AppScreen_screen_init);
    }
}
void ui_event_Panel17(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        scan_network(e);
    }
}
void ui_event_Panel24(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_DisplayScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_DisplayScreen_screen_init);
    }
}
void ui_event_MqttScreen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_AppScreen, LV_SCR_LOAD_ANIM_FADE_ON, 250, 0, &ui_AppScreen_screen_init);
    }
}
void ui_event_Panel45(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_SensorsScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_SensorsScreen_screen_init);
    }
}
void ui_event_Panel46(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_ManualScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_ManualScreen_screen_init);
    }
}
void ui_event_SensorsScreen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_MqttScreen, LV_SCR_LOAD_ANIM_FADE_ON, 250, 0, &ui_MqttScreen_screen_init);
    }
}
void ui_event_ManualScreen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_MqttScreen, LV_SCR_LOAD_ANIM_FADE_ON, 250, 0, &ui_MqttScreen_screen_init);
    }
}
void ui_event_Switch1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        button1_on(e);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        button1_off(e);
    }
}
void ui_event_Switch2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        button2_on(e);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        button2_off(e);
    }
}
void ui_event_DisplayScreen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_SettingsScreen, LV_SCR_LOAD_ANIM_FADE_ON, 250, 0, &ui_SettingsScreen_screen_init);
    }
}
void ui_event_Slider3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        change_brightness(e);
    }
}
void ui_event_WifiScreen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_SettingsScreen, LV_SCR_LOAD_ANIM_FADE_ON, 250, 0, &ui_SettingsScreen_screen_init);
    }
}

void ui_event_OtaScreen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT && lv_obj_has_flag(ui_Panel93, LV_OBJ_FLAG_HIDDEN)) 
    {
        handle_out_ota_page();
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_AppScreen, LV_SCR_LOAD_ANIM_FADE_ON, 250, 0, &ui_AppScreen_screen_init);
    }
}

void ui_event_Button11(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED)
    {
        handle_out_ota_page();
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_AppScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_AppScreen_screen_init);
    }
}

void ui_event_AboutScreen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) 
    {
        _ui_screen_change(&ui_AppScreen, LV_SCR_LOAD_ANIM_FADE_ON, 250, 0, &ui_AppScreen_screen_init);
    }
}

void ui_event_Button21(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(ui_Panel100, LV_OBJ_FLAG_HIDDEN);
    }
}


void ui_event_Button22(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(ui_Panel100, LV_OBJ_FLAG_HIDDEN);
    }
}

void ui_event_Button23(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED)
    {
        handle_out_ota_page();
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_AppScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_AppScreen_screen_init);        
    }
}

void ui_event_Button24(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED)
    {
        handle_start_ota();
    }
}

void ui_event_Button25(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED)
    {
        handle_out_ota_page();
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_AppScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_AppScreen_screen_init);
                
    }
}

void ui_event_Button26(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED)
    {
        handle_out_ota_page();
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_AppScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_AppScreen_screen_init);

    }
}

void ui_event_Button27(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED)
    {
        handle_out_ota_page();
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_AppScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_AppScreen_screen_init);

    }
}

void ui_event_ScheduleScreen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT && lv_obj_has_flag(ui_Panel93, LV_OBJ_FLAG_HIDDEN)) 
    {
        deleteObject();
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_AppScreen, LV_SCR_LOAD_ANIM_FADE_ON, 250, 0, &ui_AppScreen_screen_init);
    }

}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_MainScreen_screen_init();
    ui_AppScreen_screen_init();
    ui_SettingsScreen_screen_init();
    ui_AboutScreen_screen_init();
    ui_MqttScreen_screen_init();
    ui_SensorsScreen_screen_init();
    ui_ManualScreen_screen_init();
    ui_DisplayScreen_screen_init();
    ui_WifiScreen_screen_init();
    ui_OtaScreen_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_MainScreen);
}
