#include <Arduino.h>
#include "arraySensor.h"
#include <pins.h>

// obj sensor
arraySensor sensor(8, SIG, C0, C1, C2, C3, WHITE);

void setup(){
	// init serial
	Serial.begin(921600);

	// init pins
	init_pins();

	// set init array senso0r
	sensor.set_init_arr(4);

	// init sensor
	sensor.init();

	// calibrate sensor
	sensor.calibrate(30, 100, LED0);

	// wait 3 seconds
	Serial.println(sensor.calibrate_status());

	delay(3000);
}

void loop(){
	// debug
	Serial.print(sensor.debub());
	Serial.print(" ");
	Serial.println(sensor.read_line());
}

