#include "lvgl_port.h"
#include "global.h"
#include <M5Unified.h>
#include "../../m5helper/brightness.h"
#include "../../services/wifi_service.h"
#include <lvgl.h>


#define TOUCH_WAKEUP_PIN 39 // Chân INT của CST816S
#define WIFI_TIMEOUT 4000  // ms

/*Change to your screen resolution*/
static uint32_t last_touch_time = 0; // Lưu thời điểm cuối cùng có chạm
static const uint32_t sleep_timeout_1 = 10000; // Thời gian timeout (15 giây)
static const uint32_t sleep_timeout_2 = 30000; // Thời gian timeout (30 giây)
static const uint32_t modem_sleep_timeout = 20000; // Thời gian timeout (20 giây)
static bool is_modem_sleeping = false; // Trạng thái của Modem Sleep
static bool is_light_sleeping = false; // Trạng thái của light Sleep

static const uint16_t screenWidth = 320;
static const uint16_t screenHeight = 240;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * screenHeight / 10];
static bool enable_light_flag = false; 
/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  M5.Display.startWrite();
  M5.Display.setAddrWindow(area->x1, area->y1, w, h);
  M5.Display.pushPixelsDMA((uint16_t *)&color_p->full, w * h, true);
  M5.Display.endWrite();

  lv_disp_flush_ready(disp);
}

/*Read the touchpad*/
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) {
  if (!touch_enabled) {
    data->state = LV_INDEV_STATE_REL;
    return;
  }

  if (!M5.Display.touch()) {
    print(PRINTLN,"Touch not found.");
    return;
  }

  uint16_t touchX = 0, touchY = 0;

  if (!M5.Display.getTouch(&touchX, &touchY)) {
    is_touching = false;
    data->state = LV_INDEV_STATE_REL;
  } else {
    is_touching = true;
    data->state = LV_INDEV_STATE_PR;

    /*Set the coordinates*/
    data->point.x = touchX;
    data->point.y = touchY;

    // Cập nhật thời gian cuối cùng có chạm
    last_touch_time = millis();
  }
}


void disable_touch() {
  touch_enabled = false;
}

void enable_touch() {
  touch_enabled = true;
}

// void my_log(const char *buf)
// {
//   print(PRINTLN,buf);
// }

void lvgl_driver_init() {
  lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * screenHeight / 10);

  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  /*Change the following line to your display resolution*/
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  /*Initialize the (dummy) input device driver*/
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);

  /*Print to serial for debug purpose*/
  // lv_log_register_print_cb(my_log);
}

void setup_wakeup_pin() {
    pinMode(TOUCH_WAKEUP_PIN, INPUT_PULLUP); // Cấu hình chân cảm ứng INT làm đầu vào
    esp_sleep_enable_ext0_wakeup((gpio_num_t)TOUCH_WAKEUP_PIN, 0); // Wake-up khi GPIO39 LOW
}

void check_sleep() {
  if(ota_running_flag == false)
  {
    uint32_t current_time = millis();

    if (current_time - last_touch_time > sleep_timeout_2) {
      if(!is_light_sleeping)
      {
        print(PRINTLN,"Entering Light Sleep...");
        is_light_sleeping = true;
        enable_light_flag = false;
        is_modem_sleeping = false;
        set_brightness(0);
        esp_sleep_enable_ext0_wakeup((gpio_num_t)TOUCH_WAKEUP_PIN, 0);
        // Bắt đầu Light Sleep
        esp_light_sleep_start(); // Chuyển vào chế độ Light Sleep
      }
      
    }
    else {
      if (enable_light_flag == false) 
      {
        enable_light_flag = true;
        set_brightness(80);
      }
      else if(is_light_sleeping)
      {
        print(PRINTLN,"Exiting Light Sleep, Wi-Fi Reconnected...");  
        is_light_sleeping = false;
        // Khôi phục Wi-Fi sau khi Modem Sleep
        WiFi.mode(WIFI_MODE_STA); // Bật Wi-Fi trở lại
        preferences.begin("wifi-config", true);
        String wifi_username = preferences.getString("wifi_user"); // Giá trị mặc định nếu không có
        String wifi_password = preferences.getString("wifi_pass");
        preferences.end();
        WiFi.begin(wifi_username, wifi_password); // Thay bằng SSID và mật khẩu của bạn
        unsigned long startTime = millis();  // Get the current time
        while (millis() - startTime < WIFI_TIMEOUT && WiFi.status() != WL_CONNECTED) 
        {
          delay(500);
          print(PRINTLN, "connecting....");
        }
        if (WiFi.status() != WL_CONNECTED) 
        {
          WiFi.disconnect();
        }  
      }
    }
  }

}
