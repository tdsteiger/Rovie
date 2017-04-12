#ifndef _MOTOR_H_
#define _MOTOR_H_

#include <stdint.h>

class Motor {
	public:
		Motor(const uint8_t pinIN1, const uint8_t pinIN2, const uint8_t pinEN);

		// Drive the motor forward at a defined speed
		// Speed is an 8bit unsigned integer. Max 255, Min 0.
		void forward(const uint8_t speed);

		// Drive the motor backwards at a defined speed
		// Speed is an 8bit unsigned integer. Max 255, Min 0.
		void backward(const uint8_t speed);

		// Brakes the motor
		void brake();

		// Lets the motor freely spin
		void freeRun();

	private:
		uint8_t pinIN1_;
		uint8_t pinIN2_;
		uint8_t pinEN_;
};

#endif
