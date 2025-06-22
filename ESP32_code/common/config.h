#pragma once
#include "private_keys.h"

// ==================== Sensor BME280 ====================
#define BME280_I2C_ADDRESS  0x76

// ==================== Pantalla OLED ====================
#define SCREEN_WIDTH        128
#define SCREEN_HEIGHT       64
#define OLED_I2C_ADDRESS    0x3C

// ==================== Sensor de humedad del suelo ====================
#define MOISTURE_PIN        34

// ==================== Configuración LoRa ====================
#define LORA_CS_PIN         18
#define LORA_RST_PIN        14
#define LORA_IRQ_PIN        26
#define LORA_FREQ           915E6

// ==================== Comunicación WiFi y Servidor ====================
#define SERVER_URL          PRIVATE_SERVER_URL
#define WIFI_SSID           PRIVATE_WIFI_SSID
#define WIFI_PASS           PRIVATE_WIFI_PASS

// ==================== Parámetros del sistema ====================
#define TX_TIME_SLEEP       30000  // Delay entre envios (ms)
#define RX_TIME_SLEEP       5000   // Delay entre lecturas (ms)
