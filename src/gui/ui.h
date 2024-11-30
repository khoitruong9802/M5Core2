// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: m5core2

#ifndef _M5CORE2_UI_H
#define _M5CORE2_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "ui_events.h"

// SCREEN: ui_MainScreen
void ui_MainScreen_screen_init(void);
extern lv_obj_t * ui_MainScreen;
extern lv_obj_t * ui_Panel2;
extern lv_obj_t * ui_header1;
extern lv_obj_t * ui_Image1;
extern lv_obj_t * ui_Image2;
extern lv_obj_t * ui_Slider2;
extern lv_obj_t * ui_Label1;
extern lv_obj_t * ui_Label2;
extern lv_obj_t * ui_Label3;
extern lv_obj_t * ui_Label4;
void ui_event_Panel4(lv_event_t * e);
extern lv_obj_t * ui_Panel4;
extern lv_obj_t * ui_Panel100;
extern lv_obj_t * ui_Panel101;
void ui_event_Button21(lv_event_t * e);
extern lv_obj_t * ui_Button21;
void ui_event_Button22(lv_event_t * e);
extern lv_obj_t * ui_Button22;
extern lv_obj_t * ui_Label101;
extern lv_obj_t * ui_Label102;
extern lv_obj_t * ui_Label103;

// SCREEN: ui_AppScreen
void ui_AppScreen_screen_init(void);
void ui_event_AppScreen(lv_event_t * e);
extern lv_obj_t * ui_AppScreen;
extern lv_obj_t * ui_Panel5;
void ui_event_Panel6(lv_event_t * e);
extern lv_obj_t * ui_Panel6;
void ui_event_Panel3(lv_event_t * e);
extern lv_obj_t * ui_Panel3;
extern lv_obj_t * ui_Panel9;
extern lv_obj_t * ui_Label5;
extern lv_obj_t * ui_Panel1;
extern lv_obj_t * ui_Panel7;
extern lv_obj_t * ui_Label6;
void ui_event_Panel11(lv_event_t * e);
extern lv_obj_t * ui_Panel11;
extern lv_obj_t * ui_Panel12;
extern lv_obj_t * ui_Label8;
extern lv_obj_t * ui_Panel8;
extern lv_obj_t * ui_Panel10;
extern lv_obj_t * ui_Label7;
void ui_event_Panel13(lv_event_t * e);
extern lv_obj_t * ui_Panel13;
extern lv_obj_t * ui_Panel14;
extern lv_obj_t * ui_Label10;
extern lv_obj_t * ui_Panel40;
extern lv_obj_t * ui_Spinner1;
extern lv_obj_t * ui_Panel41;
void ui_event_Button2(lv_event_t * e);
extern lv_obj_t * ui_Button2;
extern lv_obj_t * ui_Label35;
extern lv_obj_t * ui_Label34;
extern lv_obj_t * ui_Panel42;
extern lv_obj_t * ui_Label36;
extern lv_obj_t * ui_Panel49;
void ui_event_Button3(lv_event_t * e);
extern lv_obj_t * ui_Button3;
extern lv_obj_t * ui_Label37;
extern lv_obj_t * ui_Panel29;
extern lv_obj_t * ui_Label33;
extern lv_obj_t * ui_Panel39;
void ui_event_Button1(lv_event_t * e);
extern lv_obj_t * ui_Button1;
extern lv_obj_t * ui_Label31;
void ui_event_Panel90(lv_event_t * e);
extern lv_obj_t * ui_Panel90;
extern lv_obj_t * ui_Panel91;
extern lv_obj_t * ui_Label90;
// SCREEN: ui_SettingsScreen
void ui_SettingsScreen_screen_init(void);
void ui_event_SettingsScreen(lv_event_t * e);
extern lv_obj_t * ui_SettingsScreen;
extern lv_obj_t * ui_Panel15;
extern lv_obj_t * ui_Panel16;
void ui_event_Panel17(lv_event_t * e);
extern lv_obj_t * ui_Panel17;
extern lv_obj_t * ui_Panel18;
extern lv_obj_t * ui_Label9;
extern lv_obj_t * ui_Panel20;
extern lv_obj_t * ui_Panel21;
extern lv_obj_t * ui_Label11;
void ui_event_Panel24(lv_event_t * e);
extern lv_obj_t * ui_Panel24;
extern lv_obj_t * ui_Panel25;
extern lv_obj_t * ui_Label13;
extern lv_obj_t * ui_Panel22;
extern lv_obj_t * ui_Panel23;
extern lv_obj_t * ui_Label12;
//SCREEN: ui_OtaScreen
void ui_OtaScreen_screen_init(void);
void ui_event_OtaScreen(lv_event_t * e);
extern  lv_obj_t * ui_OtaScreen;
extern  lv_obj_t * ui_Panel92;
extern  lv_obj_t * ui_Panel93;
extern  lv_obj_t * ui_Spinner2;
void ui_event_Button11(lv_event_t * e);
extern  lv_obj_t * ui_Button11;
extern  lv_obj_t * ui_Label90;
extern  lv_obj_t * ui_Label91;
extern  lv_obj_t * ui_Panel94;

