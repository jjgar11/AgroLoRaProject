#include "config.h"
#include "sensors/bme280_sensor.h"
#include "moisture/sen0193.h"
#include "display/oled_display.h"
#include "lora/lora_comm.h"
#include <esp_sleep.h>

RTC_DATA_ATTR int txCounter = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  initBME280();
  initSoilSensor();
  initOLED();
  initLoRa();

  float t = getTemperature();
  float h = getHumidity();
  float p = getPressure();
  int m = readSoilMoisture();

  txCounter++;

  char packet[64];
  snprintf(packet, sizeof(packet), "%d,%.2f,%.2f,%.2f,%d", txCounter, t, h, p, m);

  sendLoRaPacket(packet);

  displayData(txCounter, t, h, p, m);
  Serial.println(packet);

  // Configurar tiempo de deep sleep (en microsegundos)
  esp_sleep_enable_timer_wakeup(TIME_SLEEP * 1000);
  esp_deep_sleep_start();
}

void loop() {
}
