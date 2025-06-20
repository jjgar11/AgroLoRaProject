#pragma once
#include <Arduino.h>

void initLoRa();
void sendLoRaPacket(const String& data);
String receiveLoRaPacket();
