#include "rtc_service.h"
#include <lvgl.h>
#include "../gui/ui_custom_events.h"
#include "../global.h"
#define MAX_TIME_SERVER_CONNECT_TIMES 5

#define WIFI_SSID "Mi tom thanh long"
#define WIFI_PASSWORD "87654321"
#define NTP_TIMEZONE "JST-9"
#define NTP_SERVER1 "0.pool.ntp.org"
#define NTP_SERVER2 "1.pool.ntp.org"
#define NTP_SERVER3 "2.pool.ntp.org"

static constexpr const char *const wd[7] = {"Sun", "Mon", "Tue", "Wed", "Thr", "Fri", "Sat"};
static constexpr const char *const mon[13] = {"", "Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec"};

void update_time_from_server()
{
  /// setup RTC ( NTP auto setting )
  uint8_t connect_times = 0;
  while (WiFi.status() != WL_CONNECTED && connect_times < MAX_TIME_SERVER_CONNECT_TIMES)
  {
    print(PRINTLN,"Connect to wifi to sync time");
    delay(2000);
  }

  if (WiFi.status() == WL_CONNECTED)
  {
    configTzTime(NTP_TIMEZONE, NTP_SERVER1, NTP_SERVER2, NTP_SERVER3);
    print(PRINT,"NTP:");

    while (sntp_get_sync_status() != SNTP_SYNC_STATUS_COMPLETED)
    {
      print(PRINT,".");
      delay(1000);
    }

    print(PRINTLN,"\r\nNTP Connected.");

    time_t t = time(nullptr) + 1; // Advance one second.
    while (t > time(nullptr))
      ; /// Synchronization in seconds
    t = t - 7200;
    M5.Rtc.setDateTime(localtime(&t));
  }
}

void rtc_service(void *parameter)
{
  if (!M5.Rtc.isEnabled())
  {
    print(PRINTLN,"RTC not found.");
    vTaskDelete(NULL);
  }

  update_time_from_server();

  for (;;)
  {

    delay(1000);

    auto dt = M5.Rtc.getDateTime();
    // print(PRINTF,"RTC:%04d/%s/%02d (%s)  %02d:%02d:%02d\r\n", dt.date.year, mon[dt.date.month], dt.date.date, wd[dt.date.weekDay], dt.time.hours, dt.time.minutes, dt.time.seconds);

    char *time1 = new char[6];
    snprintf(time1, 6, "%02d:%02d", dt.time.hours, dt.time.minutes);

    char *time2 = new char[13];
    snprintf(time2, 13, "%s %s %02d", wd[dt.date.weekDay], mon[dt.date.month], dt.date.date);

    lv_event_send(ui_Label1, (lv_event_code_t)MY_LV_EVENT_RTC_UPDATE_LABEL, (void *)time1);
    lv_event_send(ui_Label2, (lv_event_code_t)MY_LV_EVENT_RTC_UPDATE_LABEL, (void *)time2);

    // /// ESP32 internal timer
    // auto t = time(nullptr);
    // {
    //   auto tm = gmtime(&t); // for UTC.
    //   print(PRINTF,"ESP32 UTC  :%04d/%02d/%02d (%s)  %02d:%02d:%02d\r\n",
    //                 tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
    //                 wd[tm->tm_wday],
    //                 tm->tm_hour, tm->tm_min, tm->tm_sec);
    // }

    // {
    //   auto tm = localtime(&t); // for local timezone.
    //   print(PRINTF,"ESP32 %s:%04d/%02d/%02d (%s)  %02d:%02d:%02d\r\n", NTP_TIMEZONE,
    //                 tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
    //                 wd[tm->tm_wday],
    //                 tm->tm_hour, tm->tm_min, tm->tm_sec);
    // }
  }
}