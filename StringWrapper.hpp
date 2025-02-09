#ifndef STRING_WRAPPER
#define STRING_WRAPPER

#include <iostream>
#include <string>

class StringWrapper {
	StringWrapper() : str{} {};
	StringWrapper(const std::string& _str) : str{ _str } {}
	StringWrapper(const StringWrapper& other) = default;
	
	StringWrapper& operator = (const StringWrapper& other) = default;

	StringWrapper& operator += (const StringWrapper& other) {
		if (this != &other) { // checking for self-assignment
			str += other.str;
		}
		return *this;
	}

	StringWrapper operator + (const StringWrapper& other) const {
		StringWrapper sum = *this;
		sum += other;
		return sum;
	}

	bool operator == (const StringWrapper& other) const {
		return str == other.str;
	}

	bool operator != (const StringWrapper& other) const {
		return str != other.str;
	}

	char& operator [] (size_t index) {
		if (index >= str.size()) {
			throw std::out_of_range("Index out of range");
		}
		return str[index];
	}

	const char& operator [] (size_t index) const {
		if (index >= str.size()) {
			throw std::out_of_range("Index out of range");
		}
		return str[index];
	}

	friend std::ostream& operator << (std::ostream& out, const StringWrapper& _str);

private:
	std::string str;
};

std::ostream& operator << (std::ostream& out, const StringWrapper& _str) {
	out << _str.str;
	return out;
}

#endif // !STRING_WRAPPER
