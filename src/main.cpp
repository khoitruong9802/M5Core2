#include "gui/ui_start.h"
#include "global.h"
#include "services/rtc_service.h"
#include "services/wifi_service.h"
#include "services/bottom_button_service.h"
#include "services/ota_service.h"
#include "services/mqtt_service.h"
#include <SPIFFS.h>
#include "esp_heap_caps.h"
#include "esp_psram.h"
#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
SemaphoreHandle_t lvgl_mutex;
void printHeapInfo() {
    // Get PSRAM and SRAM information
    size_t free_psram = heap_caps_get_free_size(MALLOC_CAP_SPIRAM);
    size_t free_sram = heap_caps_get_free_size(MALLOC_CAP_INTERNAL);
    Serial.println("=========================================================");
    Serial.printf("Free PSRAM: %u bytes\n", free_psram);
    Serial.printf("Free SRAM : %u bytes\n", free_sram);

    // Print detailed information about the heap
    multi_heap_info_t heap_info;
    heap_caps_get_info(&heap_info, MALLOC_CAP_INTERNAL);
    // Serial.printf("Total heap size: %u bytes\n", heap_info.total_free_bytes + heap_info.total_allocated_bytes);
    // Serial.printf("Total allocated heap: %u bytes\n", heap_info.total_allocated_bytes);
    // Serial.printf("Total free heap: %u bytes\n", heap_info.total_free_bytes);
    Serial.println("=========================================================");
}

void printDetailedHeapInfo() {
    heap_caps_print_heap_info(MALLOC_CAP_8BIT);
}


void monitorHealth() {
    // Print free heap memory
    Serial.printf("Free heap memory: %u bytes\n", ESP.getFreeHeap());

    // Print heap information
    printHeapInfo();

    // Print detailed heap information
    // printDetailedHeapInfo();
}

void my_log_cb(const char * buf)
{
    Serial.println(buf);
}

void setup()
{
    touch_enabled = true;
    WiFi.begin("kien", "11111111");
    // WiFi.begin("BiBo 2", "260NTB33");
    // WiFi.begin("RD-SEAI_2.4G", "");
    // lv_log_register_print_cb(my_log_cb);

    lvgl_mutex = xSemaphoreCreateMutex();

    // Check for creation errors (optional)
    if (lvgl_mutex == NULL)
    {
    print(PRINTLN,"Can not create mutex");
    }
    bool psramEnabled = psramFound();
    if (psramEnabled) {
        Serial.println("PSRAM is enabled.");
        Serial.printf("Free PSRAM: %u bytes\n", ESP.getFreePsram());
    } else {
        Serial.println("PSRAM is not enabled.");
    }
    m5::M5Unified::config_t cfg = M5.config();

    cfg.serial_baudrate = 115200; // default=115200. if "Serial" is not needed, set it to 0.
    cfg.clear_display = true;     // default=true. clear the screen when begin.
    cfg.output_power = true;      // default=true. use external port 5V output.
    cfg.internal_imu = true;      // default=true. use internal IMU.
    cfg.internal_rtc = true;      // default=true. use internal RTC.
    cfg.internal_spk = false;     // default=true. use internal speaker.
    cfg.internal_mic = false;     // default=true. use internal microphone.
    cfg.external_imu = true;      // default=false. use Unit Accel & Gyro.
    cfg.external_rtc = false;     // default=false. use Unit RTC.
    cfg.led_brightness = 64;      // default= 0. system LED brightness (0=off / 255=max) (※ not NeoPixel)
    M5.begin(cfg);
    M5.Display.setRotation(1);

    xTaskCreatePinnedToCore(ui_start, "ui_start", 4096, NULL, 5, NULL, tskNO_AFFINITY);
    xTaskCreatePinnedToCore(rtc_service, "rtc_service", 4096, NULL, 5, NULL, tskNO_AFFINITY);
    xTaskCreatePinnedToCore(bottom_button_service, "bottom_button_service", 2048, NULL, 5, NULL, tskNO_AFFINITY);
    xTaskCreatePinnedToCore(mqtt_init, "mqtt_init", 2048, NULL, 5, NULL, tskNO_AFFINITY);
}

void loop()
{
  monitorHealth();
//   Serial.println("======================================================================");
//   Serial.println(touch_enabled);
//   Serial.println(currentPage);
//   Serial.println("======================================================================");
    delay(1000);
//   vTaskDelete(NULL);
}
