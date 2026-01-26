#include "ClapTrap.hpp"
#include <iostream>

void ClapTrap::attack(const std::string &target) {
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage
			  << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << name << " repairs " << amount << " hit points!\n";
}

ClapTrap::ClapTrap() : name(), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "ClapTrap " << name << " default constructor called.\n";
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "ClapTrap " << name << " parametric constructor called.\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name), hit_points(other.hit_points), energy_points(other.energy_points),
	  attack_damage(other.attack_damage) {
	std::cout << "ClapTrap " << name << " copy constructor called.\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap " << name << " assignment operator called.\n";

	if (this == &other) {
		return *this;
	}

	name = other.name;
	hit_points = other.hit_points;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;

	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " destructor called.\n";
}
