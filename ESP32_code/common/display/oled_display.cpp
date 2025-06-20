#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <Wire.h>
#include "oled_display.h"
#include "../config.h"

Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void initOLED() {
  display.begin(OLED_I2C_ADDRESS, true);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 0);
  display.println(F("OLED Ready"));
  display.display();
}

void displayData(int counter, float temp, float hum, float pres, int moisture) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 0);
  display.printf("ID: %d\nTemp: %.1f C\nHum: %.1f %%\nPres: %.1f hPa\nSoil: %d",
                 counter, temp, hum, pres, moisture);
  display.display();
}
