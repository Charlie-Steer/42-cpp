#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

void FragTrap::initializeValues(void) {
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called.\n";
	initializeValues();
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "FragTrap " << name << " parametric constructor called.\n";
	initializeValues();
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
	std::cout << "FragTrap " << name << " requests to perform a high five!\n";
}
