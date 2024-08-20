#pragma once

#include <M5Unified.h>
#include <Arduino.h>
#include <WiFi.h>
#include <esp_sntp.h>
#include "../gui/ui.h"
#include "lvgl.h"

void rtc_service(void *parameter);