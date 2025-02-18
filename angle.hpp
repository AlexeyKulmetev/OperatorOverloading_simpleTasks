#ifndef ANGLE
#define ANGEL
#define _USE_MATH_DEFINES
#include <cmath>

class Angle {
public:
	Angle() = default;
	Angle(const int _angle) : angle(_angle) {}
	Angle(const Angle& other) : Angle(other.angle) {}

	operator double() {
		return static_cast<double>(angle) * M_PI / 180.0;
	}

	operator int() {
		return angle * 60;
	}

private:
	int angle;
};

Angle operator "" _deg(unsigned long long x) {
	return Angle(static_cast<int>(x));
}

#endif // !ANGLE