#include <Arduino.h>

void setup() {
    Serial.begin(921600);

    // random seed
    randomSeed(analogRead(0));
}

void loop() {
    // print a random number
    uint32_t now = micros();
    Serial.print("tempo: ");
    Serial.println(micros() - now);
    delay(500);
}