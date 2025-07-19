#pragma once
#include <Arduino.h>

void connectToWiFi(const char* ssid, const char* password);
void tryReconnectWiFi();
bool checkWiFiStatus();
void sendDataToServer(int counter, float t, float h, float p, int m);
String formatFloatOrNull(float val);
