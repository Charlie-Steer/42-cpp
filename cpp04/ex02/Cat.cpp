#include "Cat.hpp"
#include <iostream>

Cat::Cat() : AAnimal("Cat") {
	std::cout << type << " default constructor called.\n";
	brain = new Brain();
}

Cat::Cat(const Cat &other) : AAnimal(other) {
	std::cout << type << " copy constructor called.\n";
	brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other) {
	if (this == &other) {
		return *this;
	}

	AAnimal::operator=(other);
	if (brain != NULL) {
		delete brain;
	}
	brain = new Brain(*other.brain);
	return *this;
}

Cat::~Cat() {
	std::cout << type << " destructor called.\n";
	delete brain;
}

void Cat::makeSound() const {
	std::cout << type << ": *meow*\n";
}

Brain &Cat::getBrain() const {
	return *brain;
}
