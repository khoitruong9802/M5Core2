#include "ota_service.h"

void ota_update(void *parameter){
    Serial.println("Start OTA");
    ArduinoOTA.begin();
   for (;;)
    {
        delay(1000);
        Serial.println("Scanning OTA");
        ArduinoOTA.handle();
        
    }
    
}