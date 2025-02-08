#ifndef COUNTER
#define COUNTER

#include <iostream>

class Counter {
public:
	Counter() { number = 0; }
	Counter(long _num) { number = _num; }
	Counter(const Counter& other) { number = other.number; }

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

	Counter operator + (const Counter& other) {
		Counter sum = *this;
		sum += other;
		return sum;
	}

	friend std::ostream& operator << (std::ostream& out, const Counter& counter);
	friend std::istream& operator >> (std::istream& in, Counter& couner);

private:
	long number;
};

std::ostream& operator << (std::ostream& out, const Counter& counter) {
	out << counter.number;
	return out;
}

std::istream& operator >> (std::istream& in, Counter& counter) {
	std::cout << "Enter counter: ";
	in >> counter.number;
	return in;
}

#endif // !COUNTER
