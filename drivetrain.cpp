// Include our class header
#include "drivetrain.h"

// Constructor implementation
DriveTrain::DriveTrain(const uint8_t pinIN1L, const uint8_t pinIN2L, const uint8_t pinENL, const uint8_t pinIN1R, const uint8_t pinIN2R, const uint8_t pinENR) : leftMotor(pinIN1L, pinIN2L, pinENL), rightMotor(pinIN1R, pinIN2R, pinENR)
{

}

// The forward implementation
void DriveTrain::forward(const uint8_t speed)
{
	leftMotor.forward(speed);
	rightMotor.forward(speed);
}

// The forwardLeft implementation
void DriveTrain::forwardLeft(const uint8_t speed)
{
	leftMotor.brake();
	rightMotor.forward(speed);
}

// The forwardRight implementation
void DriveTrain::forwardRight(const uint8_t speed)
{
	leftMotor.forward(speed);
	rightMotor.brake();
}

// The backward implementation
void DriveTrain::backward(const uint8_t speed)
{
	leftMotor.backward(speed);
	rightMotor.backward(speed);
}

// The backwardLeft implementation
void DriveTrain::backwardLeft(const uint8_t speed)
{
	leftMotor.backward(speed);
	rightMotor.brake();
}

// The backwardRight implementation
void DriveTrain::backwardRight(const uint8_t speed)
{
	leftMotor.brake();
	rightMotor.backward(speed);
}

// The rotateLeft implementation
void DriveTrain::rotateLeft(const uint8_t speed)
{
	leftMotor.backward(speed);
	rightMotor.forward(speed);
}

// The rotateRight implementation
void DriveTrain::rotateRight(const uint8_t speed)
{
	leftMotor.forward(speed);
	rightMotor.backward(speed);
}

// the brake implementation
void DriveTrain::brake()
{
	leftMotor.brake();
	rightMotor.brake();
}

// the free run implementation
void DriveTrain::freeRun()
{
	leftMotor.freeRun();
	rightMotor.freeRun();
}
