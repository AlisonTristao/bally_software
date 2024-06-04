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

void Control::printConfig()
{
    Serial.printf("Constantes: \nkp = %f\nki = %f\nkd = %f\n\n", kp, ki, kd);
}

int32_t Control::simplePID(double kp, double ki, double kd, double Erro, int32_t limit)
{
    float Ts = 0.01; // tempo de amostragem

    aw = (ki - 0.1) * Ts * (limit - pid);
    k1 = (kp + ki * Ts);
    k2 = -kp;
    // proporcional

    // integral
    // Ie += (Erro * Ts);

    // derivativa
    // conferir se não vale mais a pena usar so a saida (y) no D

    // garante que a integral nao sature
    /* if (Ie >= limit / 2)
        Ie = limit / 2;
    else if (Ie <= -limit / 2)
        Ie = -limit / 2; */

    // salva o ultimo erro
    pid += pid + (k1 * Erro) + (k2 * ErroPassado) + aw + ((Erro - ErroPassado) / Ts) * kd; // com anti-windup
    // soma tudo
    // pid = ((kp * Erro) + (Ie * ki) + (Erro - ErroPassado / Ts) * kd);

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
int32_t Control::simplePD(double kp, double kd, double Erro, int32_t limit)
{
    float Ts = 0.01; // tempo de amostragem

    // proporcional

    // integral
    // Ie += (Erro * Ts);

    // derivativa
    // conferir se não vale mais a pena usar so a saida (y) no D

    // garante que a integral nao sature
    /* if (Ie >= limit / 2)
        Ie = limit / 2;
    else if (Ie <= -limit / 2)
        Ie = -limit / 2; */

    // salva o ultimo erro
    // pid += pid + ((kp + ki * Ts) * Erro + (-kp) * ErroPassado) + (ki - 0.1) * Ts * (limit - pid) + (Erro - ErroPassado / Ts) * kd; // com anti-windup
    // soma tudo
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
