#include <Arduino.h>
#include <pins.h>
#include <HBridge.h>
#include <Encoder.h>

// encoders
Encoder encoderA;
Encoder encoderB;

// motors
HBridge motorA(AIN1, AIN2, CH1, PWM_A);
HBridge motorB(BIN1, BIN2, CH2, PWM_B);

void setup(){
	// init serial
	Serial.begin(921600);

	// init pins
	init_pins();

	// init motors
	motorA.init();
	motorB.init();
	
	// alocates interrupt on second core
	Encoder::isrServiceCpuCore = 0;

	// define encoders configuration
	encoderA.attachHalfQuad(A1, A0);
	encoderB.attachHalfQuad(B1, B0);

	// clear the encoder's raw count and set the tracked count to zero
	encoderA.clearCount();
	encoderB.clearCount();
}

void loop(){
	// set the pwm
	motorA.applyPWM(1000);
	motorB.applyPWM(1000);

	// Loop and read the count
	Serial.println("Encoder speed = " + String((double)encoderA.getSpeed()) + " " + String((double)encoderB.getSpeed()));
	delay(100);
}

