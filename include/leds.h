#ifndef LEDS_H
#define LEDS_H
#include <Arduino.h>
#include "pins.h"

// default function to set the leds
void setLeds(byte error){
    setLeds(error, 6, (uint8_t[]){LED0, LED1, LED2, LED3, LED4, LED5});
}

// function to set the leds based on the error code
void setLeds(byte error, uint8_t len, uint8_t* ledPins) {
    for (int i = 0; i < len; i++) {
        // define the state of the led based on the bit of the error code
        digitalWrite(ledPins[i], (error >> i) & 0x01); 
    }
}

#endif