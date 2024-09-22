#include "gui/ui_start.h"
#include "global.h"
#include "services/rtc_service.h"
#include "services/wifi_service.h"
#include "services/bottom_button_service.h"
#include "services/ota_service.h"

SemaphoreHandle_t lvgl_mutex;

void setup()
{
  lvgl_mutex = xSemaphoreCreateMutex();

  // Check for creation errors (optional)
  if (lvgl_mutex == NULL)
  {
    Serial.println("Can not create mutex");
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

  xTaskCreatePinnedToCore(ota_update, "ota_update", 2048, NULL, 5, NULL, tskNO_AFFINITY);
  xTaskCreatePinnedToCore(ui_start, "ui_start", 4096, NULL, 5, NULL, tskNO_AFFINITY);
  xTaskCreatePinnedToCore(rtc_service, "rtc_service", 4096, NULL, 5, NULL, tskNO_AFFINITY);
  xTaskCreatePinnedToCore(bottom_button_service, "bottom_button_service", 2048, NULL, 5, NULL, tskNO_AFFINITY);
}

void loop()
{
  vTaskDelete(NULL);
}