extern  lv_obj_t * ui_Panel102;
extern  lv_obj_t * ui_Panel103;
extern  lv_obj_t * ui_Panel104;
extern  lv_obj_t * ui_Panel105;
void ui_event_Button23(lv_event_t * e);
extern  lv_obj_t * ui_Button23;
void ui_event_Button24(lv_event_t * e);
extern  lv_obj_t * ui_Button24;
void ui_event_Button25(lv_event_t * e);
extern  lv_obj_t * ui_Button25;
void ui_event_Button26(lv_event_t * e);
extern  lv_obj_t * ui_Button26;
void ui_event_Button27(lv_event_t * e);
extern  lv_obj_t * ui_Button27;
extern  lv_obj_t * ui_Label104;
extern  lv_obj_t * ui_Label105;
extern  lv_obj_t * ui_Label106;
extern  lv_obj_t * ui_Label107;
extern  lv_obj_t * ui_Label108;
extern  lv_obj_t * ui_Label109;
extern  lv_obj_t * ui_Label110;
// SCREEN: ui_AboutScreen
void ui_AboutScreen_screen_init(void);
void ui_event_AboutScreen(lv_event_t * e);
extern lv_obj_t * ui_AboutScreen;
extern lv_obj_t * ui_Panel19;
extern lv_obj_t * ui_Label14;
// SCREEN: ui_MqttScreen
void ui_MqttScreen_screen_init(void);
void ui_event_MqttScreen(lv_event_t * e);
extern lv_obj_t * ui_MqttScreen;
extern lv_obj_t * ui_Panel43;
extern lv_obj_t * ui_Panel44;
void ui_event_Panel45(lv_event_t * e);
extern lv_obj_t * ui_Panel45;
extern lv_obj_t * ui_Image3;
extern lv_obj_t * ui_Label23;
void ui_event_Panel46(lv_event_t * e);
extern lv_obj_t * ui_Panel46;
extern lv_obj_t * ui_Image4;
extern lv_obj_t * ui_Label24;
extern lv_obj_t * ui_Panel47;
extern lv_obj_t * ui_Image5;
extern lv_obj_t * ui_Label25;
// SCREEN: ui_SensorsScreen
void ui_SensorsScreen_screen_init(void);
void ui_event_SensorsScreen(lv_event_t * e);
extern lv_obj_t * ui_SensorsScreen;
extern lv_obj_t * ui_Panel31;
extern lv_obj_t * ui_Panel33;
extern lv_obj_t * ui_Label19;
extern lv_obj_t * ui_Label20;
extern lv_obj_t * ui_Label21;
extern lv_obj_t * ui_Label22;
extern lv_obj_t * ui_Label26;
extern lv_obj_t * ui_Label27;
extern lv_obj_t * ui_Label15;
extern lv_obj_t * ui_Label16;
// SCREEN: ui_ManualScreen
void ui_ManualScreen_screen_init(void);
void ui_event_ManualScreen(lv_event_t * e);
extern lv_obj_t * ui_ManualScreen;
extern lv_obj_t * ui_Panel35;
extern lv_obj_t * ui_Panel36;
extern lv_obj_t * ui_Panel28;
extern lv_obj_t * ui_Label32;
extern lv_obj_t * ui_Image6;
void ui_event_Switch1(lv_event_t * e);
extern lv_obj_t * ui_Switch1;
extern lv_obj_t * ui_Panel27;
extern lv_obj_t * ui_Label29;
extern lv_obj_t * ui_Image7;
void ui_event_Switch2(lv_event_t * e);
extern lv_obj_t * ui_Switch2;
// SCREEN: ui_DisplayScreen
void ui_DisplayScreen_screen_init(void);
void ui_event_DisplayScreen(lv_event_t * e);
extern lv_obj_t * ui_DisplayScreen;
extern lv_obj_t * ui_Panel37;
extern lv_obj_t * ui_Panel48;
extern lv_obj_t * ui_Label28;
extern lv_obj_t * ui_Panel38;
void ui_event_Slider3(lv_event_t * e);
extern lv_obj_t * ui_Slider3;
extern lv_obj_t * ui_Label30;
extern lv_obj_t * ui_Dropdown1;
// SCREEN: ui_WifiScreen
void ui_WifiScreen_screen_init(void);
void ui_event_WifiScreen(lv_event_t * e);
extern lv_obj_t * ui_WifiScreen;
extern lv_obj_t * ui_Panel26;
extern lv_obj_t * ui____initial_actions0;
// SCREEN: ui_ScheduleScreen
void ui_ScheduleScreen_screen_init(void);
void ui_event_ScheduleScreen(lv_event_t * e);
extern lv_obj_t *  ui_ScheduleScreen;
extern lv_obj_t *  ui_MainScheduleScreen;
extern lv_obj_t *  ui_HeaderScheduleScreen;
extern lv_obj_t *  ui_ButtonPreviousPageItemTitleScheduleScreen;
extern lv_obj_t *  ui_ButtonNextPageItemTitleScheduleScreen;
extern lv_obj_t *  ui_LabelPreviousPageItemTitleScheduleScreen;
extern lv_obj_t *  ui_LabelNextPageItemTitleScheduleScreen;
extern lv_obj_t *  ui_PanelPageItemTitleScheduleContainerScreen;
extern lv_obj_t *  ui_PanelPageItemTitleScheduleScreen[3];
extern lv_obj_t *  ui_LabelPageItemTitleScheduleScreen[3];
extern lv_obj_t *  ui_ScheduleContainer;
extern lv_obj_t *  ui_PanelLoadingScheduleScreen;
extern lv_obj_t *  ui_SpinnerLoadingScheduleScreen;
extern lv_obj_t *  ui_LabelLoadingScheduleScreen;
extern lv_obj_t * ui_OptionHeaderScheduleScreen;
extern lv_obj_t * ui_AddOptionHeaderScheduleScreen;
extern lv_obj_t * ui_LabelAddOptionHeaderScheduleScreen;
extern lv_obj_t * ui_PanelRemoveOptionHeaderScheduleScreen;
extern lv_obj_t * ui_ImageRemoveOptionHeaderScheduleScreen;

