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
extern lv_obj_t * ui_PanelBattery;
extern lv_obj_t * ui_LabelBattery;
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
void ui_event_Panel1(lv_event_t * e);
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

extern lv_obj_t * ui_Panel29;
extern lv_obj_t * ui_Label33;
extern lv_obj_t * ui_Panel39;
void ui_event_Button1(lv_event_t * e);
extern lv_obj_t * ui_Button1;
extern lv_obj_t * ui_Label31;
extern lv_obj_t * ui_Panel90;
extern lv_obj_t * ui_Panel91;
extern lv_obj_t * ui_Label90;
extern lv_obj_t * ui_Panel40;
extern lv_obj_t * ui_Spinner1;
extern lv_obj_t * ui_Panel41;
extern lv_obj_t * ui_Button2;
extern lv_obj_t * ui_Label35;
extern lv_obj_t * ui_Label34;
void ui_event_Button2(lv_event_t * e);
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
// SCREEN: ui_InformationScreen
void ui_InformationScreen_screen_init(void);
void ui_event_InformationScreen(lv_event_t * e);
extern lv_obj_t * ui_InformationScreen;
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
void ui_event_PanelHistoryItemFarmScreen(lv_event_t * e);
void ui_event_Panel47(lv_event_t * e);
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
extern lv_obj_t * ui_Label155;
extern lv_obj_t * ui_Label166;
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
extern lv_obj_t * wifiLoading;
extern lv_obj_t * wifiSpinnerLoading;
extern lv_obj_t * wifiLabelLoading;
// SCREEN: ui_ScheduleScreen
void ui_ScheduleScreen_screen_init(void);
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
extern lv_obj_t * ui_PanelFlow1ContainerScheduleItem;
extern lv_obj_t * ui_LabelFlow1TitleScheduleItem;
void ui_event_PanelFlow1ScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_PanelFlow1ScheduleItem;
extern lv_obj_t * ui_LabelFlow1ScheduleItem;
extern lv_obj_t * ui_PanelFlow2ContainerScheduleItem;
extern lv_obj_t * ui_LabelFlow2TitleScheduleItem;
void ui_event_PanelFlow2ScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_PanelFlow2ScheduleItem;
extern lv_obj_t * ui_LabelFlow2ScheduleItem;
extern lv_obj_t * ui_PanelFlow3ContainerScheduleItem;
extern lv_obj_t * ui_LabelFlow3TitleScheduleItem;
void ui_event_PanelFlow3ScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_PanelFlow3ScheduleItem;
extern lv_obj_t * ui_LabelFlow3ScheduleItem;
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
// SCREEN: ui_Flow1
void ui_Flow1_screen_init(void);
extern lv_obj_t * ui_Flow1;
extern lv_obj_t * ui_Flow1ScheduleItemScreen;
extern lv_obj_t * ui_LabelTitleFlow1ScheduleItem;
void ui_event_PanelCloseButtonFlow1ScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_PanelCloseButtonFlow1ScheduleItem;
extern lv_obj_t * ui_LabelCloseButtonFlow1ScheduleItem;
void ui_event_TextAreaFlow1ScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_TextAreaFlow1ScheduleItem;
extern lv_obj_t * ui_KeyboardFlow1ScheduleItem;
extern lv_obj_t * ui_LabelUnitFlow1ScheduleItem;
extern lv_obj_t * ui_PanelTextAreaFlow1ScheduleItem;
// SCREEN: ui_Flow2
void ui_Flow2_screen_init(void);
extern lv_obj_t * ui_Flow2;
extern lv_obj_t * ui_Flow2ScheduleItemScreen;
extern lv_obj_t * ui_LabelTitleFlow2ScheduleItem;
void ui_event_PanelCloseButtonFlow2ScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_PanelCloseButtonFlow2ScheduleItem;
extern lv_obj_t * ui_LabelCloseButtonFlow2ScheduleItem;
void ui_event_TextAreaFlow2ScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_TextAreaFlow2ScheduleItem;
extern lv_obj_t * ui_KeyboardFlow2ScheduleItem;
extern lv_obj_t * ui_LabelUnitFlow2ScheduleItem;
extern lv_obj_t * ui_PanelTextAreaFlow2ScheduleItem;
// SCREEN: ui_Flow3
void ui_Flow3_screen_init(void);
extern lv_obj_t * ui_Flow3;
extern lv_obj_t * ui_Flow3ScheduleItemScreen;
extern lv_obj_t * ui_LabelTitleFlow3ScheduleItem;
void ui_event_PanelCloseButtonFlow3ScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_PanelCloseButtonFlow3ScheduleItem;
extern lv_obj_t * ui_LabelCloseButtonFlow3ScheduleItem;
void ui_event_TextAreaFlow3ScheduleItem(lv_event_t * e);
extern lv_obj_t * ui_TextAreaFlow3ScheduleItem;
extern lv_obj_t * ui_KeyboardFlow3ScheduleItem;
extern lv_obj_t * ui_LabelUnitFlow3ScheduleItem;
extern lv_obj_t * ui_PanelTextAreaFlow3ScheduleItem;
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
// SCREEN: ui_farm
void ui_farmScreen_screen_init(void);
extern lv_obj_t * ui_farmScreen;
extern lv_obj_t * ui_farmScreen_screen;
extern lv_obj_t * ui_PanelfarmScreen_screen;
void ui_event_PanelDeviceItemFarmScreen(lv_event_t * e);
extern lv_obj_t * ui_PanelDeviceItemFarmScreen;
extern lv_obj_t * ui_ImgDeviceItemFarmScreen;
extern lv_obj_t * ui_LabelDeviceItemFarmScreen;
void ui_event_PanelScheduleItemFarmScreen(lv_event_t * e);
extern lv_obj_t * ui_PanelScheduleItemFarmScreen;
extern lv_obj_t * ui_ImgScheduleItemFarmScreen;
extern lv_obj_t * ui_LabelScheduleItemFarmScreen;
extern lv_obj_t * ui_PanelHistoryItemFarmScreen;
extern lv_obj_t * ui_ImgHistoryItemFarmScreen;
extern lv_obj_t * ui_LabelHistoryItemFarmScreen;
void ui_event_farmScreen(lv_event_t * e);
void ui_event_ButtonHeaderLoadingFarm(lv_event_t * e);
extern lv_obj_t * ui_PanelLoadingFarmScreen;
extern lv_obj_t * ui_SpinnerLoadingFarm;
extern lv_obj_t * ui_PanelHeaderLoadingFarm;
extern lv_obj_t * ui_ButtonHeaderLoadingFarm;
extern lv_obj_t * ui_LabelHeaderLoadingFarm;
extern lv_obj_t * ui_LabelMesageLoadingFarm;
extern lv_obj_t * ui_PanelNotification1FarmScreen;
extern lv_obj_t * ui_LabelMessageNotification1Farm;
extern lv_obj_t * ui_PanelHeaderNotification1Farm;
void ui_event_ButtonCloseHeaderNotification1Farm(lv_event_t * e);
extern lv_obj_t * ui_ButtonCloseHeaderNotification1Farm;
extern lv_obj_t * ui_LabelCloseHeaderNotification1Farm;
void ui_event_ThreshHoldItemFarmScreen(lv_event_t * e);
extern lv_obj_t * ui_PanelThreshHoldItemFarmScreen;
extern lv_obj_t * ui_ImgThreshHoldItemFarmScreen;
extern lv_obj_t * ui_LabelThreshHoldItemFarmScreen;
// SCREEN: ui_Notification
void ui_Notification_screen_init(void);
void ui_event_Notification(lv_event_t * e);
extern lv_obj_t * ui_Notification;
extern lv_obj_t * ui_NotificationScreen;
extern lv_obj_t * ui_LabelTitleNotification;
extern lv_obj_t * ui_PanelNotificationItem1;
extern lv_obj_t * ui_LabelNotificationItem1;
extern lv_obj_t * ui_PanelNotificationItem2;
extern lv_obj_t * ui_LabelNotificationItem2;
extern lv_obj_t * ui_PanelNotificationItem3;
extern lv_obj_t * ui_LabelNotificationItem3;
extern lv_obj_t * ui_PanelNotificationItem4;
extern lv_obj_t * ui_LabelNotificationItem4;
extern lv_obj_t * ui_PanelNotificationItem5;
extern lv_obj_t * ui_LabelNotificationItem5;
extern lv_obj_t * ui_PanelLoadingNotificationScreen;
extern lv_obj_t * ui_SpinnerLoadingNotificationScreen;
extern lv_obj_t * ui_LabelLoadingNotificationScreen;

