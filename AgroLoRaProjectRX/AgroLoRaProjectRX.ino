#include "config.h"
#include "display/oled_display.h"
#include "lora/lora_comm.h"
#include "utils.h"

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
