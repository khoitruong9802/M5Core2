#include "bottom_button_service.h"
#include <M5Unified.h>
#include "../gui/ui_custom_events.h"
#include "../m5helper/brightness.h"

void bottom_button_service(void *parameter)
{
  for (;;)
  {
    M5.update();
    delay(20);

    if (M5.BtnPWR.wasClicked())
    {
      Serial.println("Btn PWR");
      // Serial.println(m5brightness);
      if (m5brightness == 0) {
        set_brightness(prev_m5brightness);
      } else {
        set_brightness(0);
      }
    }
    else if (M5.BtnB.wasClicked())
    {
      Serial.println("Btn B");
      lv_event_send(ui_MainScreen, (lv_event_code_t)MY_LV_EVENT_CHANGE_SCREEN, NULL); 
    }
    else if (M5.BtnC.wasClicked())
    {
      Serial.println("Btn C");
      lv_event_send(ui_MainScreen, (lv_event_code_t)MY_LV_EVENT_BACK_SCREEN, NULL); 
    }
  }
}
