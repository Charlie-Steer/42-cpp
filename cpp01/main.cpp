#include "Zombie.hpp"

int main(void) {
	Zombie zombie_charlie = Zombie("Charlie");
	Zombie zombie_ana("Ana");
	Zombie *zombie_tobias = newZombie("Tobías");
	randomChump("Mauricio");

	zombie_charlie.announce();
	zombie_ana.announce();
	zombie_tobias->announce();

	delete zombie_tobias;

	return (0);
}
