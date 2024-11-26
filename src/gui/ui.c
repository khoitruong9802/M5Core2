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
lv_obj_t *  ui_HeaderScheduleScreen;
lv_obj_t *  ui_ButtonPreviousPageItemTitleScheduleScreen;
lv_obj_t *  ui_ButtonNextPageItemTitleScheduleScreen;
lv_obj_t *  ui_LabelPreviousPageItemTitleScheduleScreen;
lv_obj_t *  ui_LabelNextPageItemTitleScheduleScreen;
lv_obj_t *  ui_PanelPageItemTitleScheduleContainerScreen;
lv_obj_t *  ui_PanelPageItemTitleScheduleScreen[3];
lv_obj_t *  ui_LabelPageItemTitleScheduleScreen[3];
lv_obj_t *  ui_ScheduleContainer;


// SCREEN: ui_scheduleItemScreen
void ui_ScheduleItemScreen_screen_init(void);
lv_obj_t * ui_scheduleItemScreen;
void ui_event_ScheduleItemScreen(lv_event_t * e);
lv_obj_t * ui_PanelScheduleItemScreen;
lv_obj_t * ui_PanelHeaderScheduleItem;
lv_obj_t * ui_ButtonOKHeaderScheduleItem;
lv_obj_t * ui_LabelOKHeaderScheduleItem;
lv_obj_t * ui_ButtonCancelHeaderScheduleItem;
lv_obj_t * ui_LabelCancelHeaderScheduleItem;
lv_obj_t * ui_PanelScheduleItemContainerScreen;
lv_obj_t * ui_PanelNameContainerScheduleItem;
lv_obj_t * ui_LabelNameTitleScheduleItem;
void ui_event_PanelNameScheduleItem(lv_event_t * e);
lv_obj_t * ui_PanelNameScheduleItem;
lv_obj_t * ui_LabelNameScheduleItem;
lv_obj_t * ui_PanelDescriptionContainerScheduleItem;
lv_obj_t * ui_LabelDescriptionTitleScheduleItem;
void ui_event_PanelDescriptionScheduleItem(lv_event_t * e);
lv_obj_t * ui_PanelDescriptionScheduleItem;
lv_obj_t * ui_LabelDescriptionScheduleItem;
lv_obj_t * ui_PanelAreaContainerScheduleItem;
lv_obj_t * ui_LabelAreaTitleScheduleItem;
lv_obj_t * ui_DropdownAreaScheduleItem;
lv_obj_t * ui_PanelPriorityContainerScheduleItem;
lv_obj_t * ui_LabelPriorityTitleScheduleItem;
lv_obj_t * ui_SliderPriorityScheduleItem;
lv_obj_t * ui_LabelPriorityItem5ScheduleItem;
lv_obj_t * ui_LabelPriorityItem4ScheduleItem;
lv_obj_t * ui_LabelPriorityItem3ScheduleItem;
lv_obj_t * ui_LabelPriorityItem2ScheduleItem;
lv_obj_t * ui_LabelPriorityItem1ScheduleItem;
lv_obj_t * ui_PanelWaterQuantityContainerScheduleItem;
lv_obj_t * ui_LabelWaterQuantityTitleScheduleItem;
void ui_event_PanelWaterQuantityScheduleItem(lv_event_t * e);
lv_obj_t * ui_PanelWaterQuantityScheduleItem;
lv_obj_t * ui_LabelWaterQuantityScheduleItem;
lv_obj_t * ui_PanelScheduleContainerScheduleItem;
lv_obj_t * ui_LabelScheduleTitleScheduleItem;
lv_obj_t * ui_PanelScheduleInforContainerScheduleItem;
lv_obj_t * ui_PanelScheduleStartTimeContainerScheduleItem;
lv_obj_t * ui_LabelScheduleStartTimeTitleScheduleItem;
void ui_event_PanelScheduleStartTimeScheduleItem(lv_event_t * e);
lv_obj_t * ui_PanelScheduleStartTimeScheduleItem;
lv_obj_t * ui_LabelScheduleStartTimeScheduleItem;
lv_obj_t * ui_PanelScheduleStopTimeContainerScheduleItem;
lv_obj_t * ui_LabelScheduleStopTimeTitleScheduleItem;
void ui_event_PanelScheduleEndTimeScheduleItem(lv_event_t * e);
lv_obj_t * ui_PanelScheduleEndTimeScheduleItem;
lv_obj_t * ui_LabelScheduleEndTimeScheduleItem;
lv_obj_t * ui_PanelScheduleRepeatContainerScheduleItem;
lv_obj_t * ui_LabelScheduleRepeatTitleScheduleItem;
lv_obj_t * ui_DropdownScheduleRepeatScheduleItem;
lv_obj_t * ui_PanelScheduleWeekContainerScheduleItem;
lv_obj_t * ui_LabelScheduleWeekTitleScheduleItem;
lv_obj_t * ui_PanelScheduleWeekScheduleItem;
lv_obj_t * ui_PanelScheduleWeekItemMondayScheduleItem;
lv_obj_t * ui_LabelScheduleWeekItemMondayScheduleItem;
lv_obj_t * ui_PanelScheduleWeekItemTuesdayScheduleItem;
lv_obj_t * ui_LabelScheduleWeekItemTuesdayScheduleItem;
lv_obj_t * ui_PanelScheduleWeekItemWednesdayScheduleItem;
lv_obj_t * ui_LabelScheduleWeekItemWednesdayScheduleItem;
lv_obj_t * ui_PanelScheduleWeekItemThursdayScheduleItem;
lv_obj_t * ui_LabelScheduleWeekItemThursdayScheduleItem;
lv_obj_t * ui_PanelScheduleWeekItemFridayScheduleItem;
lv_obj_t * ui_LabelScheduleWeekItemFridayScheduleItem;
lv_obj_t * ui_PanelScheduleWeekItemSaturdayScheduleItem;
lv_obj_t * ui_LabelScheduleWeekItemSaturdayScheduleItem;
lv_obj_t * ui_PanelScheduleWeekItemSundayScheduleItem;
lv_obj_t * ui_LabelScheduleWeekItemSundayScheduleItem;
lv_obj_t * ui_PanelScheduleDateContainerScheduleItem;
lv_obj_t * ui_LabelScheduleDateTitleScheduleItem;
void ui_event_PanelScheduleDateScheduleItem(lv_event_t * e);
lv_obj_t * ui_PanelScheduleDateScheduleItem;
lv_obj_t * ui_LabelScheduleDateScheduleItem;
lv_obj_t * ui_PanelScheduleStartDateContainerScheduleItem;
lv_obj_t * ui_LabelScheduleStartDateTitleScheduleItem;
void ui_event_PanelScheduleStartDateScheduleItem(lv_event_t * e);
lv_obj_t * ui_PanelScheduleStartDateScheduleItem;
lv_obj_t * ui_LabelScheduleStartDateScheduleItem;
lv_obj_t * ui_PanelScheduleEndDateContainerScheduleItem;
lv_obj_t * ui_LabelScheduleEndDateTitleScheduleItem;
lv_obj_t * ui_CheckboxScheduleEndDateScheduleItem;
void ui_event_PanelScheduleEndDateScheduleItem(lv_event_t * e);
lv_obj_t * ui_PanelScheduleEndDateScheduleItem;
lv_obj_t * ui_LabelScheduleEndDateScheduleItem;
lv_obj_t * ui_PanelLoadingScheduleItemScreen;
lv_obj_t * ui_SpinnerLoadingScheduleItemScreen;
lv_obj_t * ui_LabelLoadingScheduleItemScreen;

