#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() {
	std::cout << "Default constructor called.\n";
	raw_bits = 0;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called.\n";
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called.\n";
	if (this == &other) {
		return *this;
	}
	this->raw_bits = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called.\n";
}

int Fixed::getRawBits(void) const {
	return raw_bits;
}

void Fixed::setRawBits(int const raw) {
	raw_bits = raw;
}

// ex01:

Fixed::Fixed(const int decimal) {
	std::cout << "Int constructor called.\n";
	raw_bits = decimal << num_fractional_bits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called.\n";
	raw_bits = static_cast<int>(roundf(value * (1 << num_fractional_bits)));
}

int Fixed::toInt(void) const {
	return (raw_bits >> num_fractional_bits);
}

float Fixed::toFloat(void) const {
	return (static_cast<float>(raw_bits) / (1 << num_fractional_bits));
}

std::ostream &operator<<(std::ostream &stream, const Fixed &fx) {
	stream << fx.toFloat();
	return stream;
}

// ex02:

bool Fixed::operator>(const Fixed &other) const {
	return (raw_bits > other.raw_bits);
}

bool Fixed::operator<(const Fixed &other) const {
	return (raw_bits < other.raw_bits);
}

bool Fixed::operator>=(const Fixed &other) const {
	return (raw_bits >= other.raw_bits);
}

bool Fixed::operator<=(const Fixed &other) const {
	return (raw_bits <= other.raw_bits);
}

bool Fixed::operator==(const Fixed &other) const {
	return (raw_bits == other.raw_bits);
}

bool Fixed::operator!=(const Fixed &other) const {
	return (raw_bits != other.raw_bits);
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(raw_bits + other.raw_bits);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(raw_bits - other.raw_bits);
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result.setRawBits((static_cast<long>(raw_bits) * other.raw_bits) >> num_fractional_bits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
	result.setRawBits((static_cast<long>(raw_bits) << num_fractional_bits) / other.raw_bits);
	return result;
}
