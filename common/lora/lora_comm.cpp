#include "lora_comm.h"
#include <SPI.h>
#include <LoRa.h>
#include "../config.h"

void initLoRa() {
  LoRa.setPins(LORA_CS_PIN, LORA_RST_PIN, LORA_IRQ_PIN);
  if (!LoRa.begin(LORA_FREQ)) {
    Serial.println("Fallo al inicializar LoRa.");
    while (true);
  }
  Serial.println("LoRa inicializado correctamente.");
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