// SCREEN: ui_name
void ui_name_screen_init(void);
lv_obj_t * ui_name;
lv_obj_t * ui_NameScheduleItemScreen;
void ui_event_PanelCloseButtonNameScheduleItem(lv_event_t * e);
lv_obj_t * ui_PanelCloseButtonNameScheduleItem;
lv_obj_t * ui_LabelCloseButtonNameScheduleItem;
lv_obj_t * ui_TextAreaNameScheduleItem;
lv_obj_t * ui_KeyboardNameScheduleItem;
lv_obj_t * ui_LabelTitleNameScheduleItem;


// SCREEN: ui_description
void ui_description_screen_init(void);
lv_obj_t * ui_description;
lv_obj_t * ui_DescriptionScheduleItemScreen;
void ui_event_PanelCloseButtonDescriptionScheduleItem(lv_event_t * e);
lv_obj_t * ui_PanelCloseButtonDescriptionScheduleItem;
lv_obj_t * ui_LabelCloseButtonDescriptionScheduleItem;
lv_obj_t * ui_TextAreaDescriptionsScheduleItem;
lv_obj_t * ui_KeyboardDescriptionsScheduleItem;
lv_obj_t * ui_LabelTitleDescriptionScheduleItem;


// SCREEN: ui_waterQuantity
void ui_waterQuantity_screen_init(void);
lv_obj_t * ui_waterQuantity;
lv_obj_t * ui_WaterQuantityScheduleItemScreen;
lv_obj_t * ui_LabelTitleWaterQuantityScheduleItem;
void ui_event_PanelCloseButtonWaterQuantityScheduleItem(lv_event_t * e);
lv_obj_t * ui_PanelCloseButtonWaterQuantityScheduleItem;
lv_obj_t * ui_LabelCloseButtonWaterQuantityScheduleItem;
lv_obj_t * ui_TextAreaWaterQuantityScheduleItem;
lv_obj_t * ui_KeyboardWaterQuantityScheduleItem;
lv_obj_t * ui_LabelUnitWaterQuantityScheduleItem;


