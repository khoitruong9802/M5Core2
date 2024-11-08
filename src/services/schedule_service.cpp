#include "schedule_service.h"
#include "../gui/ui.h"
#include "../utils/http.h"
void handleScheduleUI()
{
    JsonDocument doc;
    String response = http_get_data("http://192.168.1.3:3000/data");

    DeserializationError error = deserializeJson(doc, response);
    if (error) {
    Serial.println(error.c_str());
    }

    // Access the JSON array
    JsonArray jsonArray = doc.as<JsonArray>();

    // Iterate over each JSON object in the array
    for (JsonObject obj : jsonArray) {
    const char *time = obj["start_time"];
    int flow1 = obj["flows"][0];
    int flow2 = obj["flows"][1];
    int flow3 = obj["flows"][2];
    // lv_event_send(ui_Panel1, (lv_event_code_t)MY_LV_EVENT_MQTT_CONNECT_OK, NULL);
    // renderUi(time, flow1, flow2, flow3);
    }
}