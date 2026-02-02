#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	std::cout << type << " default constructor called.\n";
	brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << type << " copy constructor called.\n";
	brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other) {
	if (this == &other) {
		return *this;
	}

	Animal::operator=(other);
	if (brain != NULL) {
		delete brain;
	}
	brain = new Brain(*other.brain);
	return *this;
}

Dog::~Dog() {
	std::cout << type << " destructor called.\n";
	delete brain;
}

void Dog::makeSound() const {
	std::cout << type << ": *woof*\n";
}

Brain &Dog::getBrain() const {
	return *brain;
}