// SCREEN: ui_wateringHistory
void ui_wateringHistory_screen_init(void);
void ui_event_wateringHistory(lv_event_t * e);
extern lv_obj_t * ui_wateringHistory;
extern lv_obj_t * ui_wateringHistoryScreen;
extern lv_obj_t * ui_LabelTitleWateringHistory;
extern lv_obj_t * ui_PanelHeaderWateringHistoryContainer;
extern lv_obj_t * ui_ButtonPreviousHeaderWateringHistory;
extern lv_obj_t * ui_LabelPreviousHeaderWateringHistory;
extern lv_obj_t * ui_PanelHeaderWateringHistory;
extern lv_obj_t * ui_PanelItem1HeaderWateringHistory;
extern lv_obj_t * ui_LabelItem1HeaderWateringHistory;
extern lv_obj_t * ui_PanelItem2HeaderWateringHistory;
extern lv_obj_t * ui_LabelItem2HeaderWateringHistory;
extern lv_obj_t * ui_PanelItem3HeaderWateringHistory;
extern lv_obj_t * ui_LabelItem3HeaderWateringHistory;
extern lv_obj_t * ui_ButtonNextHeaderWateringHistory;
extern lv_obj_t * ui_LabelNextHeaderWateringHistory;
extern lv_obj_t * ui_PanelWateringHistoryItem1;
extern lv_obj_t * ui_LabelNameWateringHistoryItem1;
extern lv_obj_t * ui_LabelAreaWateringHistoryItem1;
extern lv_obj_t * ui_LabelResultWaterQuantityWateringHistoryItem1;
extern lv_obj_t * ui_PanelStartTimeWateringHistoryItem1;
extern lv_obj_t * ui_LabelStartTimeWateringHistoryItem1;
extern lv_obj_t * ui_PanelEndTimeWateringHistoryItem1;
extern lv_obj_t * ui_LabelEndTimeWateringHistoryItem1;
extern lv_obj_t * ui_PanelWateringQuantityWateringHistoryItem1;
extern lv_obj_t * ui_LabelWateringQuantityWateringHistoryItem1;
extern lv_obj_t * ui_PanelWateringHistoryItem2;
extern lv_obj_t * ui_LabelNameWateringHistoryItem2;
extern lv_obj_t * ui_LabelAreaWateringHistoryItem2;
extern lv_obj_t * ui_LabelResultWaterQuantityWateringHistoryItem2;
extern lv_obj_t * ui_PanelStartTimeWateringHistoryItem2;
extern lv_obj_t * ui_LabelStartTimeWateringHistoryItem2;
extern lv_obj_t * ui_PanelEndTimeWateringHistoryItem2;
extern lv_obj_t * ui_LabelEndTimeWateringHistoryItem2;
extern lv_obj_t * ui_PanelWateringQuantityWateringHistoryItem2;
extern lv_obj_t * ui_LabelWateringQuantityWateringHistoryItem2;
extern lv_obj_t * ui_PanelWateringHistoryItem3;
extern lv_obj_t * ui_LabelNameWateringHistoryItem3;
extern lv_obj_t * ui_LabelAreaWateringHistoryItem3;
extern lv_obj_t * ui_LabelResultWaterQuantityWateringHistoryItem3;
extern lv_obj_t * ui_PanelStartTimeWateringHistoryItem3;
extern lv_obj_t * ui_LabelStartTimeWateringHistoryItem3;
extern lv_obj_t * ui_PanelEndTimeWateringHistoryItem3;
extern lv_obj_t * ui_LabelEndTimeWateringHistoryItem3;
extern lv_obj_t * ui_PanelWateringQuantityWateringHistoryItem3;
extern lv_obj_t * ui_LabelWateringQuantityWateringHistoryItem3;
extern lv_obj_t * ui_PanelLoadingWateringHistoryScreen;
extern lv_obj_t * ui_SpinnerLoadingWateringHistoryScreen;
extern lv_obj_t * ui_LabelLoadingWateringHistoryScreen;
void ui_event_PanelItem1HeaderWateringHistory(lv_event_t * e);
void ui_event_PanelItem2HeaderWateringHistory(lv_event_t * e);
void ui_event_PanelItem3HeaderWateringHistory(lv_event_t * e);
void ui_event_ButtonPreviousHeaderWateringHistory(lv_event_t * e);
void ui_event_ButtonNextHeaderWateringHistory(lv_event_t * e);

