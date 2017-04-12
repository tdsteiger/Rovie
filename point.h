#ifndef _POINT_H_
#define _POINT_H_

class Point {
	public:
		Point(double x, double y);

		// Returns double x_
		double getX();

		// Sets x_ to speficied double val
		void setX(double val);

		// Returns double y_
		double getY();

		// Sets y_ to speficied double val
		void setY(double val);

		// Returns distance in x
		double distanceX(const Point& p);

		// Returns distance in y
		double distanceY(const Point& p);

		// Returns double distance to p
		double distance(const Point& p);

		// Returns double degree bearing to p [0,360]
		double bearing(const Point& p);

		// Returns bool True if points are the same
		bool equals(const Point& p);

	private:
		double x_;
		double y_;
};

#endif
