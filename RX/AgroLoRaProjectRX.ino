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
    unsigned long ts;
    float t, h, p;
    int m;

    if (parsePacketData(packet, ts, t, h, p, m)) {
      displayData(ts, t, h, p, m);
      Serial.println(packet);
    }
  }
  delay(100);
}
