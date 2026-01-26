#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
	std::cout << "===== ClapTrap test =====" << std::endl;
	{
		ClapTrap ct("CL4P");
		ct.attack("target");
		ct.takeDamage(3);
		ct.beRepaired(2);
	}

	std::cout << std::endl;
	std::cout << "===== ScavTrap test =====" << std::endl;
	{
		ScavTrap st("SC4V");
		st.attack("intruder");
		st.guardGate();
	}

	std::cout << std::endl;
	std::cout << "===== FragTrap test =====" << std::endl;
	{
		FragTrap ft("FR4G");
		ft.attack("enemy");
		ft.takeDamage(60);
		ft.beRepaired(20);
		ft.takeDamage(100);
		ft.beRepaired(20);
		ft.attack("enemy");
		ft.highFivesGuys();
	}

	std::cout << std::endl;
	std::cout << "===== FragTrap copy constructor test =====" << std::endl;
	{
		FragTrap original("Original");
		FragTrap copy(original);
		copy.highFivesGuys();
	}

	std::cout << std::endl;
	std::cout << "===== FragTrap assignment operator test =====" << std::endl;
	{
		FragTrap a("Alpha");
		FragTrap b("Beta");

		b = a;
		b.highFivesGuys();
	}

	std::cout << std::endl;
	std::cout << "===== Polymorphic deletion test =====" << std::endl;
	{
		ClapTrap *ptr = new FragTrap("Poly");
		delete ptr;
	}

	std::cout << std::endl;
	std::cout << "===== End of tests =====" << std::endl;

	return 0;
}
