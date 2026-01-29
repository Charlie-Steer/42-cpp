#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cout << type << " default constructor called.\n";
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << type << " copy constructor called.\n";
}

Cat &Cat::operator=(const Cat &other) {
	if (this == &other) {
		return *this;
	}

	Animal::operator=(other);
	return *this;
}

Cat::~Cat() {
	std::cout << type << " destructor called.\n";
}

void Cat::makeSound() const {
	std::cout << type << ": *meow*\n";
}
