#include "lora_comm.h"
#include <SPI.h>
#include <LoRa.h>
#include "../config.h"

void initLoRa() {
  LoRa.setPins(LORA_CS_PIN, LORA_RST_PIN, LORA_IRQ_PIN);
  LoRa.begin(915E6);
}

void sendLoRaPacket(String data) {
  LoRa.beginPacket();
  LoRa.print(data);
  LoRa.endPacket();
}

String receiveLoRaPacket() {
  int packetSize = LoRa.parsePacket();
  if (packetSize == 0) return "";
  String received = "";
  while (LoRa.available()) {
    received += (char) LoRa.read();
  }
  return received;
}
