#ifndef RANGE
#define RANGE

#include <iostream>

class Range {
public:
	Range() = default;
	Range(int _start, int _end) : start(_start), end(_end) {
		if (start > end) {
			throw std::invalid_argument("Start must be less or equal to end.");
		}
	}
	Range(const Range& other) : Range(other.start, other.end) {}

	bool operator == (const Range& other) const {
		return start == other.start && end == other.end;
	}

	bool operator != (const Range& other) const {
		return !(*this == other);
	}

	bool operator () (int num) const {
		return num >= start && num <= end;
	}

	friend std::ostream& operator << (std::ostream& out, const Range& range);

private:
	int start;
	int end;
};

std::ostream& operator << (std::ostream& out, const Range& range) {
	out << "[" << range.start << ", " << range.end << "]";
	return out;
}

#endif // !RANGE