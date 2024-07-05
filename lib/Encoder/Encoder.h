#pragma once
#include <driver/gpio.h>
#include <driver/pcnt.h>
#ifndef ARDUINO
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/portable.h>
#include <freertos/semphr.h>
#endif

#define MAX_ESP32_ENCODERS PCNT_UNIT_MAX
#define 	_INT16_MAX 32766
#define  	_INT16_MIN -32766
#define ISR_CORE_USE_DEFAULT (0xffffffff)

class Encoder;

typedef void (*enc_isr_cb_t)(void*);

class Encoder {
public:
	/**
	 * @brief Construct a new Encoder object
	 *
	 * @param always_interrupt set to true to enable interrupt on every encoder pulse, otherwise false
	 * @param enc_isr_cb callback executed on every encoder ISR, gets a pointer to
	 * 	the Encoder instance as an argument, no effect if always_interrupt is
	 * 	false
	 */
	Encoder(int aPintNumber, int bPinNumber);
	~Encoder(); 
	
	// congifure the encoder
	void init();
	void detach();
	bool isAttached(){return attached;}
	[[deprecated("Replaced by detach")]] void detatch();

	// set/get data
	double getSpeed();
	int64_t getCount();
	int64_t clearCount();
	int64_t pauseCount();
	int64_t resumeCount();
	void setCount(int64_t value);
	void setFilter(uint16_t value);
	volatile int64_t count = 0;

	// set/get isr callback	
	static Encoder *encoders[MAX_ESP32_ENCODERS];
	static uint32_t isrServiceCpuCore;

	// set/get isr callback
	bool always_interrupt;

	// counter configuration
	pcnt_config_t r_enc_config;
	enc_isr_cb_t _enc_isr_cb = nullptr;
	void* _enc_isr_cb_data = nullptr;
private:
	// configure encoder
	void attach(int aPintNumber, int bPinNumber);

	// pins configuration
	gpio_num_t aPinNumber;
	gpio_num_t bPinNumber;

	// counter 
	int64_t getCountRaw();
	pcnt_unit_t unit;
	int countsMode = 2;

	// variables to control the encoder
	bool attached;
	bool direction;
	bool working;
	int64_t last_time = 0, resolution = 70;
	static bool attachedInterrupt;
};

//Added by Sloeber
#pragma once
