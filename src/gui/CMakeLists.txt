SET(SOURCES screens/ui_MainScreen.c
    screens/ui_AppScreen.c
    screens/ui_SettingsScreen.c
    screens/ui_AboutScreen.c
    screens/ui_MqttScreen.c
    screens/ui_SensorsScreen.c
    screens/ui_ManualScreen.c
    screens/ui_DisplayScreen.c
    screens/ui_WifiScreen.c
    screens/ui_OtaScreen.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.cpp
    images/ui_img_background_png.c
    images/ui_img_125102533.c
    images/ui_img_wifi_icon_png.c
    images/ui_img_2012070497.c
    images/ui_img_931645554.c
    images/ui_img_app_icon_png.c
    images/ui_img_setting_icon_png.c
    images/ui_img_folder_icon_png.c
    images/ui_img_mqtt_icon_png.c
    images/ui_img_clock_item_png.c
    images/ui_img_about_icon_png.c
    images/ui_img_wifisetting_icon_png.c
    images/ui_img_bluetooth_icon_png.c
    images/ui_img_loop_png.c
    images/ui_img_display_icon_png.c
    images/ui_img_language_icon_png.c
    images/ui_img_sensor_icon_png.c
    images/ui_img_656191529.c
    images/ui_img_scheduler_icon_png.c
    images/ui_img_pump_icon_png.c
    images/ui_img_brightness_bar_icon_png.c)

add_library(ui ${SOURCES})
