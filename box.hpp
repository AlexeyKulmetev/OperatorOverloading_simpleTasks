#ifndef BOX
#define BOX

#include <cmath>
#include <stdexcept>
#include <iostream>

class Box {
public:
	Box() = default;
	Box(const double _width, const double _height, const double _depth) : width(_width), height(_height), depth(_depth) {}
	Box(const Box& other) : Box(other.width, other.height, other.depth) {}

	Box& operator += (const Box& other) {
		if (volume() == 0) {
			*this = other;
			return *this;
		}
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

	double getEpsilon() const {
		return epsilon;
	}

	void setEpsilon(const double& _epsilon) {
		if (_epsilon < 0) {
			throw std::invalid_argument("Epsilon must be non-negative");
		}
		epsilon = _epsilon;
	}

	double volume() const{
		return width * height * depth;
	}

	friend std::ostream& operator << (std::ostream& out, const Box& box);

private:
	double width;
	double height;
	double depth;
	double epsilon = 0.001;
};

std::ostream& operator << (std::ostream& out, const Box& box) {
	out << "Box(width: " << box.width << ", height: " << box.height << ", depth: " << box.depth << ")";
	return out;
}

#endif // !BOX
