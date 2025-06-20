#pragma once

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
#define SERVER_URL          "http://<TU_IP_LOCAL>:5000/data"
#define WIFI_SSID           "TU_SSID"
#define WIFI_PASS           "TU_PASSWORD"

// ==================== Parámetros del sistema ====================
#define TIME_SLEEP          5000  // Delay entre lecturas (ms)
