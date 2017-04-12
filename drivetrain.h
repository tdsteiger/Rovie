#ifndef _DRIVETRAIN_H_
#define _DRIVETRAIN_H_

// include our motor code
#include "motor.h"
#include <stdint.h>

class DriveTrain {
	public:
		DriveTrain(const uint8_t pinIN1L, const uint8_t pinIN2L, const uint8_t pinENL, const uint8_t pinIN1R, const uint8_t pinIN2R, const uint8_t pinENR);

		// Drive forward at a defined speed
		// Speed is an 8bit unsigned integer. Max 255, Min 0.
		void forward(const uint8_t speed);

		// Turn left, going forward at a defined speed
		// Speed is an 8bit unsigned integer. Max 255, Min 0.
		void forwardLeft(const uint8_t speed);

		// Turn right, going forward at a defined speed
		// Speed is an 8bit unsigned integer. Max 255, Min 0.
		void forwardRight(const uint8_t speed);

		// Drive the motor backwards at a defined speed
		// Speed is an 8bit unsigned integer. Max 255, Min 0.
		void backward(const uint8_t speed);

		// Turn left, going backward at a defined speed
		// Speed is an 8bit unsigned integer. Max 255, Min 0.
		void backwardLeft(const uint8_t speed);

		// Turn right, going backward at a defined speed
		// Speed is an 8bit unsigned integer. Max 255, Min 0.
		void backwardRight(const uint8_t speed);

		// Rotate left at a defined speed
		// Speed is an 8bit unsigned integer. Max 255, Min 0.
		void rotateLeft(const uint8_t speed);

		// Rotate right at a defined speed
		// Speed is an 8bit unsigned integer. Max 255, Min 0.
		void rotateRight(const uint8_t speed);

		// Brakes the motor
		void brake();

		// Lets the motor freely spin
		void freeRun();

	private:
		Motor rightMotor;
		Motor leftMotor;
};

#endif
