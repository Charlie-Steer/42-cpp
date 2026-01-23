#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
	std::cout << "===== ClapTrap basic test =====" << std::endl;
	{
		ClapTrap a("CL4P");
		a.attack("target");
		a.takeDamage(5);
		a.beRepaired(3);
	}

	std::cout << std::endl;
	std::cout << "===== ScavTrap basic test =====" << std::endl;
	{
		ScavTrap s("SC4V");
		s.attack("intruder");
		s.takeDamage(20);
		s.beRepaired(10);
		s.guardGate();
	}

	std::cout << std::endl;
	std::cout << "===== Copy constructor test =====" << std::endl;
	{
		ScavTrap original("Original");
		ScavTrap copy(original);

		copy.attack("copy-target");
	}

	std::cout << std::endl;
	std::cout << "===== Assignment operator test =====" << std::endl;
	{
		ScavTrap a("Alpha");
		ScavTrap b("Beta");

		b = a;
		b.attack("assigned-target");
	}

	std::cout << std::endl;
	std::cout << "===== Self-assignment test =====" << std::endl;
	{
		ScavTrap s("Self");
		s = s;
		s.attack("self-target");
	}

	std::cout << std::endl;
	std::cout << "===== Destruction order test =====" << std::endl;
	{
		ScavTrap temp("Temp");
	}

	std::cout << std::endl;
	std::cout << "===== End of tests =====" << std::endl;
	return 0;
}
