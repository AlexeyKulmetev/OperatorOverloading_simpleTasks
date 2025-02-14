#ifndef BOX
#define BOX

#include <cmath>

class Box {
public:
	Box() = default;
	Box(double _width, double _height, double _depth) : width(_width), height(_height), depth(_depth) {}
	Box(const Box& other) : Box(other.width, other.height, other.depth) {}

	Box& operator += (const Box& other) {
		double newVolume = volume() + other.volume();
		double scaleFactor = std::cbrt(newVolume / volume());
		width *= scaleFactor;
		height *= scaleFactor;
		depth *= scaleFactor;

		return *this;
	}

	bool operator == (const Box& other) const {
		return std::abs(volume() - other.volume()) < epsilon;
	}

	bool operator != (const Box& other) const {
		return !(*this == other);
	}

	Box operator + (const Box& other) const {
		Box sum = *this;
		sum += other;
		return sum;
	}

	double getEpsilon() {
		return epsilon;
	}

	double setEpsilon(const double& _epsilon) {
		epsilon = _epsilon;
	}

	double volume() const{
		return width * height * depth;
	}

private:
	double width;
	double height;
	double depth;
	double epsilon = 0.001;
};

#endif // !BOX
