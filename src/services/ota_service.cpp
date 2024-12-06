#include "ota_service.h"
#include <lvgl.h>


// Function to check for the latest firmware file
String getLatestFirmwareFileName(const char* Url) 
{
    HTTPClient http;
    String latestFirmwareFileName = "";

    http.begin(String(Url) + "/api/v1/OTA/");
    int httpCode = http.GET();

    if (httpCode == HTTP_CODE_OK) 
    {
        String payload = http.getString();
        Serial.println(payload);
        latestFirmwareFileName = payload;
    } 
    else 
    {
        print(PRINTF,"Failed to get the firmware list, error code: %d\n", httpCode);
    }

    http.end();
    return latestFirmwareFileName;
}

void ota_update(void *parameter)
{
    print(PRINTLN,"Start OTA");
    String filename = getLatestFirmwareFileName(ota_server);
    write_new_ota_version(filename);
    print(PRINTF,"Start installing: %s\n", filename.c_str());

    String firmwareURL = ota_server + String("/uploads/") + filename;
    HTTPClient http;
    http.begin(firmwareURL);
    int httpCode = http.GET();
    
    if (httpCode == HTTP_CODE_OK) 
    {
        int contentLength = http.getSize();
        bool canBegin = Update.begin(contentLength);

        if (canBegin) 
        {
            print(PRINTLN,"Begin OTA update");
            WiFiClient* client = http.getStreamPtr();
            size_t written = Update.writeStream(*client);

            if (written == contentLength) 
            {
                print(PRINTLN,"OTA update successful!");
            } else 
            {
                print(PRINTF,"OTA update failed. Written %d / %d bytes\n", written, contentLength);
            }

            if (Update.end()) 
            {
                if (Update.isFinished()) 
                {
                    print(PRINTLN,"Update completed. Rebooting...");
                    ESP.restart();
                } else 
                {
                    print(PRINTLN,"Update not finished. Something went wrong.");
                }
            } else 
            {
                print(PRINTF,"Update failed. Error #: %d\n", Update.getError());
            }
        } else 
        {
            print(PRINTLN,"Not enough space to start OTA update");
        }
    } else 
    {
        print(PRINTF,"Failed to download firmware, error code: %d\n", httpCode);
    }

    http.end();
    print(PRINTLN,"End OTA");
}

void ota_checking_update(void *paramter)
{

    bool alert_screen_flag =  false;

    print(PRINTLN,"Start OTA checking update");
    for(;;)
    {
        if (!SPIFFS.begin(true)) 
        {  // true to format the file system if mounting fails
            print(PRINTLN,"SPIFFS Mount Failed");
        } else 
        {
            print(PRINTLN,"SPIFFS Mount Success");
            break;
        }
    }
    File file = SPIFFS.open("/firmware_version.txt", "r");
    String line = file.readStringUntil('\n');
    for(;;)
    {
        String filename = getLatestFirmwareFileName(ota_server);
        print(PRINTLN,"The original:");
        print(PRINTLN,line.c_str());
        print(PRINTLN,"The new:");
        print(PRINTLN,filename.c_str());
        String name_of_old_file;
        String name_of_new_file;
        for(int i = 0; i <  filename.length() &&  i < line.length(); i++){
            name_of_new_file += filename[i];
            name_of_old_file += line[i];
        }
        if(name_of_new_file == name_of_old_file)
        {
            //TODO
            if(alert_screen_flag == ALERT_SCREEN_ON)
            {
                alert_screen_flag = ALERT_SCREEN_OFF;
            }
            print(PRINTLN,"No change!");
        } 
        else 
        {
            //TODO
            if(alert_screen_flag ==  ALERT_SCREEN_OFF)
            {
                alert_screen_flag = ALERT_SCREEN_ON;
                _ui_flag_modify(ui_Panel100, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
            }
            print(PRINTLN,"changed!");
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void write_new_ota_version(String new_ota_version)
{
    File file = SPIFFS.open("/firmware_version.txt", "w");
    if (!file) {
        print(PRINTLN,"Failed to open file for writing");
    } else {
        file.println(new_ota_version);  // Write the filename to the file
        file.close();            // Close the file after writing
        print(PRINTLN,"File written and closed successfully");
    }

}