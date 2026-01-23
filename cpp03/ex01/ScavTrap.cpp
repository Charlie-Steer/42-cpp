#include "ScavTrap.hpp"
#include <iostream>

void ScavTrap::initializeValues(void) {
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called.\n";
	initializeValues();
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "ScavTrap " << name << " parametric constructor called.\n";
	initializeValues();
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap " << name << " copy constructor called.\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}

	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " destructor called.\n";
}

void ScavTrap::attack(const std::string &target) {
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage
			  << " points of damage!\n";
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in gate keeper mode.\n";
}
