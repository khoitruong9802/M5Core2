#include "ota_service.h"

void ota_update(void *parameter){
    Serial.println("Start OTA");
    ArduinoOTA.begin();
   for (;;)
    {
        Serial.println("Scanning OTA");
        ArduinoOTA.handle();
        delay(1000);
    }
    
}