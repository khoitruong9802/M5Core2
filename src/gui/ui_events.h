// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: m5core2

#ifndef _UI_EVENTS_H
#define _UI_EVENTS_H

#ifdef __cplusplus
extern "C" {
#endif
void change_screen_mqtt(lv_event_t * e);
void scan_network(lv_event_t * e);
void button1_on(lv_event_t * e);
void button1_off(lv_event_t * e);
void button2_on(lv_event_t * e);
void button2_off(lv_event_t * e);
void change_brightness(lv_event_t * e);
void change_screen_ota(lv_event_t * e);
void handle_out_ota_page();
void handle_start_ota();
void schedule_screen_init(lv_event_t * e);
void deleteObject(lv_obj_t * obj);
void ui_event_DropdownClickedScheduleRepeatScheduleItem(lv_event_t * e);
void ui_event_CheckboxScheduleEndDateScheduleItem(lv_event_t * e);
void ui_event_PanelScheduleWeekItemMondayScheduleItem(lv_event_t * e);
void ui_event_PanelScheduleWeekItemTuesdayScheduleItem(lv_event_t * e);
void ui_event_PanelScheduleWeekItemWednesdayScheduleItem(lv_event_t * e);
void ui_event_PanelScheduleWeekItemThursdayScheduleItem(lv_event_t * e);
void ui_event_PanelScheduleWeekItemFridayScheduleItem(lv_event_t * e);
void ui_event_PanelScheduleWeekItemSaturdayScheduleItem(lv_event_t * e);
void ui_event_PanelScheduleWeekItemSundayScheduleItem(lv_event_t * e);
void ui_event_ButtonOKHeaderScheduleItem(lv_event_t * e);
void ui_event_ButtonCancelHeaderScheduleItem(lv_event_t * e);
void ui_event_PanelPageItemTitleScheduleScreen0(lv_event_t * e);
void ui_event_PanelPageItemTitleScheduleScreen1(lv_event_t * e);
void ui_event_PanelPageItemTitleScheduleScreen2(lv_event_t * e);
void ui_event_ButtonNextPageItemTitleScheduleScreen(lv_event_t *e);
void ui_event_ButtonPreviousPageItemTitleScheduleScreen(lv_event_t *e);
void ui_event_PanelRemoveOptionHeaderScheduleScreen(lv_event_t * e);
void ui_event_AddOptionHeaderScheduleScreen(lv_event_t * e);
void printText(const char * text);
uint16_t get_hour(const char *time_str);
uint16_t get_minute(const char *time_str);
uint32_t get_year(const char * date_str);
uint32_t get_month(const char * date_str);
uint32_t get_day(const char * date_str);
uint32_t get_current_year();
uint32_t get_current_month();
uint32_t get_current_day();
const char* formatTime(uint16_t hour, uint16_t minute);
const char* formatDate(uint16_t year, uint16_t month, uint16_t day);
int convertStringToInt(const char* str);
const char * convertPriorityToCstr(int priority);
const char* convertTimeToHHMM(const char* time) ;
void addNewRequest(const char* baseServerURL, int schedule_id, const char* jsonPayload);
void sendPutRequest(const char* serverURL, const char* jsonPayload);
void updatePageScheduleItem(int indexOfElement);
void sendDeleteRequest(int schedule_id);
void updateItemforScheduleScreen(int hidden_all_flag, int number_appear);
#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
