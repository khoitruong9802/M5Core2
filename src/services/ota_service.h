#pragma once
#include "global.h"
#include "../gui/ui.h"

#define ALERT_SCREEN_ON 1
#define ALERT_SCREEN_OFF 0

String getLatestFirmwareFileName(const char* Url);
void ota_update(void *parameter);
void ota_checking_update(void *paramter);

 