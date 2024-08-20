#include <M5Unified.h>
#include <lvgl.h>

#include "gui/ui_start.h"
#include "global.h"
#include "services/rtc_service.h"
#include "services/wifi_service.h"
#include "services/bottom_button_service.h"

SemaphoreHandle_t my_mutex;
void ui_handler(void *parameter);

void setup()
{
  my_mutex = xSemaphoreCreateMutex();

  // Check for creation errors (optional)
  if (my_mutex == NULL)
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

  ui_start();

  xTaskCreatePinnedToCore(ui_handler, "ui_handler", 4096, NULL, 2, NULL, tskNO_AFFINITY);
  xTaskCreatePinnedToCore(rtc_service, "rtc_service", 4096, NULL, 2, NULL, tskNO_AFFINITY);
  xTaskCreatePinnedToCore(bottom_button_service, "bottom_button_service", 2048, NULL, 2, NULL, tskNO_AFFINITY);

  // xTaskCreate(wifi_service, "wifi_service", 4096, NULL, 1, NULL);
  // xTaskCreate(scan_wifi, "scan_wifi", 4096, NULL, 1, NULL);
}

void loop()
{
}

int count = 0;
void ui_handler(void *parameter)
{
  for (;;)
  {
    if (count == 100) {
      Serial.printf("ui handler run on core: %d\n", xPortGetCoreID());
      count = 0;
    }
    count++; 
    if (xSemaphoreTake(my_mutex, 0) == pdTRUE)
    {
      // Critical section (access shared resource here)
      lv_timer_handler();

      // Release the mutex after critical section
      xSemaphoreGive(my_mutex);
    } else {
      Serial.println("ui handler can not require semaphore");
    }
    delay(10);

    // lv_timer_handler();
    // delay(5);

  }
}
