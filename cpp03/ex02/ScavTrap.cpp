#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("default_name", 100, 50, 20) {
	std::cout << "ScavTrap default constructor called.\n";
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "ScavTrap " << name << " name constructor called.\n";
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
	if (hit_points <= 0) {
		std::cout << "ScavTrap " << name << " can't attack because it is broken.\n";
	} else if (energy_points <= 0) {
		std::cout << "ScavTrap " << name << " can't attack because it has no energy.\n";
	} else {
		energy_points -= 1;
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage
				  << " points of damage!\n";
	}
}

void ScavTrap::guardGate() {
	if (hit_points <= 0) {
		std::cout << "ScavTrap " << name << " can't enter gate keeper mode because it is broken.\n";
	} else {
		std::cout << "ScavTrap " << name << " is now in gate keeper mode.\n";
	}
}
