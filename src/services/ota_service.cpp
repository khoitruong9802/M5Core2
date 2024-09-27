#include "ota_service.h"

const char* serverUrl = "http://192.168.1.7:4000/latest-firmware";

void ota_update(void *parameter)
{
    Serial.println("Start OTA");
    HTTPClient http;
    http.begin(serverUrl);
    int httpCode = http.GET();

    if (httpCode == HTTP_CODE_OK) {
        int contentLength = http.getSize();
        bool canBegin = Update.begin(contentLength);

        if (canBegin) {
            Serial.println("Begin OTA update");
            WiFiClient* client = http.getStreamPtr();
            size_t written = Update.writeStream(*client);

            if (written == contentLength) {
                Serial.println("OTA update successful!");
            } else {
                Serial.printf("OTA update failed. Written %d / %d bytes\n", written, contentLength);
            }

            if (Update.end()) {
                if (Update.isFinished()) {
                    Serial.println("Update completed. Rebooting...");
                    ESP.restart();
                } else {
                    Serial.println("Update not finished. Something went wrong.");
                }
            } else {
                Serial.printf("Update failed. Error #: %d\n", Update.getError());
            }
        } else {
            Serial.println("Not enough space to start OTA update");
        }
    } else {
        Serial.printf("Failed to download firmware, error code: %d\n", httpCode);
    }

    http.end();
    Serial.println("End OTA");
}