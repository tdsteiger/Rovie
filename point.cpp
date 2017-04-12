// Include our class header
#include "point.h"
#include <math.h>

#define PI 3.14159265

// Constructor implementation
Point::Point(double x, double y) : x_(x), y_(y)
{

}

// The getX implementation
double Point::getX()
{
	return x_;
}

// The setX implementation
void Point::setX(double val)
{
	x_ = val;
}

// The getY implementation
double Point::getY()
{
	return y_;
}

// The setY implementation
void Point::setY(double val)
{
	y_ = val;
}

// The distanceX implementation
double Point::distanceX(const Point& p)
{
	return p.x_ - x_;
}

// The distanceY implementation
double Point::distanceY(const Point& p)
{
	return p.y_ - y_;
}

// The distance implementation
double Point::distance(const Point& p)
{
	double dx = distanceX(p);
	double dy = distanceY(p);
	return sqrt(dx * dx + dy * dy);
}

// The bearing implementation
double Point::bearing(const Point& p)
{
	if (equals(p)) {
		return 0;
	}

	double dx = p.x_ - x_;
	double dy = p.y_ - y_;
	return (atan2(dy, dx) + PI) * 180 / PI; //may need to move reference direction from x-axis to y-axis for true bearing
}

// The equals implementation
bool Point::equals(const Point& p)
{
	return p.x_ == x_ && p.y_ == y_;
}
