#include "ui_start.h"

#include <lvgl.h>

#include "../global.h"
#include "custom_widget.h"
#include "porting/lvgl_port.h"
#include "services/wifi_service.h"
#include "ui.h"

void custom_widget_init() {
  list_wifi_widget_init();
  enter_password_widget_init();
  init_scan_wifi_list_element();
}

int count = 0;
void ui_start(void *parameter) {
  lv_init();
  lvgl_driver_init();
  ui_init();
  custom_widget_init();

  for (;;) {
    if (count == 100) {
      // print(PRINTF, "ui handler run on core: %d\n", xPortGetCoreID());
      count = 0;
    }
    count++;
    if (xSemaphoreTake(lvgl_mutex, pdMS_TO_TICKS(10)) == pdTRUE) {
      // Critical section (access shared resource here)
      lv_timer_handler();

      // Release the mutex after critical section
      xSemaphoreGive(lvgl_mutex);
    } else {
      print(PRINTLN, "ui handler can not require semaphore");
    }
    vTaskDelay(pdMS_TO_TICKS(10));

    // lv_timer_handler();
    // delay(5);
  }
}