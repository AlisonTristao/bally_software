#include <Arduino.h>
#include "pins.h"
#include "HBridge.h"

void setup()
{
  Serial.begin(115200);
  init_pins();

  HBridge leftMotor(AIN1, AIN2, CH1, PWM_A);
  HBridge rightMotor(BIN1, BIN2, CH2, PWM_B);

  leftMotor.applyPWM(1500);
  rightMotor.applyPWM(1500);
}

void loop()
{
}