//SCREEN: ui_SensorsArea
void ui_SensorsAreaScreen_screen_init(void);
void ui_event_SensorsAreaScreen(lv_event_t * e);
extern lv_obj_t * ui_SensorsAreaScreen;
extern lv_obj_t * ui_SensorsAreaScreen_screen;
extern lv_obj_t * ui_PanelSensorsAreaScreen_screen;
extern lv_obj_t * ui_PanelArea1SensorsArea;
extern lv_obj_t * ui_LabelArea1SensorsArea;
extern lv_obj_t * ui_PanelArea2SensorsArea;
extern lv_obj_t * ui_LabelArea2SensorsArea;
extern lv_obj_t * ui_PanelArea3SensorsArea;
extern lv_obj_t * ui_LabelArea3SensorsArea;
void ui_event_PanelArea1SensorArea(lv_event_t * e);
void ui_event_PanelArea2SensorArea(lv_event_t * e);
void ui_event_PanelArea3SensorArea(lv_event_t * e);


// SCREEN: ui_SoilTemperatureSensor
void ui_SoilTemperatureSensor_screen_init(void);
void ui_event_SoilTemperatureSensor(lv_event_t * e);
extern lv_obj_t * ui_SoilTemperatureSensor;
extern lv_obj_t * ui_SoilTemperatureSensorScreen;
extern lv_obj_t * ui_ChartSoilTemperatureSensor;
extern lv_obj_t * ui_LabelSoilTemperatureSensor;
// SCREEN: ui_SoidHumiditySensor
void ui_SoidHumiditySensor_screen_init(void);
void ui_event_SoidHumiditySensor(lv_event_t * e);
extern lv_obj_t * ui_SoidHumiditySensor;
extern lv_obj_t * ui_SoidHumiditySensorScreen;
extern lv_obj_t * ui_ChartSoidHumiditySensor;
extern lv_obj_t * ui_LabelTitleSoidHumiditySensor;
// SCREEN: ui_SoidNitro
void ui_SoidNitro_screen_init(void);
void ui_event_SoidNitro(lv_event_t * e);
extern lv_obj_t * ui_SoidNitro;
extern lv_obj_t * ui_SoidNitroScreen;
extern lv_obj_t * ui_ChartSoidNitro;
extern lv_obj_t * ui_labelTitleSoidNitro;
// SCREEN: ui_SoidKali
void ui_SoidKali_screen_init(void);
void ui_event_SoidKali(lv_event_t * e);
extern lv_obj_t * ui_SoidKali;
extern lv_obj_t * ui_SoidKaliScreen;
extern lv_obj_t * ui_ChartSoidKali;
extern lv_obj_t * ui_LabelSoidKali;
extern lv_obj_t * ui____initial_actions0;
// SCREEN: ui_SoidPhotpho
void ui_SoidPhotpho_screen_init(void);
void ui_event_SoidPhotpho(lv_event_t * e);
extern lv_obj_t * ui_SoidPhotpho;
extern lv_obj_t * ui_SoidPhotphoScreen;
extern lv_obj_t * ui_ChartSoidPhotpho;
extern lv_obj_t * ui_labelTitleSoidPhotpho;
// SCREEN: ui_DevicesScreen
void ui_DevicesAreaScreen_screen_init(void);
extern lv_obj_t * ui_DevicesAreaScreen;
extern lv_obj_t * ui_DevicesAreaScreen_screen;
extern lv_obj_t * ui_PanelDevicesAreaScreen_screen;
extern lv_obj_t * ui_PanelArea1DevicesArea;
extern lv_obj_t * ui_LabelArea1DevicesArea;
extern lv_obj_t * ui_PanelArea2DevicesArea;
extern lv_obj_t * ui_LabelArea2DevicesArea;
extern lv_obj_t * ui_PanelArea3DevicesArea;
extern lv_obj_t * ui_LabelArea3DevicesArea;
void ui_event_DevicesAreaScreen(lv_event_t * e);
//SCREEN: ui_SensorsLogArea
void ui_SensorsLogAreaScreen_screen_init(void);
void ui_event_SensorsLogAreaScreen(lv_event_t * e);
extern lv_obj_t * ui_SensorsLogAreaScreen;
extern lv_obj_t * ui_SensorsLogAreaScreen_screen;
extern lv_obj_t * ui_PanelSensorsLogAreaScreen_screen;
extern lv_obj_t * ui_PanelArea1SensorsLogArea;
extern lv_obj_t * ui_LabelArea1SensorsLogArea;
extern lv_obj_t * ui_PanelArea2SensorsLogArea;
extern lv_obj_t * ui_LabelArea2SensorsLogArea;
extern lv_obj_t * ui_PanelArea3SensorsLogArea;
extern lv_obj_t * ui_LabelArea3SensorsLogArea;


