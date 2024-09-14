#pragma once

typedef struct {
  char **name_of_wifi;
  int *number_of_wifi;
} ListOfWifi;

void wifi_service(void *parameter);
void connect_wifi(const char *ssid, const char *password);
void scan_wifi(void *parameter);