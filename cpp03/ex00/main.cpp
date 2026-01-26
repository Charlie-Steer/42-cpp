#include "ClapTrap.hpp"
#include <iostream>

int main() {
	std::cout << "----- Default construction -----\n";
	ClapTrap a;

	std::cout << "\n----- Parametrized construction -----\n";
	ClapTrap b("Charlie");

	std::cout << "\n----- Copy construction -----\n";
	ClapTrap c(b);

	std::cout << "\n----- Assignment operator -----\n";
	a = b;

	std::cout << "\n----- Verb functions -----\n";
	b.attack("target_dummy");
	b.takeDamage(6);
	b.beRepaired(3);
	b.takeDamage(100);
	b.takeDamage(7);
	b.beRepaired(3);
	b.attack("target_dummy");

	std::cout << "\n----- Self-assignment (edge case) -----\n";
	b = b;

	std::cout << "\n----- End of scope -----\n";
	return 0;
}
