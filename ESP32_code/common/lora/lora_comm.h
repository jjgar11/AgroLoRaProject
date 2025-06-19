#pragma once

void initLoRa();
void sendLoRaPacket(const String& data);
String receiveLoRaPacket();
