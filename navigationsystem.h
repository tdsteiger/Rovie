#ifndef _NAVIGATIONSYSTEM_H_
#define _NAVIGATIONSYSTEM_H_

// include our drivetrain code
#include "drivetrain.h"

// include our obstable detection code
#include "obstacledetector.h"

// include our compass code
#include "compass.h"

// include our point code
#include "point.h"

class NavigationSystem {
    public:
        NavigationSystem(ObstacleDetector& od, DriveTrain& dt);

        // Avoids obstacles, but roams freely
        void roam();

        // Returns true when point is reached, Avoids obstacles, and navigates to point
        bool navigate(const Point& p);

        // Calibrates components
        void calibrate();

        // Return double bearing
        double getBearing();

    private:
        // Calculates degrees needed to course-correct [-180,180]
        double getCorrection(const double current, const double desired);

        // Handles movement based off of correction
        void drive(const double correction);

        // Overloads correct(0)
        void correct();

        // Moves to minimize correction
        void correct(const double correction);

        // Avoids obstacle based off of detection and overloaded correction = 0 values
        void avoid(const int detection);

        // Avoids obstacle based off of detection and correction values
        void avoid(const int detection, const double correction);

        ObstacleDetector obstacleDetector;
        DriveTrain driveTrain;
        Compass compass;
        Point location;
        double currentBearing;
};

#endif
