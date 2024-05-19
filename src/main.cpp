#include <Arduino.h>

void setup() {
  Seial.begin(115200);
}

void loop() {
  Serial.println("Funcionando na esp32-S3?...");
  delay(1000);
}