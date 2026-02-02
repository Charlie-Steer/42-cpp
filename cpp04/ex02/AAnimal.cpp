#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : type("Unknown") {
	std::cout << "Animal (" << type << ") default constructor called.\n";
}

AAnimal::AAnimal(const std::string &type) : type(type) {
	std::cout << "Animal (" << type << ") type constructor called.\n";
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type) {
	std::cout << "Animal (" << type << ") copy constructor called.\n";
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
	if (this == &other) {
		return *this;
	}

	type = other.type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "Animal (" << type << ") destructor called.\n";
}

// void Animal::makeSound() const {
// 	std::cout << "Animal (" << type << "): ???\n";
// }

const std::string &AAnimal::getType(void) const {
	return type;
}
