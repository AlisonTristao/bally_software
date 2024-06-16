#include "Control.h"
#include <Arduino.h>

Control::Control(double kp, double ki, double kd)
{
    this->kp = kp;
    this->kd = kd;
    this->ki = ki;
}

void Control::setConst(double kp, double ki, double kd)
{
    this->kp = kp;
    this->kd = kd;
    this->ki = ki;
}

void Control::setVerb(bool verb)
{
    this->verb = verb;
}

String Control::printConfig()
{
    return "Constantes: \nkp = " + String(kp) + "\nki = " + String(ki) + "\nkd = " + String(kd) + "\n\n";
    // Serial.printf("Constantes: \nkp = %f\nki = %f\nkd = %f\n\n", kp, ki, kd);
}

int32_t Control::simplePID(double kp, double ki, double kd, double Erro, int32_t limit)
{
    float Ts = 0.1; // tempo de amostragem

    // anti windup
    aw = (ki - 0.1) * Ts * (limit - pid);
    k1 = (kp + ki * Ts);
    k2 = -kp;

    // salva o ultimo erro
    pid += pid + (k1 * Erro) + (k2 * ErroPassado) + aw + ((Erro - ErroPassado) / Ts) * kd; // pid com anti-windup

    // garante que o P e o D nao sature
    if (pid >= limit)
        pid = limit;
    else if (pid <= -limit)
        pid = -limit;

    if (verb)
    {
        // Serial.printf("Tempo: %.2f\t", Ts);
        // Serial.printf("P: %.2f\t I: %.2f\tD: %.2f\t", P, I, D);
        Serial.printf("PID: %d\t", pid);
        Serial.printf("Erro passado: %.2f,\t Erro: %.2f\n", Erro, Erro);
    }
    ErroPassado = Erro;
    return pid;
}
int32_t Control::simplePD(double kp, double kd, double Erro, int32_t limit)
{
    float Ts = 0.01; // tempo de amostragem

    pid = ((kp * Erro) + (Erro - ErroPassado / Ts) * kd);

    // garante que nao sature
    if (pid >= limit)
        pid = limit;
    else if (pid <= -limit)
        pid = -limit;

    if (verb)
    {
        // Serial.printf("Tempo: %.2f\t", Ts);
        // Serial.printf("P: %.2f\t I: %.2f\tD: %.2f\t", P, I, D);
        Serial.printf("PI: %d\t", pid);
        Serial.printf("Erro passado: %.2f,\t Erro: %.2f\n", Erro, Erro);
    }
    ErroPassado = Erro;
    return pid;
}
