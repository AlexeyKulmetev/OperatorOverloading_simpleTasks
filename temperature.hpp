#ifndef TEMPERATURE
#define TEMPERATURE

class Temperature {
public:
	Temperature() = default;
	explicit Temperature(const double _celsius) : celsius{_celsius} {}
	Temperature(const Temperature& other) : celsius{ other.celsius } {}

	explicit operator double() const {
		return celsius * 9 / 5 + 32;  
	}

	explicit operator int() const {
		return static_cast<int>(celsius + 273.15);
	}


private:
	double celsius;
};

Temperature operator "" _C (long double x) {
	return Temperature(static_cast<double>(x));
}

#endif // !TEMPERATURE
