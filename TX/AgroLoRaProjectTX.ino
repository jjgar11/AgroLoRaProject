#include "config.h"
#include "sensors/bme280_sensor.h"
#include "moisture/sen0193.h"
#include "display/oled_display.h"
#include "lora/lora_comm.h"

void setup() {
  Serial.begin(115200);
  Wire.begin();

  initBME280();
  initSoilSensor();
  initOLED();
  initLoRa();
}

void loop() {
  float t = getTemperature();
  float h = getHumidity();
  float p = getPressure();
  int m = readSoilMoisture();

  String packet = String(millis()) + "," + String(t) + "," + String(h) + "," + String(p) + "," + String(m);
  sendLoRaPacket(packet);

  displayData(txCounter, t, h, p, m);
  Serial.println(packet);

  delay(TIME_SLEEP);
}