// SCREEN: ui_scheduleItemScreen
void ui_ScheduleItemScreen_screen_init(void);
extern lv_obj_t * ui_scheduleItemScreen;
extern lv_obj_t * ui_PanelScheduleItemScreen;
extern lv_obj_t * ui_PanelHeaderScheduleItem;

extern lv_obj_t * ui_ButtonOKHeaderScheduleItem;
extern lv_obj_t * ui_LabelOKHeaderScheduleItem;

extern lv_obj_t * ui_ButtonCancelHeaderScheduleItem;
extern lv_obj_t * ui_LabelCancelHeaderScheduleItem;
extern lv_obj_t * ui_PanelScheduleItemContainerScreen;
extern lv_obj_t * ui_PanelNameContainerScheduleItem;
extern lv_obj_t * ui_LabelNameTitleScheduleItem;
void ui_event_PanelNameScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_PanelNameScheduleItem;
extern lv_obj_t * ui_LabelNameScheduleItem;
extern lv_obj_t * ui_PanelDescriptionContainerScheduleItem;
extern lv_obj_t * ui_LabelDescriptionTitleScheduleItem;
void ui_event_PanelDescriptionScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_PanelDescriptionScheduleItem;
extern lv_obj_t * ui_LabelDescriptionScheduleItem;
extern lv_obj_t * ui_PanelAreaContainerScheduleItem;
extern lv_obj_t * ui_LabelAreaTitleScheduleItem;
extern lv_obj_t * ui_DropdownAreaScheduleItem;
extern lv_obj_t * ui_PanelPriorityContainerScheduleItem;
extern lv_obj_t * ui_LabelPriorityTitleScheduleItem;
extern lv_obj_t * ui_SliderPriorityScheduleItem;
extern lv_obj_t * ui_LabelPriorityItem5ScheduleItem;
extern lv_obj_t * ui_LabelPriorityItem4ScheduleItem;
extern lv_obj_t * ui_LabelPriorityItem3ScheduleItem;
extern lv_obj_t * ui_LabelPriorityItem2ScheduleItem;
extern lv_obj_t * ui_LabelPriorityItem1ScheduleItem;
extern lv_obj_t * ui_PanelWaterQuantityContainerScheduleItem;
extern lv_obj_t * ui_LabelWaterQuantityTitleScheduleItem;
void ui_event_PanelWaterQuantityScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_PanelWaterQuantityScheduleItem;
extern lv_obj_t * ui_LabelWaterQuantityScheduleItem;
extern lv_obj_t * ui_PanelScheduleContainerScheduleItem;
extern lv_obj_t * ui_LabelScheduleTitleScheduleItem;
extern lv_obj_t * ui_PanelScheduleInforContainerScheduleItem;
extern lv_obj_t * ui_PanelScheduleStartTimeContainerScheduleItem;
extern lv_obj_t * ui_LabelScheduleStartTimeTitleScheduleItem;
void ui_event_PanelScheduleStartTimeScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_PanelScheduleStartTimeScheduleItem;
extern lv_obj_t * ui_LabelScheduleStartTimeScheduleItem;
extern lv_obj_t * ui_PanelScheduleStopTimeContainerScheduleItem;
extern lv_obj_t * ui_LabelScheduleStopTimeTitleScheduleItem;
void ui_event_PanelScheduleEndTimeScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_PanelScheduleEndTimeScheduleItem;
extern lv_obj_t * ui_LabelScheduleEndTimeScheduleItem;
extern lv_obj_t * ui_PanelScheduleRepeatContainerScheduleItem;
extern lv_obj_t * ui_LabelScheduleRepeatTitleScheduleItem;
extern lv_obj_t * ui_DropdownScheduleRepeatScheduleItem;
extern lv_obj_t * ui_PanelScheduleWeekContainerScheduleItem;
extern lv_obj_t * ui_LabelScheduleWeekTitleScheduleItem;
extern lv_obj_t * ui_PanelScheduleWeekScheduleItem;
extern lv_obj_t * ui_PanelScheduleWeekItemMondayScheduleItem;
extern lv_obj_t * ui_LabelScheduleWeekItemMondayScheduleItem;
extern lv_obj_t * ui_PanelScheduleWeekItemTuesdayScheduleItem;
extern lv_obj_t * ui_LabelScheduleWeekItemTuesdayScheduleItem;
extern lv_obj_t * ui_PanelScheduleWeekItemWednesdayScheduleItem;
extern lv_obj_t * ui_LabelScheduleWeekItemWednesdayScheduleItem;
extern lv_obj_t * ui_PanelScheduleWeekItemThursdayScheduleItem;
extern lv_obj_t * ui_LabelScheduleWeekItemThursdayScheduleItem;
extern lv_obj_t * ui_PanelScheduleWeekItemFridayScheduleItem;
extern lv_obj_t * ui_LabelScheduleWeekItemFridayScheduleItem;
extern lv_obj_t * ui_PanelScheduleWeekItemSaturdayScheduleItem;
extern lv_obj_t * ui_LabelScheduleWeekItemSaturdayScheduleItem;
extern lv_obj_t * ui_PanelScheduleWeekItemSundayScheduleItem;
extern lv_obj_t * ui_LabelScheduleWeekItemSundayScheduleItem;
extern lv_obj_t * ui_PanelScheduleDateContainerScheduleItem;
extern lv_obj_t * ui_LabelScheduleDateTitleScheduleItem;
void ui_event_PanelScheduleDateScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_PanelScheduleDateScheduleItem;
extern lv_obj_t * ui_LabelScheduleDateScheduleItem;
extern lv_obj_t * ui_PanelScheduleStartDateContainerScheduleItem;
extern lv_obj_t * ui_LabelScheduleStartDateTitleScheduleItem;
void ui_event_PanelScheduleStartDateScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_PanelScheduleStartDateScheduleItem;
extern lv_obj_t * ui_LabelScheduleStartDateScheduleItem;
extern lv_obj_t * ui_PanelScheduleEndDateContainerScheduleItem;
extern lv_obj_t * ui_LabelScheduleEndDateTitleScheduleItem;
extern lv_obj_t * ui_CheckboxScheduleEndDateScheduleItem;
void ui_event_PanelScheduleEndDateScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_PanelScheduleEndDateScheduleItem;
extern lv_obj_t * ui_LabelScheduleEndDateScheduleItem;
extern lv_obj_t * ui_PanelLoadingScheduleItemScreen;
extern lv_obj_t * ui_SpinnerLoadingScheduleItemScreen;
extern lv_obj_t * ui_LabelLoadingScheduleItemScreen;

