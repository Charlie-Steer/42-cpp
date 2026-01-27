#include "DiamondTrap.hpp"
#include <iostream>

int main() {
	std::cout << "\n--- CONSTRUCTION TEST ---\n";
	DiamondTrap d1("DiamondBob");

	std::cout << "\n--- WHO AM I TEST ---\n";
	d1.whoAmI();

	std::cout << "\n--- ATTACK TEST (must use ScavTrap version) ---\n";
	d1.attack("enemy");

	std::cout << "\n--- ENERGY / HP CONSUMPTION TEST ---\n";
	for (int i = 0; i < 55; i++)
		d1.attack("dummy"); // should stop when energy hits 0

	std::cout << "\n--- REPAIR TEST ---\n";
	d1.beRepaired(20);

	std::cout << "\n--- DAMAGE TEST ---\n";
	d1.takeDamage(200); // should break the robot
	d1.attack("enemy"); // should fail (no HP)

	std::cout << "\n--- COPY CONSTRUCTOR TEST ---\n";
	DiamondTrap d2(d1);
	d2.whoAmI();

	std::cout << "\n--- ASSIGNMENT OPERATOR TEST ---\n";
	DiamondTrap d3("Temporary");
	d3 = d1;
	d3.whoAmI();

	std::cout << "\n--- POLYMORPHISM TEST ---\n";
	ClapTrap *ptr = new DiamondTrap("Poly");
	ptr->attack("target"); // should still use ScavTrap attack
	delete ptr;

	std::cout << "\n--- END OF PROGRAM (DESTRUCTION ORDER) ---\n";
	return 0;
}
