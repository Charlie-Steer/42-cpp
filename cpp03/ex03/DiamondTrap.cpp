#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

#define DEFAULT_NAME "default_name"

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(name), FragTrap(name), name(name) {
	std::cout << "DiamondTrap " << name << " name constructor called.\n";
}

DiamondTrap::DiamondTrap()
	: ClapTrap(std::string(DEFAULT_NAME) + "_clap_name", 100, 50, 30), ScavTrap(DEFAULT_NAME), FragTrap(DEFAULT_NAME),
	  name(DEFAULT_NAME) {
	std::cout << "DiamondTrap " << name << " default constructor called.\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
	std::cout << "DiamondTrap " << name << " copy constructor called.\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this == &other) {
		return *this;
	} else {
		ClapTrap::operator=(other);
		name = other.name;
		return *this;
	}
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << name << " destructor called.\n";
}

void DiamondTrap::whoAmI() const {
	std::cout << "My DiamondTrap name is " << name << " and my ClapTrap name is " << ClapTrap::name << ".\n";
}
