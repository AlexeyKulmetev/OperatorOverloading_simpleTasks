#ifndef COUNTER
#define COUNTER

#include <iostream>

class Counter {
public:
	Counter() = default;
	Counter(long _num) : number{ _num } {}
	Counter(const Counter& other) : number{ other.number } {}

	const Counter& operator = (const Counter& other) {
		if (this == &other) {
			return *this;
		}
		number = other.number;
		return *this;
	}

	Counter& operator ++ () {
		++number;
		return *this;
	}

	Counter operator ++ (int) {
		Counter copy = *this;
		++*this;
		return copy;
	}

	Counter operator -- () {
		if (number) {
			--number;
		}
		return *this;
	}

	Counter operator -- (int) {
		Counter copy = *this;
		--*this;
		return copy;
	}

	Counter& operator += (const Counter& other) {
		number += other.number;
		return *this;
	}

	Counter operator + (const Counter& other) const {
		Counter sum = *this;
		sum += other;
		return sum;
	}

	Counter& operator -= (const Counter& other)  {
		number -= other.number;
		return *this;
	}

	Counter operator - (const Counter& other) const {
		Counter diff = *this;
		diff -= other;
		return diff;
	}

	Counter& operator *= (const Counter& other) {
		number *= other.number;
		return *this;
	}

	Counter operator * (const Counter& other) const {
		Counter prod = *this;
		prod *= other;
		return prod;
	}

	Counter& operator /= (const Counter& other) {
		if (other.number == 0) {
			throw std::runtime_error("Division by zero");
		}
		number /= other.number;
		return *this;
	}

	Counter operator / (const Counter& other) const {
		Counter quotient = *this;
		quotient /= other;
		return quotient;
	}

	friend std::ostream& operator << (std::ostream& out, const Counter& counter);
	friend std::istream& operator >> (std::istream& in, Counter& counter);

private:
	long number;
};

std::ostream& operator << (std::ostream& out, const Counter& counter) {
	out << counter.number;
	return out;
}

std::istream& operator >> (std::istream& in, Counter& counter) {
	in >> counter.number;
	return in;
}

#endif // !COUNTER
