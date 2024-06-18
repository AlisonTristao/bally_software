#ifndef ARRAYSENSOR_H
#define ARRAYSENSOR_H
#include <Arduino.h>

// line colors
#define BLACK 0
#define WHITE 1

class arraySensor{
private:
    // mux pins
    uint8_t sig, c0, c1, c2, c3;
    uint8_t len;
    bool lineColor;
    double lastPosition;

    // normalize array
    uint16_t *min, *max;

    // functions
    uint16_t read(uint8_t index);
    uint16_t normalize(uint16_t value, uint8_t index);
    bool calibration_ok();
    String debub();

public:
    arraySensor(uint8_t len, uint8_t sig, uint8_t c0, uint8_t c1, uint8_t c2, uint8_t c3, bool lineColor);
    virtual ~arraySensor();

    // init variables
    void init();
    bool calibrate(uint8_t n_samples, uint8_t delay_ms, uint8_t led);
    String calibrate_status();
    double read_line();
};
#endif