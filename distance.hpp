#ifndef DISTANCE
#define DISTANCE

class Distance {
	Distance() = default;
	Distance(int _length) : length{ _length } {}
	Distance(const Distance& other) : length{ other.length } {}

	operator double() const {
		return static_cast<double>(length / 1000);
	}
	
	operator int() const {
		return length * 100;
	}

private:
	int length;
};

#endif // !DISTANCE
