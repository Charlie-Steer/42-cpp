#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	std::cout << type << " default constructor called.\n";
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << type << " copy constructor called.\n";
}

Dog &Dog::operator=(const Dog &other) {
	if (this == &other) {
		return *this;
	}

	Animal::operator=(other);
	return *this;
}

Dog::~Dog() {
	std::cout << type << " destructor called.\n";
}

void Dog::makeSound() const {
	std::cout << type << ": *woof*\n";
}
