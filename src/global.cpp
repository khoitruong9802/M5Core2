#include "global.h"

Preferences preferences;

jsonScheduleItem jsonScheduleItemList[3];

String jsonString;

const char* web_server_official = "";
const char * web_server = "http://192.168.0.103:3000/data";
const char * web_server_2 = "http://192.168.0.103:3000";
const char* ota_server = "http://192.168.0.112:4000";

int numberOfPage;
int numberOfElement;
int currentPage;

int current_schedule_id;

int currentWateringHistoryPage;
int totalWateringHistoryPage;

uint16_t current_year;
uint16_t current_month;
uint16_t current_day;

bool convert_mqtt_task = 0;
bool touch_enabled;

const char *str_topic_temp1;
const char *str_topic_humi1;
const char *str_topic_kali1;
const char *str_topic_nito1;
const char *str_topic_photpho1;
const char *str_topic_temp2;
const char *str_topic_humi2;
const char *str_topic_kali2;
const char *str_topic_nito2;
const char *str_topic_photpho2;
const char *str_topic_temp3;
const char *str_topic_humi3;
const char *str_topic_kali3;
const char *str_topic_nito3;
const char *str_topic_photpho3;

//GENERAL
int current_area_for_sensors_log;
int current_area_for_sensors;

bool is_touching = false;

void print(uint8_t print_mode, const char* msg, ...) {
    if (DEBUG_MODE == 1) {
        va_list args;
        va_start(args, msg);

        char buffer[256];  // Create a buffer large enough for your formatted string

        switch (print_mode) {
            case PRINT:
                Serial.print(msg);
                break;
                
            case PRINTLN:
                Serial.println(msg);
                break;
                
            case PRINTF:
                vsnprintf(buffer, sizeof(buffer), msg, args);  // Format the string with va_list
                Serial.print(buffer);  // Print the formatted string
                break;
                
            default:
                Serial.println("Invalid print mode");
        }

        va_end(args);
    }
}

void buzz_in_second()
{
    // Rung trong 1 giây
    if (M5.getBoard() == m5::board_t::board_M5StackCore2) {
        // Bật rung bằng cách đặt LDO3 ở mức 3.3V
        M5.Power.Axp192.setLDO3(3300); // Đơn vị: mV
        delay(1000);                   // Rung trong 1 giây
        // Tắt rung bằng cách đặt LDO3 về 0V
        M5.Power.Axp192.setLDO3(0);
    }
}