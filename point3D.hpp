#ifndef POINT_3D
#define POINT_3D
#include <iostream>

class Point3D {
	Point3D() = default;
	Point3D(int _x, int _y, int _z) : x{ _x }, y{ _y }, z{ _z } {}
	Point3D(const Point3D& other) : x{ other.x }, y{ other.y }, z{ other.z } {}

	const Point3D& operator = (const Point3D& other) {
		if (this != &other) {
			x = other.x;
			y = other.y;
			z = other.z;
		}
		return *this;
	}

	const Point3D& operator += (const Point3D& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	Point3D operator + (const Point3D& other) const {
		Point3D sum = *this;
		sum += other;
		return sum;
	}

	const Point3D& operator -= (const Point3D& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	Point3D operator - (const Point3D& other) const {
		Point3D diff = *this;
		diff -= other;
		return diff;
	}

	int operator * (const Point3D& other) {
		return x * other.x + y * other.y + z * other.z;
	}

	bool operator == (const Point3D& other) const {
		return (x == other.x) && (y == other.y) && (z == other.z);
	}

	friend std::ostream& operator << (std::ostream& out, const Point3D& other);

private:
	int x, y, z;
};

std::ostream& operator << (std::ostream& out, const Point3D& point3D) {
	out << "(" << point3D.x << ", " << point3D.y << ", " << point3D.z << ")";
	return out;
}

#endif // !POINT_3D
