#include "bottom_button_service.h"

#include <M5Unified.h>

#include "../global.h"
#include "../m5helper/brightness.h"

void bottom_button_service(void *parameter) {
  for (;;) {
    M5.update();
    delay(20);

    if (M5.BtnPWR.wasClicked()) {
      print(PRINTLN, "Btn PWR");
      // print(PRINTLN,m5brightness);
      if (m5brightness == 0) {
        set_brightness(prev_m5brightness);
      } else {
        set_brightness(0);
      }
    }
  }
}
