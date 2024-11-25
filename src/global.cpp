#include "global.h"

String jsonString;

int numberOfPage;
int numberOfElement;
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
