#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("default_name", 100, 100, 30) {
	std::cout << "FragTrap default constructor called.\n";
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name, 100, 100, 30) {
	std::cout << "FragTrap " << name << " parametric constructor called.\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "FragTrap " << name << " copy constructor called.\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}

	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << " destructor called.\n";
}

void FragTrap::highFivesGuys() {
	if (hit_points <= 0) {
		std::cout << "FragTrap " << name << " can't high five because it is broken.\n";
	} else {
		std::cout << "FragTrap " << name << " requests to perform a high five!\n";
	}
}