// SCREEN: ui_startTime
void ui_startTime_screen_init(void);
lv_obj_t * ui_startTime;
lv_obj_t * ui_StartTimeScheduleItemScreen;
lv_obj_t * ui_LabelTitleStartTimeScheduleItem;
lv_obj_t * ui_RollerHourStartTimeScheduleItem;
lv_obj_t * ui_LabelColonSymbolStartTimeScheduleItem;
lv_obj_t * ui_RollerMinuteStartTimeScheduleItem;
void ui_event_ButtonOKStartTimeScheduleItem(lv_event_t * e);
lv_obj_t * ui_ButtonOKStartTimeScheduleItem;
lv_obj_t * ui_LabelOKStartTimeScheduleItem;
void ui_event_ButtonCancelStartTimeScheduleItem(lv_event_t * e);
lv_obj_t * ui_ButtonCancelStartTimeScheduleItem;
lv_obj_t * ui_LabelCancelStartTimeScheduleItem;


// SCREEN: ui_endTime
void ui_endTime_screen_init(void);
lv_obj_t * ui_endTime;
lv_obj_t * ui_EndTimeScheduleItemScreen;
lv_obj_t * ui_LabelTitleEndTimeScheduleItem;
lv_obj_t * ui_RollerHourEndTimeScheduleItem;
lv_obj_t * ui_LabelColonSymbolEndTimeScheduleItem;
lv_obj_t * ui_RollerMinuteEndTimeScheduleItem;
void ui_event_ButtonOKEndTimeScheduleItem(lv_event_t * e);
lv_obj_t * ui_ButtonOKEndTimeScheduleItem;
lv_obj_t * ui_LabelOKEndTimeScheduleItem;
void ui_event_ButtonCancelEndTimeScheduleItem(lv_event_t * e);
lv_obj_t * ui_ButtonCancelEndTimeScheduleItem;
lv_obj_t * ui_LabelCancelEndTimeScheduleItem;


// SCREEN: ui_EndDate
void ui_EndDate_screen_init(void);
lv_obj_t * ui_EndDate;
lv_obj_t * ui_EndDateScheduleItemScreen;
void ui_event_ButtonOKEndDateScheduleItem(lv_event_t * e);
lv_obj_t * ui_ButtonOKEndDateScheduleItem;
lv_obj_t * ui_LabelOKEndDateScheduleItem;
lv_obj_t * ui_LabelTitleEndDateScheduleItem;
lv_obj_t * ui_CalendarEndDateScheduleItem;
void ui_event_ButtonCancelEndDateScheduleItem(lv_event_t * e);
lv_obj_t * ui_ButtonCancelEndDateScheduleItem;
lv_obj_t * ui_LabelCancelEndDateScheduleItem;


// SCREEN: ui_startDate
void ui_startDate_screen_init(void);
lv_obj_t * ui_startDate;
lv_obj_t * ui_StartDateScheduleItemScreen;
void ui_event_ButtonOKStartDateScheduleItem(lv_event_t * e);
lv_obj_t * ui_ButtonOKStartDateScheduleItem;
lv_obj_t * ui_LabelOKStartDateScheduleItem;
lv_obj_t * ui_LabelTitleStartDateScheduleItem;
lv_obj_t * ui_CalendarStartDateScheduleItem;
void ui_event_ButtonCancelStartDateScheduleItem(lv_event_t * e);
lv_obj_t * ui_ButtonCancelStartDateScheduleItem;
lv_obj_t * ui_LabelCancelStartDateScheduleItem;


