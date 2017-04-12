// include our drivetrain code
#include "drivetrain.h"

// include our obstable detection code
#include "obstacledetector.h"

// include our navigation code
#include "navigationsystem.h"

// The Right Motors Enable Pin
// Labelled on the motor driver as ENA
// Be carful of PWM Timers
const int motorRENPin = 10;

// The Right Motors IN1 Pin
// Labelled on the motor driver as IN1
const int motorRIN1Pin = 9;

// The Right Motors IN2 Pin
// Labelled on the motor driver as IN2
const int motorRIN2Pin = 8;

// The Left Motors Enable Pin
// Labelled on the motor driver as ENB
// Be carful of PWM Timers
const int motorLENPin = 5;

// The Left Motors IN1 Pin
// Labelled on the motor driver as IN3
const int motorLIN1Pin = 7;

// The Left Motors IN2 Pin
// Labelled on the motor driver as IN4
const int motorLIN2Pin = 6;

// left IR detector sensor to digital pin 2
const int Left_IRDetector_Pin = 2;

// right IR detector sensor to digital pin 3
const int Right_IRDetector_Pin = 3;

DriveTrain driveTrain(motorRIN1Pin, motorRIN2Pin, motorRENPin, motorLIN1Pin, motorLIN2Pin, motorLENPin);

ObstacleDetector obstacleDetector(Left_IRDetector_Pin, Right_IRDetector_Pin);

NavigationSystem navigationSystem(obstacleDetector, driveTrain);

void setup()
{
	//wait for compass to initialize
	delay(56);
	navigationSystem.calibrate();
}

void loop()
{
	navigationSystem.roam();
}
