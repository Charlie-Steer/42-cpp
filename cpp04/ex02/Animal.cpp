#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Unknown") {
	std::cout << "Animal (" << type << ") default constructor called.\n";
}

Animal::Animal(const std::string &type) : type(type) {
	std::cout << "Animal (" << type << ") type constructor called.\n";
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << "Animal (" << type << ") copy constructor called.\n";
}

Animal &Animal::operator=(const Animal &other) {
	if (this == &other) {
		return *this;
	}

	type = other.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal (" << type << ") destructor called.\n";
}

// void Animal::makeSound() const {
// 	std::cout << "Animal (" << type << "): ???\n";
// }

const std::string &Animal::getType(void) const {
	return type;
}
