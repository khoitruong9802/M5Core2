#pragma once

typedef struct {
  char **name_of_wifi;
  int *number_of_wifi;
} ListOfWifi;

typedef struct {
  const char *username;
  const char *password;
} WifiCredentials;

void wifi_service(void *parameter);
void scan_wifi(void *parameter);
void init_scan_wifi_list_element();