#ifndef BOX
#define BOX

class Box {
public:
	Box() = default;
	Box(double _width, double _height, double _depth) : width(_width), height(_height), depth(_depth) {}
	Box(const Box& other) : Box(other.width, other.height, other.depth) {}

	Box& operator += (const Box& other) {
		double newVolume = volume() + other.volume();

		return *this;
	}

	Box operator + (const Box& other) const {
		Box sum = *this;
		sum += other;
		return sum;
	}

double volume() const{
		return width * height * depth;
	}

private:
	double width;
	double height;
	double depth;
};

#endif // !BOX
