#include "global.h"

jsonScheduleItem jsonScheduleItemList[5];

String jsonString;

const char* web_server_official = "";
const char * web_server = "http://192.168.0.103:3000/data";
const char * web_server_2 = "http://192.168.0.103:3000";
const char* ota_server = "http://192.168.0.112:4000";

int numberOfPage;
int numberOfElement;
int currentOfElementHeader;

int current_schedule_id;

uint16_t current_year;
uint16_t current_month;
uint16_t current_day;

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
