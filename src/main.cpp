#include <Arduino.h>
#include "pins.h"

void setup() {
  init_pins();
  Serial.begin(115200);

  tone(BZR, 2000, 1000);
}

void loop() {
  Serial.println("Serial monitor is working!");
  delay(1000);
}