// SCREEN: ui_date
void ui_date_screen_init(void);
lv_obj_t * ui_date;
lv_obj_t * ui_DateScheduleItemScreen;
void ui_event_ButtonOKDateScheduleItem(lv_event_t * e);
lv_obj_t * ui_ButtonOKDateScheduleItem;
lv_obj_t * ui_LabelOKDateScheduleItem;
lv_obj_t * ui_LabelTitleDateScheduleItem;
lv_obj_t * ui_CalendarDateScheduleItem;
void ui_event_ButtonCancelDateScheduleItem(lv_event_t * e);
lv_obj_t * ui_ButtonCancelDateScheduleItem;
lv_obj_t * ui_LabelCancelDateScheduleItem;


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
        // deleteObject(ui_ScheduleContainer);
        lv_obj_add_flag(ui_PanelPageItemTitleScheduleScreen[0], LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_PanelPageItemTitleScheduleScreen[1], LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_PanelPageItemTitleScheduleScreen[2], LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_style_bg_color(ui_PanelPageItemTitleScheduleScreen[0], lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_PanelPageItemTitleScheduleScreen[1], lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_PanelPageItemTitleScheduleScreen[2], lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);        
        lv_task_handler();
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_AppScreen, LV_SCR_LOAD_ANIM_FADE_ON, 250, 0, &ui_AppScreen_screen_init);
    }

}

void ui_event_ScheduleItemScreen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT && lv_obj_has_flag(ui_Panel93, LV_OBJ_FLAG_HIDDEN)) 
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_ScheduleScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_ScheduleScreen_screen_init);
    }

}




void ui_event_PanelNameScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_name, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_name_screen_init);
    }
}
void ui_event_PanelDescriptionScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_description, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_description_screen_init);
    }
}
void ui_event_PanelWaterQuantityScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_waterQuantity, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_waterQuantity_screen_init);
    }
}
void ui_event_PanelScheduleStartTimeScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_startTime, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_startTime_screen_init);
    }
}
void ui_event_PanelScheduleEndTimeScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_endTime, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_endTime_screen_init);
    }
}
void ui_event_PanelScheduleDateScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_date, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_date_screen_init);
    }
}
void ui_event_PanelScheduleStartDateScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_startDate, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_startDate_screen_init);
    }
}
void ui_event_PanelScheduleEndDateScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_EndDate, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_EndDate_screen_init);
    }
}
void ui_event_PanelCloseButtonNameScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_scheduleItemScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_scheduleItemScreen_screen_init);
    }
}
void ui_event_PanelCloseButtonDescriptionScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_scheduleItemScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_scheduleItemScreen_screen_init);
    }
}
void ui_event_PanelCloseButtonWaterQuantityScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_scheduleItemScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_scheduleItemScreen_screen_init);
    }
}
void ui_event_ButtonOKStartTimeScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_scheduleItemScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_scheduleItemScreen_screen_init);
    }
}
void ui_event_ButtonCancelStartTimeScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_scheduleItemScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_scheduleItemScreen_screen_init);
    }
}
void ui_event_ButtonOKEndTimeScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_scheduleItemScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_scheduleItemScreen_screen_init);
    }
}
void ui_event_ButtonCancelEndTimeScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_scheduleItemScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_scheduleItemScreen_screen_init);
    }
}
void ui_event_ButtonOKEndDateScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_scheduleItemScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_scheduleItemScreen_screen_init);
    }
}
void ui_event_ButtonCancelEndDateScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_scheduleItemScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_scheduleItemScreen_screen_init);
    }
}
void ui_event_ButtonOKStartDateScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_scheduleItemScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_scheduleItemScreen_screen_init);
    }
}
void ui_event_ButtonCancelStartDateScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_scheduleItemScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_scheduleItemScreen_screen_init);
    }
}
void ui_event_ButtonOKDateScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_scheduleItemScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_scheduleItemScreen_screen_init);
    }
}
void ui_event_ButtonCancelDateScheduleItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(&ui_scheduleItemScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_scheduleItemScreen_screen_init);
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
    ui_ScheduleScreen_screen_init();
    ui_ScheduleItemScreen_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_MainScreen);
}
