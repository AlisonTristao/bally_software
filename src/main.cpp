#include <Arduino.h>
#include "pins.h"
#include "leds.h"
#include "error.h"
#include "HBridge.h"
#include "Control.h"
#include "arraySensor.h"
#include "mapeamento_pista.h"

void setup(){
    Serial.begin(115200);
}

void loop(){
    Serial.println("Hello World");
    delay(1000);
}
