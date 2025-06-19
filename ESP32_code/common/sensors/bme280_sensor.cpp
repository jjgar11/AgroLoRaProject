#include "bme280_sensor.h"
#include <Adafruit_BME280.h>
#include <Wire.h>
#include "../config.h"

Adafruit_BME280 bme;

void initBME280() {
  bme.begin(BME280_I2C_ADDRESS);
}

float getTemperature() {
  return bme.readTemperature();
}

float getHumidity() {
  return bme.readHumidity();
}

float getPressure() {
  return bme.readPressure();
}
