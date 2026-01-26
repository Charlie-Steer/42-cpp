#include "ClapTrap.hpp"
#include <iostream>

int clamp_min(int value, int min) {
	return value < min ? min : value;
}

void ClapTrap::print_health() {
	std::cout << "ClapTrap " << name << " has " << hit_points << " hit points.\n";
}

void ClapTrap::attack(const std::string &target) {
	if (hit_points <= 0) {
		std::cout << "ClapTrap " << name << " can't attack because it is broken.\n";
	} else if (energy_points <= 0) {
		std::cout << "ClapTrap " << name << " can't attack because it has no energy.\n";
	} else {
		energy_points -= 1;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage
				  << " points of damage!\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hit_points <= 0) {
		std::cout << "ClapTrap " << name << " is already broken.\n";
	} else {
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!\n";
		hit_points = clamp_min(hit_points - static_cast<int>(amount), 0);
		ClapTrap::print_health();
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hit_points <= 0) {
		std::cout << "ClapTrap " << name << " can't repair itself because it is broken.\n";
	} else if (energy_points <= 0) {
		std::cout << "ClapTrap " << name << " can't repair itself because it has no energy.\n";
	} else {
		energy_points -= 1;
		std::cout << "ClapTrap " << name << " repairs " << amount << " hit points!\n";
		hit_points += amount;
		ClapTrap::print_health();
	}
}

ClapTrap::ClapTrap() : name(), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "ClapTrap " << name << " default constructor called.\n";
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "ClapTrap " << name << " name constructor called.\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name), hit_points(other.hit_points), energy_points(other.energy_points),
	  attack_damage(other.attack_damage) {
	std::cout << "ClapTrap " << name << " copy constructor called.\n";
}

ClapTrap::ClapTrap(const std::string &name, unsigned int hit_points, unsigned int energy_points,
				   unsigned int attack_damage)
	: name(name), hit_points(hit_points), energy_points(energy_points), attack_damage(attack_damage) {
	std::cout << "ClapTrap " << name << " parametric constructor called.\n";
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
