#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() : x(0), y(0) {
}

Point::Point(const float x, const float y) : x(x), y(y) {
}

Point::Point(const Point &other) : x(other.x), y(other.y) {
}

Point::~Point() {
}

Fixed Point::getX(void) const {
	return x;
}

Fixed Point::getY(void) const {
	return y;
}
