#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("Unknown") {
	std::cout << "WrongAnimal (" << type << ") default constructor called.\n";
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type) {
	std::cout << "WrongAnimal (" << type << ") type constructor called.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
	std::cout << "WrongAnimal (" << type << ") copy constructor called.\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this == &other) {
		return *this;
	}

	type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal (" << type << ") destructor called.\n";
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal (" << type << "): ???\n";
}

const std::string &WrongAnimal::getType(void) const {
	return type;
}
