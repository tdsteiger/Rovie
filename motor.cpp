// Include our class header
#include "motor.h"

// This is required to give us access to the pinMode,
// digitalWrite, and analogWrite functions
#include <Arduino.h>

// Constructor implementation
Motor::Motor(const uint8_t pinIN1, const uint8_t pinIN2, const uint8_t pinEN) : pinIN1_(pinIN1), pinIN2_(pinIN2), pinEN_(pinEN)
{
	// set all the pins as outputs
	pinMode(pinIN1_, OUTPUT);
	pinMode(pinIN2_, OUTPUT);
	pinMode(pinEN_, OUTPUT);

	// disable the motor
	digitalWrite(pinEN_, LOW);
}

// The forward implementation
void Motor::forward(const uint8_t speed)
{
	digitalWrite(pinIN1_, LOW);
	digitalWrite(pinIN2_, HIGH);

	// use the enable line with PWM to control the speed
	analogWrite(pinEN_, speed);
}

// The backward implementation
void Motor::backward(const uint8_t speed)
{
	digitalWrite(pinIN1_, HIGH);
	digitalWrite(pinIN2_, LOW);

	// use the enable line with PWM to control the speed
	analogWrite(pinEN_, speed);
}

// the brake implementation
void Motor::brake()
{
	digitalWrite(pinIN1_, LOW);
	digitalWrite(pinIN2_, LOW);
	digitalWrite(pinEN_, HIGH);
}

// the free run implementation
void Motor::freeRun()
{
	digitalWrite(pinEN_, LOW);
}
