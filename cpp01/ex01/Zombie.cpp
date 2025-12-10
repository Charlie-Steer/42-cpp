#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("") {
}

Zombie::Zombie(std::string name) : name(name) {
}

Zombie::~Zombie() {
	std::cout << "Destroying: " << name << ".\n";
}

void Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name) {
	this->name = name;
}
