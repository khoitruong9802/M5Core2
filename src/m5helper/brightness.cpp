#include "brightness.h"
#include <M5Unified.h>

uint8_t m5brightness = 64;
uint8_t prev_m5brightness = 64;

void set_brightness(uint8_t brightness) {
  prev_m5brightness = m5brightness;
  m5brightness = brightness;
  M5.Lcd.setBrightness(brightness);
}