#ifndef DISTANCE
#define DISTANCE

class Distance {
public:
	Distance() = default;
	Distance(const int _length) : length{ _length } {}
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

Distance operator "" _m(unsigned long long x) {
	return Distance(static_cast<int>(x));
}

#endif // !DISTANCE
