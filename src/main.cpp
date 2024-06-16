//bibliotecas utilizadas
#include <Arduino.h>
#include "HBridge.h"
#include <Control.h>
#include <pins.h>
#include <erro_seguidor.h>
String config;
int state = state_wait;

Control control(1, 1, 1);
void setup()
{
  Serial.begin(115200);
}
void loop()
{
  switch (state)
  {
  case state_wait:
    digitalWrite(LED0, HIGH);
    break;

  case state_calibrating:
    /* codigo parar a calibração dos sensores */
    state = state_run;
    break;

  case state_run:
    while (analogRead (RIGHT) == 0)
    {
      int erro = calculo_erro();
    }
    state = state_finish;
    break;
  
  case state_finish:
    /* code */
    break;
  }
}
