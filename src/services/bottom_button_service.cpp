#include "bottom_button_service.h"

#include <M5Unified.h>

#include "../global.h"
#include "../m5helper/brightness.h"

void bottom_button_service(void *parameter) {
  for (;;) {
    M5.update();
    vTaskDelay(pdMS_TO_TICKS(1000));

    if (M5.BtnPWR.wasClicked()) {
      print(PRINTLN, "Btn PWR");
     Serial.println(m5brightness);
      if (m5brightness == 0) {
        set_brightness(prev_m5brightness);
        touch_enabled = true;
      } else {
        set_brightness(0);
        touch_enabled = false;
      }
    }
  }
}
