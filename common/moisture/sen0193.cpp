#include "sen0193.h"
#include "../config.h"

void initSoilSensor() {
  pinMode(MOISTURE_PIN, INPUT);
}

int readSoilMoisture() {
  return analogRead(MOISTURE_PIN);
}
