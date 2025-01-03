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
    lv_label_set_text(ui_Label90, "Starting OTA update...");
    print(PRINTLN, "Start OTA");
    String filename = getLatestFirmwareFileName(ota_server);
    print(PRINTF, "Start installing: %s\n", filename.c_str());

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
            print(PRINTLN, "Begin OTA update");
            ota_running_flag = true;
            lv_label_set_text(ui_Label90, "OTA update in progress...");
            WiFiClient *client = http.getStreamPtr();

            bool wifiLost = false; // Theo dõi trạng thái WiFi
            size_t written = 0;

            while (written < contentLength)
            {
                if (WiFi.status() != WL_CONNECTED)
                {
                    ota_running_flag = false;
                    wifiLost = true;
                    print(PRINTLN, "WiFi lost during OTA update!");
                    lv_label_set_text(ui_Label90, "WiFi lost. Aborting OTA...");
                    Update.abort(); // Hủy OTA ngay lập tức
                    break;
                }

                size_t chunkSize = client->available();
                if (chunkSize)
                {
                    uint8_t buffer[512]; // Buffer tạm
                    size_t bytesToRead = (chunkSize > sizeof(buffer)) ? sizeof(buffer) : chunkSize;
                    int bytesRead = client->read(buffer, bytesToRead);
                    written += Update.write(buffer, bytesRead);

                    int percentage = (written * 100) / contentLength;
                    // print(PRINTF, "Progress: %d%%\n", percentage);
                    lv_label_set_text_fmt(ui_Label90, "Uploading new version... %d%%", percentage);
                }

                delay(1); // Cho phép các task khác chạy
            }

            if (wifiLost)
            {
                // Xử lý mất WiFi
                print(PRINTLN, "OTA update aborted due to WiFi disconnection.");
                lv_label_set_text(ui_Label90, "WiFi disconnect. Try again...");
                ota_running_flag = false;
                vTaskDelete(NULL);
                return; // Kết thúc
            }

            if (written == contentLength)
            {
                print(PRINTLN, "OTA update successful!");
                lv_label_set_text(ui_Label90, "OTA update successful!");
                write_new_ota_version(filename);
            }
            else
            {
                // print(PRINTF, "OTA update failed. Written %d / %d bytes\n", written, contentLength);
                ota_running_flag = false;
                lv_label_set_text(ui_Label90, "OTA update failed!");
            }

            if (Update.end())
            {
                if (Update.isFinished())
                {
                    print(PRINTLN, "Update completed. Rebooting...");
                    lv_label_set_text(ui_Label90, "Update completed. Rebooting...");
                    ESP.restart();
                }
                else
                {
                    print(PRINTLN, "Update not finished. Something went wrong.");
                    ota_running_flag = false;
                    lv_label_set_text(ui_Label90, "Update not finished. Something went wrong.");
                }
            }
            else
            {
                print(PRINTF, "Update failed. Error #: %d\n", Update.getError());
                ota_running_flag = false;
                lv_label_set_text_fmt(ui_Label90, "Update failed. Error #: %d", Update.getError());
            }
        }
        else
        {
            print(PRINTLN, "Not enough space to start OTA update");
            ota_running_flag = false;
            lv_label_set_text(ui_Label90, "Not enough space for OTA update.");
        }
    }
    else
    {
        print(PRINTF, "Failed to download firmware, error code: %d\n", httpCode);
        ota_running_flag = false;
        lv_label_set_text_fmt(ui_Label90, "Failed to download firmware. Error: %d", httpCode);
    }

    http.end();
    ota_running_flag = false;
    print(PRINTLN, "End OTA");
    lv_label_set_text(ui_Label90, "End OTA update.");
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