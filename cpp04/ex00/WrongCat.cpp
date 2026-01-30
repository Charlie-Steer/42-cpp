#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << type << " default constructor called.\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << type << " copy constructor called.\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this == &other) {
		return *this;
	}

	WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << type << " destructor called.\n";
}

void WrongCat::makeSound() const {
	std::cout << type << ": *meow*\n";
}
