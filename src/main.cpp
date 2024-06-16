//bibliotecas utilizadas
#include <Arduino.h>
<<<<<<< HEAD
#include <HBridge.h>
#include <erro_seguidor.h>

//entradas e saidas da ESP
#define button1 1
#define button2 2
#define led0 35
#define led1 36
#define led2 37
#define led4 45
#define led5 46
#define sensor_fim_de_pista 17 //17 ou 8, tem que conferir
#define sensor_curva 8 //8 ou 17, tem que conferir

//definições dos estados da maquina de estados
#define state_wait 1
#define state_calibrating 2
#define state_run 3
#define state_finish 4

//variaveis globais
short state = state_wait;
=======
#include "HBridge.h"
#include <Control.h>
String config;

Control control(1, 1, 1);
>>>>>>> fff16875acb72639024cce956bc3123652a597a8
void setup()
{
  Serial.begin(115200);
}
void loop()
{
<<<<<<< HEAD
  switch (state)
  {
  case state_wait:
    digitalWrite(led0, HIGH);
    break;

  case state_calibrating:
    /* codigo parar a calibração dos sensores */
    state = state_run;
    break;

  case state_run:
    while (analogRead (sensor_fim_de_pista) == 0)
    {
      int erro = calculo_erro();
    }
    state = state_finish;
    break;
  
  case state_finish:
    /* code */
    break;
  }
=======
  config = control.printConfig();
  control.setConst(2, 2, 2);
  Serial.println(config);
  delay(1000);
>>>>>>> fff16875acb72639024cce956bc3123652a597a8
}
