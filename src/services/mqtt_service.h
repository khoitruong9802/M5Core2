#pragma once

#include <WiFi.h>
#include <PubSubClient.h>

extern PubSubClient client;
void mqtt_service(void *parameter);