#include "src/config.h"
#include "src/display/oled_display.h"
#include "src/lora/lora_comm.h"
#include "src/http_client/sender.h"
#include "src/utils/utils.h"
#include <Wire.h>

void setup() {
  Serial.begin(115200);
  Wire.begin();

  initOLED();
  initLoRa();

  connectToWiFi(WIFI_SSID, WIFI_PASS);
}

void loop() {
  String packet = receiveLoRaPacket();
  if (packet != "") {
    Serial.println(packet);
    int counter;
    float t, h, p;
    int m;

    if (parsePacketData(packet, counter, t, h, p, m)) {
      displayData(counter, t, h, p, m);
      
      if (checkWiFiStatus()) {
        sendDataToServer(counter, t, h, p, m);
      } else {
        Serial.println("Sin conexión WiFi. Datos no enviados.");
        tryReconnectWiFi();
      }
    }
  }
}