//SCREEN: ui_SensorsLogList
void ui_SensorsLogListScreen_screen_init(void);
void ui_event_SensorsLogListScreen(lv_event_t * e);
extern lv_obj_t * ui_SensorsLogListScreen;
extern lv_obj_t * ui_SensorsLogListScreen_screen;
extern lv_obj_t * ui_PanelSensorsLogListScreen_screen;
extern lv_obj_t * ui_PanelItem1SensorsLogList;
extern lv_obj_t * ui_LabelItem1SensorsLogList;
extern lv_obj_t * ui_PanelItem2SensorsLogList;
extern lv_obj_t * ui_LabelItem2SensorsLogList;
extern lv_obj_t * ui_PanelItem3SensorsLogList;
extern lv_obj_t * ui_LabelItem3SensorsLogList;
extern lv_obj_t * ui_PanelItem4SensorsLogList;
extern lv_obj_t * ui_LabelItem4SensorsLogList;
extern lv_obj_t * ui_PanelItem5SensorsLogList;
extern lv_obj_t * ui_LabelItem5SensorsLogList;
extern lv_obj_t * ui_PanelSensorsLogScheduleItemScreen;
extern lv_obj_t * ui_SpinnerSensorsLogScheduleItemScreen;
extern lv_obj_t * ui_LabelSensorsLogScheduleItemScreen;

