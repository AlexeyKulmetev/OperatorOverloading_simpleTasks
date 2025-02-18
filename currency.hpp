#ifndef CURRENCY
#define CURRENCY

#include <cmath>


class Currency {
public:
	Currency() = default;
	Currency(const double _dollars) : dollars(_dollars) {}
	Currency(const Currency& other) = default;

	operator double() const {
		return dollars * EURO_RATE;
	}

	operator int() const {
		return static_cast<int>(std::round(dollars * RUBLE_RATE));
	}

private:
	double dollars;
	static constexpr double EURO_RATE = 0.85;
	static constexpr int RUBLE_RATE = 75;
};

Currency operator "" _usd(long double x) {
	return Currency(static_cast<double>(x));
}

#endif // !CURRENCY
