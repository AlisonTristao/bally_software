#include <Arduino.h>
#include "pins.h"
#include "arraySensor.h"
#include "HBridge.h"

arraySensor sensors(8, SIG, C3, C2, C1, C0, BLACK);

void setup() {
    Serial.begin(115200);

    // pins configuration
    init_pins();
    
    // set the initial array of the mux
    sensors.set_init_arr(5);

    // sensors configuration
    sensors.init();

    // sensors calibration
    bool erro = sensors.calibrate(30, 100, LED0);

    // check if the calibration is ok
    if(erro)    ESP.restart();
    else        Serial.println("Calibração ok");

    // degub
    Serial.println(sensors.calibrate_status());
    
    // sait 1 second
    delay(1000);
}

void loop(){
    // debug
    Serial.print(sensors.debub_fast());


    // calculate the line position
    double position = sensors.read_line();
    Serial.println(position);

    delay(1000);
}
