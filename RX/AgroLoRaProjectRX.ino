#include "config.h"
#include "display/oled_display.h"
#include "lora/lora_comm.h"

void setup() {
  Serial.begin(115200);
  Wire.begin();
  initOLED();
  initLoRa();
}

void loop() {
  String packet = receiveLoRaPacket();

  float t = 0, h = 0, p = 0;
  int m = 0;

  int i1 = packet.indexOf(',');
  int i2 = packet.indexOf(',', i1 + 1);
  int i3 = packet.indexOf(',', i2 + 1);

  if (i1 != -1 && i2 != -1 && i3 != -1) {
    t = packet.substring(0, i1).toFloat();
    h = packet.substring(i1 + 1, i2).toFloat();
    p = packet.substring(i2 + 1, i3).toFloat();
    m = packet.substring(i3 + 1).toInt();

    displayData(t, h, p, m);
  }

  delay(5000);
}
