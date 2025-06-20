#pragma once
#include <Arduino.h>

void connectToWiFi(const char* ssid, const char* password);
void sendDataToServer(int counter, float t, float h, float p, int m);