//SCREEN: ui_LoadingScreen
void ui_Loading_screen_init(void);
extern lv_obj_t * ui_Loading;
extern lv_obj_t * ui_PanelLoadingLoadingScreen;
extern lv_obj_t * ui_SpinnerLoadingLoadingScreen;
extern lv_obj_t * ui_LabelLoadingLoadingScreen;

extern lv_chart_series_t * ui_ChartSoilTemperatureSensor_series_1;
extern lv_chart_series_t * ui_ChartSoidHumiditySensor_series_1;
extern lv_chart_series_t * ui_ChartSoidKali_series_1;
extern lv_chart_series_t * ui_ChartSoidNitro_series_1;
extern lv_chart_series_t * ui_ChartSoidPhotpho_series_1;

//SCREEN: ui_thresholdAreaScreen
void ui_ThresholdAreaScreen_screen_init(void);
extern lv_obj_t *ui_ThresholdAreaScreen;
extern lv_obj_t *ui_ThresholdAreaScreen_screen;
extern lv_obj_t *ui_PanelThresholdAreaScreen_screen;
extern lv_obj_t *ui_PanelArea1ThresholdArea;
extern lv_obj_t *ui_LabelArea1ThresholdArea;
extern lv_obj_t *ui_PanelArea2ThresholdArea;
extern lv_obj_t *ui_LabelArea2ThresholdArea;
extern lv_obj_t *ui_PanelArea3ThresholdArea;
extern lv_obj_t *ui_LabelArea3ThresholdArea;
void ui_event_ThresholdAreaScreen(lv_event_t * e);


