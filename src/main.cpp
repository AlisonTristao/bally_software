#include <Arduino.h>
#include "HBridge.h"
#include <Control.h>
String config;

Control control(1, 1, 1);
void setup()
{
  Serial.begin(115200);
}

void loop()
{
  config = control.printConfig();
  control.setConst(2, 2, 2);
  Serial.println(config);
  delay(1000);
}
