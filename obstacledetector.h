#ifndef _OBSTACLEDETECTOR_H_
#define _OBSTACLEDETECTOR_H_

#include <stdint.h>

class ObstacleDetector {
	public:
		static const int NONE;
		static const int FRONT;
		static const int FRONT_LEFT;
		static const int FRONT_RIGHT;

		ObstacleDetector(const uint8_t pinL, const uint8_t pinR);

		// Detect obstacles
		// Returns int specifying what was detected
		int detect();

	private:
		uint8_t pinL_;
		uint8_t pinR_;
};

#endif