// SCREEN: ui_name
void ui_name_screen_init(void);
extern lv_obj_t * ui_name;
extern lv_obj_t * ui_NameScheduleItemScreen;
void ui_event_PanelCloseButtonNameScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_PanelCloseButtonNameScheduleItem;
extern lv_obj_t * ui_LabelCloseButtonNameScheduleItem;
void ui_event_TextAreaNameScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_TextAreaNameScheduleItem;
extern lv_obj_t * ui_KeyboardNameScheduleItem;
extern lv_obj_t * ui_LabelTitleNameScheduleItem;
extern lv_obj_t * ui_PanelTextAreaNameScheduleItem;
// SCREEN: ui_description
void ui_description_screen_init(void);
extern lv_obj_t * ui_description;
extern lv_obj_t * ui_DescriptionScheduleItemScreen;
void ui_event_PanelCloseButtonDescriptionScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_PanelCloseButtonDescriptionScheduleItem;
extern lv_obj_t * ui_LabelCloseButtonDescriptionScheduleItem;
void ui_event_TextAreaDescriptionScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_TextAreaDescriptionsScheduleItem;
extern lv_obj_t * ui_KeyboardDescriptionsScheduleItem;
extern lv_obj_t * ui_LabelTitleDescriptionScheduleItem;
extern lv_obj_t * ui_PanelTextAreaDescriptionScheduleItem;
// SCREEN: ui_waterQuantity
void ui_waterQuantity_screen_init(void);
extern lv_obj_t * ui_waterQuantity;
extern lv_obj_t * ui_WaterQuantityScheduleItemScreen;
extern lv_obj_t * ui_LabelTitleWaterQuantityScheduleItem;
void ui_event_PanelCloseButtonWaterQuantityScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_PanelCloseButtonWaterQuantityScheduleItem;
extern lv_obj_t * ui_LabelCloseButtonWaterQuantityScheduleItem;
void ui_event_TextAreaWaterQuantityScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_TextAreaWaterQuantityScheduleItem;
extern lv_obj_t * ui_KeyboardWaterQuantityScheduleItem;
extern lv_obj_t * ui_LabelUnitWaterQuantityScheduleItem;
extern lv_obj_t * ui_PanelTextAreaWaterQuantityScheduleItem;
// SCREEN: ui_startTime
void ui_startTime_screen_init(void);
extern lv_obj_t * ui_startTime;
extern lv_obj_t * ui_StartTimeScheduleItemScreen;
extern lv_obj_t * ui_LabelTitleStartTimeScheduleItem;
extern lv_obj_t * ui_RollerHourStartTimeScheduleItem;
extern lv_obj_t * ui_LabelColonSymbolStartTimeScheduleItem;
extern lv_obj_t * ui_RollerMinuteStartTimeScheduleItem;
void ui_event_ButtonOKStartTimeScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_ButtonOKStartTimeScheduleItem;
extern lv_obj_t * ui_LabelOKStartTimeScheduleItem;
void ui_event_ButtonCancelStartTimeScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_ButtonCancelStartTimeScheduleItem;
extern lv_obj_t * ui_LabelCancelStartTimeScheduleItem;
// SCREEN: ui_endTime
void ui_endTime_screen_init(void);
extern lv_obj_t * ui_endTime;
extern lv_obj_t * ui_EndTimeScheduleItemScreen;
extern lv_obj_t * ui_LabelTitleEndTimeScheduleItem;
extern lv_obj_t * ui_RollerHourEndTimeScheduleItem;
extern lv_obj_t * ui_LabelColonSymbolEndTimeScheduleItem;
extern lv_obj_t * ui_RollerMinuteEndTimeScheduleItem;
void ui_event_ButtonOKEndTimeScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_ButtonOKEndTimeScheduleItem;
extern lv_obj_t * ui_LabelOKEndTimeScheduleItem;
void ui_event_ButtonCancelEndTimeScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_ButtonCancelEndTimeScheduleItem;
extern lv_obj_t * ui_LabelCancelEndTimeScheduleItem;
// SCREEN: ui_EndDate
void ui_EndDate_screen_init(void);
extern lv_obj_t * ui_EndDate;
extern lv_obj_t * ui_EndDateScheduleItemScreen;
void ui_event_ButtonOKEndDateScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_ButtonOKEndDateScheduleItem;
extern lv_obj_t * ui_LabelOKEndDateScheduleItem;
extern lv_obj_t * ui_LabelTitleEndDateScheduleItem;
void ui_event_CalendarEndDateScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_CalendarEndDateScheduleItem;
void ui_event_ButtonCancelEndDateScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_ButtonCancelEndDateScheduleItem;
extern lv_obj_t * ui_LabelCancelEndDateScheduleItem;
// SCREEN: ui_startDate
void ui_startDate_screen_init(void);
extern lv_obj_t * ui_startDate;
extern lv_obj_t * ui_StartDateScheduleItemScreen;
void ui_event_ButtonOKStartDateScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_ButtonOKStartDateScheduleItem;
extern lv_obj_t * ui_LabelOKStartDateScheduleItem;
extern lv_obj_t * ui_LabelTitleStartDateScheduleItem;
void ui_event_CalendarStartDateScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_CalendarStartDateScheduleItem;
void ui_event_ButtonCancelStartDateScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_ButtonCancelStartDateScheduleItem;
extern lv_obj_t * ui_LabelCancelStartDateScheduleItem;
// SCREEN: ui_date
void ui_date_screen_init(void);
extern lv_obj_t * ui_date;
extern lv_obj_t * ui_DateScheduleItemScreen;
void ui_event_ButtonOKDateScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_ButtonOKDateScheduleItem;
extern lv_obj_t * ui_LabelOKDateScheduleItem;
extern lv_obj_t * ui_LabelTitleDateScheduleItem;
void ui_event_CalendarDateScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_CalendarDateScheduleItem;
void ui_event_ButtonCancelDateScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_ButtonCancelDateScheduleItem;
extern lv_obj_t * ui_LabelCancelDateScheduleItem;



