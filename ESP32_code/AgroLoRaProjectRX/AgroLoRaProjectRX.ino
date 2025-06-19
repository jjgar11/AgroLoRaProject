#include "src/config.h"
#include "src/display/oled_display.h"
#include "src/lora/lora_comm.h"
#include "utils/utils.h"
#include <Wire.h>

void setup() {
  Serial.begin(115200);
  Wire.begin();
  initOLED();
  initLoRa();
}

void loop() {
  String packet = receiveLoRaPacket();
  if (packet != "") {
    int counter;
    float t, h, p;
    int m;

    if (parsePacketData(packet, counter, t, h, p, m)) {
      displayData(counter, t, h, p, m);
      Serial.println(packet);
    }
  }
  delay(100);
}
