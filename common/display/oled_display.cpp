#include "oled_display.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <Wire.h>
#include "../config.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SH1106 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void initOLED() {
  display.begin(SH1106_SWITCHCAPVCC, OLED_I2C_ADDRESS);
  display.clearDisplay();
  display.display();
}

void displayData(int counter, float temp, float hum, float pres, int moisture) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.printf("ID: %d\nTemp: %.1f C\nHum: %.1f %%\nPres: %.1f hPa\nSoil: %d",
                 counter, temp, hum, pres, moisture);
  display.display();
}
