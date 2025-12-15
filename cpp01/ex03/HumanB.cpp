#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : name(name) {
}

void HumanB::setWeapon(Weapon &new_weapon) {
	weapon = &new_weapon;
}

void HumanB::attack() const {
	if (weapon != NULL) {
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	}
}
