// Include our class header
#include "navigationsystem.h"
#include <math.h>

// the speed used to drive forward
// 0 to 255
const int driveSpeed = 255;

// the speed used to turn
// 0 to 255
const int turnSpeed = 200;

// the amount of tolerance in bearing degrees
const double bearingTolerance = 1.5;

// the amount of tolerance in distance
const double distanceTolerance = 1.5;

// Constructor implementation
NavigationSystem::NavigationSystem(ObstacleDetector& od, DriveTrain& dt) : obstacleDetector(od), driveTrain(dt), compass(), location(Point(0.,0.)), currentBearing(0)
{

}

// The roam implementation
void NavigationSystem::roam()
{
	drive(0);
}

// The navigate implementation
bool NavigationSystem::navigate(const Point& p)
{
	if (location.distance(p) < distanceTolerance) {
		return true;
	} else {
		compass.readBearingDeg(&currentBearing);
		drive(getCorrection(currentBearing, location.bearing(p)));
		return false;
	}
}

// The calibrate implementation
void NavigationSystem::calibrate()
{
	compass.begin();
}

// The getBearing implementation
double NavigationSystem::getBearing()
{
	compass.readBearingDeg(&currentBearing);
	return currentBearing;
}

// The getCorrection implementation
double NavigationSystem::getCorrection(const double current, const double desired)
{
	double delta = current - desired;
	double correction = fmod(fabs(delta), 360.);
	
	if (correction > 180) {
		correction = 360. - correction;
	}

	int sign = (delta >= 0 && delta <= 180) || (delta <= -180 && delta >= -360) ? 1 : -1;
	return sign * correction;
}

// The drive implementation
void NavigationSystem::drive(const double correction)
{
	int detection = obstacleDetector.detect();

	if (detection == ObstacleDetector::NONE) {
		correct(correction);
	} else {
		avoid(detection, correction);
	}
}

// The correct implementation
void NavigationSystem::correct()
{
	correct(0);
}

// The correct implementation
void NavigationSystem::correct(const double correction)
{
	double absolute = fabs(correction);

	if (absolute < bearingTolerance) {
		driveTrain.forward(driveSpeed);
	} else if (correction < 0) {
		driveTrain.forwardLeft(driveSpeed);
	} else {
		driveTrain.forwardRight(driveSpeed);
	}
}

// The avoid implementation
void NavigationSystem::avoid(const int detection)
{
	avoid(detection, 0);
}

// The avoid implementation
void NavigationSystem::avoid(const int detection, const double correction)
{
	double absolute = fabs(correction);

	if(detection == ObstacleDetector::FRONT) {
		if (absolute < bearingTolerance) {
			driveTrain.backward(driveSpeed);
		} else if (correction < 0) {
			driveTrain.backwardLeft(driveSpeed);
		} else {
			driveTrain.backwardRight(driveSpeed);
		}
	} else if (detection == ObstacleDetector::FRONT_LEFT || detection == ObstacleDetector::FRONT_RIGHT) {
		if (absolute < bearingTolerance) {
			driveTrain.rotateRight(turnSpeed);
		} else if (correction < 0) {
			driveTrain.rotateLeft(turnSpeed);
		} else {
			driveTrain.rotateRight(turnSpeed);
		}
	} else {
		correct(correction);
	}
}
