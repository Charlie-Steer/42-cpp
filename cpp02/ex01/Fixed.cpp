#include "Fixed.hpp"
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
	// this->raw_bits = other.raw_bits;
	this->raw_bits = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called.\n";
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called.\n";
	return raw_bits;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called.\n";
	raw_bits = raw;
}
