#pragma once

typedef struct {
  char **name_of_wifi;
  int *number_of_wifi;
} ListOfWifi;

typedef struct {
    char username[32];
    char password[32];
} WifiCredentials;

void wifi_service(void *parameter);
void scan_wifi(void *parameter);
void init_scan_wifi_list_element();
void save_wifi_credentials(const char* username, const char* password);
void check_wifi_icon();