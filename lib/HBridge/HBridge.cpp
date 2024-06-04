#include "HBridge.h"

void HBridge::changeDirection(movement move)
{
    // altera a rotação do motor
    mov = move;

    // define a rotação
    switch (mov)
    {
    case FORWARD:
        digitalWrite(l1, HIGH);
        digitalWrite(l2, LOW);
        break;

    case BACKWARD:
        digitalWrite(l1, LOW);
        digitalWrite(l2, HIGH);
        break;

    case STOPPED:
        digitalWrite(l1, HIGH);
        digitalWrite(l2, HIGH);
        break;

    default:
        break;
    }
}
void HBridge::applyPWM(int32_t pwm)
{
    // define a direção
    movement move = FORWARD;
    if (pwm > 0)
        move = FORWARD;
    if (pwm < 0)
        move = BACKWARD;

    // muda a direção
    if (mov != move)
        changeDirection(move);

    // aplica o pwm
    ledcWrite(channelPWM, abs(pwm));
}
void HBridge::brake()
{
    // para o motor
    changeDirection(STOPPED);
    ledcWrite(channelPWM, 4095);
}