LV_IMG_DECLARE(ui_img_background_png);    // assets/background.png
LV_IMG_DECLARE(ui_img_125102533);    // assets/bluetooth-sign_icon.png
LV_IMG_DECLARE(ui_img_wifi_icon_png);    // assets/wifi_icon.png
LV_IMG_DECLARE(ui_img_2012070497);    // assets/low-battery_icon.png
LV_IMG_DECLARE(ui_img_931645554);    // assets/full-battery_icon.png
LV_IMG_DECLARE(ui_img_app_icon_png);    // assets/app_icon.png
LV_IMG_DECLARE(ui_img_setting_icon_png);    // assets/setting_icon.png
LV_IMG_DECLARE(ui_img_folder_icon_png);    // assets/folder_icon.png
LV_IMG_DECLARE(ui_img_mqtt_icon_png);    // assets/mqtt_icon.png
LV_IMG_DECLARE(ui_img_clock_item_png);    // assets/clock_item.png
LV_IMG_DECLARE(ui_img_about_icon_png);    // assets/about_icon.png
LV_IMG_DECLARE(ui_img_wifisetting_icon_png);    // assets/wifisetting_icon.png
LV_IMG_DECLARE(ui_img_bluetooth_icon_png);    // assets/bluetooth_icon.png
LV_IMG_DECLARE(ui_img_display_icon_png);    // assets/display_icon.png
LV_IMG_DECLARE(ui_img_language_icon_png);    // assets/language_icon.png
LV_IMG_DECLARE(ui_img_sensor_icon_png);    // assets/sensor_icon.png
LV_IMG_DECLARE(ui_img_656191529);    // assets/manual-control_icon.png
LV_IMG_DECLARE(ui_img_scheduler_icon_png);    // assets/scheduler_icon.png
LV_IMG_DECLARE(ui_img_pump_icon_png);    // assets/pump_icon.png
LV_IMG_DECLARE(ui_img_brightness_bar_icon_png);    // assets/brightness_bar_icon.png
LV_IMG_DECLARE(ui_img_loop_png);   
LV_IMG_DECLARE(ui_img_farm_icon_png);
LV_IMG_DECLARE(ui_img_trash_png);
LV_IMG_DECLARE(ui_img_tick_png);





void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
