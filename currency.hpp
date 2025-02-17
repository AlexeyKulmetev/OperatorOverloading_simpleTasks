#ifndef CURRENCY
#define CURRENCY

const double EURO_RATE = 0.85;
const int RUBLE_RATE = 75;

class Currency {
public:
	Currency() = default;
	Currency(const double _dollars) : dollars(_dollars) {}
	Currency(const Currency& other) = default;

	operator double() const {
		return dollars * EURO_RATE;
	}

	operator int() const {
		return dollars * RUBLE_RATE;
	}

private:
	double dollars;
	static constexpr double EURO_RATE = 0.85;
	static constexpr int RUBLE_RATE = 75;
};

#endif // !CURRENCY
