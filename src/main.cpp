#include "gui/ui_start.h"
#include "global.h"
#include "services/rtc_service.h"
#include "services/wifi_service.h"
#include "services/bottom_button_service.h"
#include "services/ota_service.h"
#include <SPIFFS.h>
#include "esp_heap_caps.h"
#include "esp_psram.h"

SemaphoreHandle_t lvgl_mutex;
void printHeapInfo() {
    // Get PSRAM and SRAM information
    size_t free_psram = heap_caps_get_free_size(MALLOC_CAP_SPIRAM);
    size_t free_sram = heap_caps_get_free_size(MALLOC_CAP_INTERNAL);

    Serial.printf("Free PSRAM: %u bytes\n", free_psram);
    Serial.printf("Free SRAM: %u bytes\n", free_sram);

    // Print detailed information about the heap
    multi_heap_info_t heap_info;
    heap_caps_get_info(&heap_info, MALLOC_CAP_INTERNAL);
    Serial.printf("Total heap size: %u bytes\n", heap_info.total_free_bytes + heap_info.total_allocated_bytes);
    Serial.printf("Total allocated heap: %u bytes\n", heap_info.total_allocated_bytes);
    Serial.printf("Total free heap: %u bytes\n", heap_info.total_free_bytes);
}
void my_log_cb(const char * buf)
{
    Serial.println(buf);
}

void setup()
{
    // lv_log_register_print_cb(my_log_cb);

  lvgl_mutex = xSemaphoreCreateMutex();

  // Check for creation errors (optional)
  if (lvgl_mutex == NULL)
  {
    print(PRINTLN,"Can not create mutex");
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
  // xTaskCreatePinnedToCore(ota_checking_update, "ota_checking_update", 2048, NULL, 5, NULL, tskNO_AFFINITY);
}

void loop()
{
  printHeapInfo();
  delay(1000);
  // vTaskDelete(NULL);
}
