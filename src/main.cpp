#include <M5Unified.h>
#include <lvgl.h>

#include <gui/ui_start.h>

#include <services/rtc_service.h>
#include <services/wifi_service.h>
#include <services/bottom_button_service.h>

void ui_handler(void *parameter);

void setup()
{
  m5::M5Unified::config_t cfg = M5.config();

  cfg.serial_baudrate = 115200;   // default=115200. if "Serial" is not needed, set it to 0.
  cfg.clear_display = true;  // default=true. clear the screen when begin.
  cfg.output_power  = true;  // default=true. use external port 5V output.
  cfg.internal_imu  = true;  // default=true. use internal IMU.
  cfg.internal_rtc  = true;  // default=true. use internal RTC.
  cfg.internal_spk  = false;  // default=true. use internal speaker.
  cfg.internal_mic  = false;  // default=true. use internal microphone.
  cfg.external_imu  = true;  // default=false. use Unit Accel & Gyro.
  cfg.external_rtc  = false;  // default=false. use Unit RTC.
  cfg.led_brightness = 64;   // default= 0. system LED brightness (0=off / 255=max) (※ not NeoPixel)
  M5.begin(cfg);

  // M5.Display.begin();
  M5.Display.setRotation(1);
  
  ui_start();

  xTaskCreate(ui_handler, "ui_handler", 4096, NULL, 1, NULL);
  xTaskCreate(rtc_service, "rtc_service", 4096, NULL, 1, NULL);
  xTaskCreate(wifi_service, "wifi_service", 4096, NULL, 1, NULL);
  // xTaskCreate(scan_wifi, "scan_wifi", 4096, NULL, 1, NULL);
  xTaskCreate(bottom_button_service, "bottom_button_service", 2048, NULL, 1, NULL);

  // xTaskCreatePinnedToCore(rtc_service, "rtc_service", 4096, NULL, 1, NULL, 1);
  // xTaskCreatePinnedToCore(wifi_service, "wifi_service", 4096, NULL, 1, NULL, 1);
  // xTaskCreatePinnedToCore(mqtt_service, "mqtt_service", 4096, NULL, 1, NULL, 1);

}
void loop()
{
}

void ui_handler(void *parameter)
{
  for (;;)
  {
    lv_timer_handler();
    delay(5);
  }
}