// SCREEN: ui_ThresHoldScreen
void ui_ThresHoldScreen_screen_init(void);
extern lv_obj_t * ui_ThresHoldScreen;
extern lv_obj_t * ui_ThresHoldScreenScreen;
extern lv_obj_t * ui_PanelScheduleItemScreen;
extern lv_obj_t * ui_PanelContainerTemperature1;
extern lv_obj_t * ui_LabelTitleTemperature1;
void ui_event_PanelTemperature1(lv_event_t * e);
extern lv_obj_t * ui_PanelTemperature1;
extern lv_obj_t * ui_LabelTemperature1;
extern lv_obj_t * ui_PanelContainerTemperature2;
extern lv_obj_t * ui_LabelTitleTemperature2;
void ui_event_PanelTemperature2(lv_event_t * e);
extern lv_obj_t * ui_PanelTemperature2;
extern lv_obj_t * ui_LabelTemperature2;
extern lv_obj_t * ui_PanelContainerKali1;
extern lv_obj_t * ui_LabelTitleKali1;
void ui_event_PanelKali1(lv_event_t * e);
extern lv_obj_t * ui_PanelKali1;
extern lv_obj_t * ui_LabelKali1;
extern lv_obj_t * ui_PanelContainerKali2;
extern lv_obj_t * ui_LabelTitleKali2;
void ui_event_PanelKali2(lv_event_t * e);
extern lv_obj_t * ui_PanelKali2;
extern lv_obj_t * ui_LabelKali2;
extern lv_obj_t * ui_PanelContainerNito1;
extern lv_obj_t * ui_LabelTitleNito1;
void ui_event_PanelNito1(lv_event_t * e);
extern lv_obj_t * ui_PanelNito1;
extern lv_obj_t * ui_LabelNito1;
extern lv_obj_t * ui_PanelContainerNito2;
extern lv_obj_t * ui_LabelTitleNito2;
void ui_event_PanelNito2(lv_event_t * e);
extern lv_obj_t * ui_PanelNito2;
extern lv_obj_t * ui_LabelNito2;
extern lv_obj_t * ui_PanelContainerPhotpho1;
extern lv_obj_t * ui_LabelTitlePhotpho1;
void ui_event_PanelPhotpho1(lv_event_t * e);
extern lv_obj_t * ui_PanelPhotpho1;
extern lv_obj_t * ui_LabelPhotpho1;
extern lv_obj_t * ui_PanelContainerPhotpho2;
extern lv_obj_t * ui_LabelTitlePhotpho2;
void ui_event_PanelPhotpho2(lv_event_t * e);
extern lv_obj_t * ui_PanelPhotpho2;
extern lv_obj_t * ui_LabelPhotpho2;
void ui_event_ButtonCancelThresHoldItem(lv_event_t * e);
extern lv_obj_t * ui_ButtonCancelThresHoldItem;
extern lv_obj_t * ui_LabelCancelThresHoldItem;
extern lv_obj_t * ui_ButtonThresHoldItem;
extern lv_obj_t * ui_LabelOKThresHoldItem;
extern lv_obj_t * ui_PanelContainer;
extern lv_obj_t * ui_PanelLoadingThresHoldItem;
extern lv_obj_t * ui_SpinnerLoadingThresHoldItem;
extern lv_obj_t * ui_LabelLoadingThresHoldItem;
// SCREEN: ui_ThresHoldItemScreen1
void ui_ThresHoldItemScreen1_screen_init(void);
extern lv_obj_t * ui_ThresHoldItemScreen1;
extern lv_obj_t * ui_ThresHoldItemContainer1;
extern lv_obj_t * ui_LabelTitleThresHoldItem1;
void ui_event_PanelButtonXThresHoldItem1(lv_event_t * e);
extern lv_obj_t * ui_PanelButtonXThresHoldItem1;
extern lv_obj_t * ui_LabelButtonXThresHoldItem1;
extern lv_obj_t * ui_KeyboardThresHoldItem1;
extern lv_obj_t * ui_PanelThresHoldItemContainer1;
extern lv_obj_t * ui_TextAreaThresHoldItem1;
// SCREEN: ui_ThresHoldItemScreen2
void ui_ThresHoldItemScreen2_screen_init(void);
extern lv_obj_t * ui_ThresHoldItemScreen2;
extern lv_obj_t * ui_ThresHoldItemContainer2;
extern lv_obj_t * ui_LabelTitleThresHoldItem2;
void ui_event_PanelButtonXThresHoldItem2(lv_event_t * e);
extern lv_obj_t * ui_PanelButtonXThresHoldItem2;
extern lv_obj_t * ui_LabelButtonXThresHoldItem2;
extern lv_obj_t * ui_KeyboardThresHoldItem2;
extern lv_obj_t * ui_PanelThresHoldItemContainer2;
extern lv_obj_t * ui_TextAreaThresHoldItem2;
// SCREEN: ui_ThresHoldItemScreen3
void ui_ThresHoldItemScreen3_screen_init(void);
extern lv_obj_t * ui_ThresHoldItemScreen3;
extern lv_obj_t * ui_ThresHoldItemContainer3;
extern lv_obj_t * ui_LabelTitleThresHoldItem3;
void ui_event_PanelButtonXThresHoldItem3(lv_event_t * e);
extern lv_obj_t * ui_PanelButtonXThresHoldItem3;
extern lv_obj_t * ui_LabelButtonXThresHoldItem3;
extern lv_obj_t * ui_KeyboardThresHoldItem3;
extern lv_obj_t * ui_PanelThresHoldItemContainer3;
extern lv_obj_t * ui_TextAreaThresHoldItem3;
// SCREEN: ui_ThresHoldItemScreen4
void ui_ThresHoldItemScreen4_screen_init(void);
extern lv_obj_t * ui_ThresHoldItemScreen4;
extern lv_obj_t * ui_ThresHoldItemContainer4;
extern lv_obj_t * ui_LabelTitleThresHoldItem4;
void ui_event_PanelButtonXThresHoldItem4(lv_event_t * e);
extern lv_obj_t * ui_PanelButtonXThresHoldItem4;
extern lv_obj_t * ui_LabelButtonXThresHoldItem4;
extern lv_obj_t * ui_KeyboardThresHoldItem4;
extern lv_obj_t * ui_PanelThresHoldItemContainer4;
extern lv_obj_t * ui_TextAreaThresHoldItem4;
// SCREEN: ui_ThresHoldItemScreen5
void ui_ThresHoldItemScreen5_screen_init(void);
extern lv_obj_t * ui_ThresHoldItemScreen5;
extern lv_obj_t * ui_ThresHoldItemContainer5;
extern lv_obj_t * ui_LabelTitleThresHoldItem5;
void ui_event_PanelButtonXThresHoldItem5(lv_event_t * e);
extern lv_obj_t * ui_PanelButtonXThresHoldItem5;
extern lv_obj_t * ui_LabelButtonXThresHoldItem5;
extern lv_obj_t * ui_KeyboardThresHoldItem5;
extern lv_obj_t * ui_PanelThresHoldItemContainer5;
extern lv_obj_t * ui_TextAreaThresHoldItem5;
// SCREEN: ui_ThresHoldItemScreen6
void ui_ThresHoldItemScreen6_screen_init(void);
extern lv_obj_t * ui_ThresHoldItemScreen6;
extern lv_obj_t * ui_ThresHoldItemContainer6;
extern lv_obj_t * ui_LabelTitleThresHoldItem6;
void ui_event_PanelButtonXThresHoldItem6(lv_event_t * e);
extern lv_obj_t * ui_PanelButtonXThresHoldItem6;
extern lv_obj_t * ui_LabelButtonXThresHoldItem6;
extern lv_obj_t * ui_KeyboardThresHoldItem6;
extern lv_obj_t * ui_PanelThresHoldItemContainer6;
extern lv_obj_t * ui_TextAreaThresHoldItem6;
// SCREEN: ui_ThresHoldItemScreen7
void ui_ThresHoldItemScreen7_screen_init(void);
extern lv_obj_t * ui_ThresHoldItemScreen7;
extern lv_obj_t * ui_ThresHoldItemContainer7;
extern lv_obj_t * ui_LabelTitleThresHoldItem7;
void ui_event_PanelButtonXThresHoldItem7(lv_event_t * e);
extern lv_obj_t * ui_PanelButtonXThresHoldItem7;
extern lv_obj_t * ui_LabelButtonXThresHoldItem7;
extern lv_obj_t * ui_KeyboardThresHoldItem7;
extern lv_obj_t * ui_PanelThresHoldItemContainer7;
extern lv_obj_t * ui_TextAreaThresHoldItem7;
// SCREEN: ui_ThresHoldItemScreen8
void ui_ThresHoldItemScreen8_screen_init(void);
extern lv_obj_t * ui_ThresHoldItemScreen8;
extern lv_obj_t * ui_ThresHoldItemContainer8;
extern lv_obj_t * ui_LabelTitleThresHoldItem8;
void ui_event_PanelButtonXThresHoldItem8(lv_event_t * e);
extern lv_obj_t * ui_PanelButtonXThresHoldItem8;
extern lv_obj_t * ui_LabelButtonXThresHoldItem8;
extern lv_obj_t * ui_KeyboardThresHoldItem8;
extern lv_obj_t * ui_PanelThresHoldItemContainer8;
extern lv_obj_t * ui_TextAreaThresHoldItem8;

void ui_event_TextAreaThresHoldItem1(lv_event_t * e);
void ui_event_TextAreaThresHoldItem2(lv_event_t * e);
void ui_event_TextAreaThresHoldItem3(lv_event_t * e);
void ui_event_TextAreaThresHoldItem4(lv_event_t * e);
void ui_event_TextAreaThresHoldItem5(lv_event_t * e);
void ui_event_TextAreaThresHoldItem6(lv_event_t * e);
void ui_event_TextAreaThresHoldItem7(lv_event_t * e);
void ui_event_TextAreaThresHoldItem8(lv_event_t * e);


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
LV_IMG_DECLARE(ui_img_chart_png);
LV_IMG_DECLARE(ui_img_device_png);
LV_IMG_DECLARE(ui_img_process_png);
LV_IMG_DECLARE(ui_img_bell_png);
LV_IMG_DECLARE(ui_img_history_png);
LV_IMG_DECLARE(ui_img_threshold_png);






#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
