// Include our class header
#include "obstacledetector.h"

// This is required to give us access to the pinMode,
// digitalWrite, and analogWrite functions
#include <Arduino.h>

const int ObstacleDetector::NONE = 0;
const int ObstacleDetector::FRONT = 1;
const int ObstacleDetector::FRONT_LEFT = 2;
const int ObstacleDetector::FRONT_RIGHT = 3;

// Constructor implementation
ObstacleDetector::ObstacleDetector(const uint8_t pinL, const uint8_t pinR) : pinL_(pinL), pinR_(pinR)
{
	// set all the pins as inputs
	pinMode(pinL_, INPUT);
	pinMode(pinR_, INPUT);
}

// The detect implementation
int ObstacleDetector::detect()
{
	int left = digitalRead(pinL_);
	int right = digitalRead(pinR_);

	if (left && right) {
		return ObstacleDetector::FRONT;
	} else if (left) {
		return ObstacleDetector::FRONT_LEFT;
	} else if (right) {
		return ObstacleDetector::FRONT_RIGHT;
	} else {
		return ObstacleDetector::NONE;
	}
}
