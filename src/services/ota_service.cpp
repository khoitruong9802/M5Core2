#include "ota_service.h"
#include <lvgl.h>
const char* web_server = "http://192.168.0.112:4000";

// Function to check for the latest firmware file
String getLatestFirmwareFileName(const char* Url) 
{
    HTTPClient http;
    String latestFirmwareFileName = "";

    http.begin(String(Url) + "/upload");
    int httpCode = http.GET();

    if (httpCode == HTTP_CODE_OK) 
    {
        String payload = http.getString();

        // Find all occurrences of firmware file links in the HTML payload
        int startIndex = 0;
        String latestTimestamp = "";

        while ((startIndex = payload.indexOf("<a href=\"/uploads/", startIndex)) != -1) 
        {
            startIndex += 18; // Move to the start of the file name
            int endIndex = payload.indexOf("\">", startIndex); // Find the end of the file link

            if (endIndex != -1) 
            {
                // Extract the file name
                String filePath = payload.substring(startIndex, endIndex);
                
                // Extract the timestamp part from the file name
                String timestamp = filePath.substring(0, filePath.indexOf('_'));
                
                // Compare with the current latest timestamp
                if (latestTimestamp == "" || timestamp > latestTimestamp) 
                {
                    latestTimestamp = timestamp;
                    latestFirmwareFileName = filePath;  // Update the latest firmware file name
                }
                
                startIndex = endIndex; // Move to the next link
            } 
            else 
            {
                break; // Break if no more links found
            }
        }
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
    String filename = getLatestFirmwareFileName(web_server);
    write_new_ota_version(filename);
    print(PRINTF,"Start installing: %s\n", filename.c_str());

    String firmwareURL = web_server + String("/uploads/") + filename;
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
        String filename = getLatestFirmwareFileName(web_server);
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
        delay(3000);
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