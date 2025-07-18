#include <SPI.h>
#include <LoRa.h>
#include "lora_comm.h"
#include "../config.h"

String lastPacket = "";

void initLoRa() {
  LoRa.setPins(LORA_CS_PIN, LORA_RST_PIN, LORA_IRQ_PIN);
  Serial.println("Pines LoRa configurados.");
  if (!LoRa.begin(LORA_FREQ)) {
    Serial.println("Fallo al inicializar LoRa.");
    while (true);
  }
  Serial.println("LoRa inicializado correctamente.");
}

void sendLoRaPacket(const String &data) {
  LoRa.beginPacket();
  LoRa.print(data);
  LoRa.endPacket();
  Serial.println("Paquete enviado.");
}

String receiveLoRaPacket() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String incoming = "";
    while (LoRa.available()) {
      incoming += (char)LoRa.read();
    }

    // Evitar duplicados
    if (incoming != lastPacket) {
      Serial.println("Paquete recibido.");
      lastPacket = incoming;
      return incoming;
    }
  }
  return "";
}
