#ifndef WHEELS_H
#define WHEELS_H
#include <Arduino.h>

// sentido da rotação das todas
enum movement
{
    FORWARD,
    BACKWARD,
    STOPPED
};

// roda objeto
class HBridge
{
public:
    HBridge(uint8_t l1, uint8_t l2, uint8_t channelPWM);
    void changeDirection(movement mov);
    void applyPWM(int32_t pwm);
    void brake();

    movement mov;
    uint8_t l1;
    uint8_t l2;
    uint8_t channelPWM;
};

// define a rotação da roda

#endif