#include "ota_service.h"

const char* serverUrl = "";


bool fileExists(const String& filename) {
    Serial.println(filename);
    // Attempt to open the file
    File file = SD.open(filename.c_str(), FILE_READ); // Convert String to const char*
    if (file) {
        file.close();  // Close the file if it exists
        return true;   // File exists
    }
    return false;      // File does not exist
}

void listFilesInDir(const char* dirname, uint8_t levels) {
  for (;;) {
    if (SD.begin(GPIO_NUM_4, SPI, 40000000)) {  // SD Card CS is on GPIO 4
      Serial.println("SD card initialized successfully.");
      break;
    }
    Serial.println("SD card initialization failed");
    delay(1000); // Wait before retrying
  }
  File root = SD.open(dirname);

  if (!root) {
    Serial.printf("Failed to open directory: %s\n", dirname);
    return;
  }

  if (!root.isDirectory()) {
    Serial.printf("%s is not a directory\n", dirname);
    root.close();
    return;
  }

  File file = root.openNextFile();
  while (file) {
    if (file.isDirectory()) {
      Serial.printf("DIR : %s\n", file.name());
      if (levels) {
        // Recursively list contents of this directory
        listFilesInDir(file.name(), levels - 1);
      }
    } else {
      Serial.printf("  FILE: %s  SIZE: %d bytes\n", file.name(), file.size());
    }
    file = root.openNextFile();
  }
  root.close();
}

// Function to check for the latest firmware file
String getLatestFirmwareFileName() 
{
    HTTPClient http;
    String latestFirmwareFileName = "";

    http.begin(String(serverUrl) + "/upload");
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
        Serial.printf("Failed to get the firmware list, error code: %d\n", httpCode);
    }

    http.end();
    return latestFirmwareFileName;
}


void ota_update(void *parameter)
{
    Serial.println("Start OTA");
    String filename = getLatestFirmwareFileName();
    Serial.printf("Start installing: %s\n", filename.c_str());
    listFilesInDir("/", 5);
//     String firmwareURL = serverUrl + String("/uploads/") + getLatestFirmwareFileName();
//     HTTPClient http;
//     http.begin(firmwareURL);
//     int httpCode = http.GET();
    
//     if (httpCode == HTTP_CODE_OK) 
//     {
//         int contentLength = http.getSize();
//         bool canBegin = Update.begin(contentLength);

//         if (canBegin) 
//         {
//             Serial.println("Begin OTA update");
//             WiFiClient* client = http.getStreamPtr();
//             size_t written = Update.writeStream(*client);

//             if (written == contentLength) 
//             {
//                 Serial.println("OTA update successful!");
//             } else 
//             {
//                 Serial.printf("OTA update failed. Written %d / %d bytes\n", written, contentLength);
//             }

//             if (Update.end()) 
//             {
//                 if (Update.isFinished()) 
//                 {
//                     Serial.println("Update completed. Rebooting...");
//                     ESP.restart();
//                 } else 
//                 {
//                     Serial.println("Update not finished. Something went wrong.");
//                 }
//             } else 
//             {
//                 Serial.printf("Update failed. Error #: %d\n", Update.getError());
//             }
//         } else 
//         {
//             Serial.println("Not enough space to start OTA update");
//         }
//     } else 
//     {
//         Serial.printf("Failed to download firmware, error code: %d\n", httpCode);
//     }

//     http.end();
//     Serial.println("End OTA");
}