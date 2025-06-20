#include <WiFi.h>
#include <HTTPClient.h>
#include "sender.h"
#include "../config.h"

void connectToWiFi(const char* ssid, const char* password) {
  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado");
}

void sendDataToServer(int counter, float t, float h, float p, int m) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(SERVER_URL);
    http.addHeader("Content-Type", "application/json");

    String jsonPayload = String("{\"id\":") + counter +
                     ",\"ts\":" + millis() +
                     ",\"t\":" + t +
                     ",\"h\":" + h +
                     ",\"p\":" + p +
                     ",\"m\":" + m + "}";

    int responseCode = http.POST(jsonPayload);

    if (responseCode > 0) {
      Serial.printf("POST enviado. Código: %d\n", responseCode);
      Serial.println(http.getString());
    } else {
      Serial.printf("Error al enviar POST: %d\n", responseCode);
    }

    http.end();
  } else {
    Serial.println("WiFi desconectado");
  }
}
