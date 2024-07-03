#include <Arduino.h>
#include <pins.h>
#include <ESP32Encoder.h>

ESP32Encoder encoderA;
ESP32Encoder encoderB;

void setup(){
	// init pins
	init_pins();

	Serial.begin(921600);

	// define encoders configuration
	encoderA.attachHalfQuad(A1, A0);
	encoderB.attachHalfQuad(B1, B0);
	
	// pausa os contadores 
	encoderA.pauseCount();
	encoderB.pauseCount();

	// set the count to zero
	encoderA.setCount(0);
	encoderB.setCount(0);

	// resume the counters
	encoderA.resumeCount();
	encoderB.resumeCount();

	// clear the encoder's raw count and set the tracked count to zero
	encoderA.clearCount();
	encoderB.clearCount();
}

void loop(){
	// Loop and read the count
	Serial.println("Encoder count = " + String((int32_t)encoderA.getCount()) + " " + String((int32_t)encoderB.getCount()));
	delay(100);
}

