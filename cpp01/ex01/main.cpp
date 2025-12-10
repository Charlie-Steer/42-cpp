#include "Zombie.hpp"

int main(void) {
	int number = 5;
	Zombie *zombie_horde = zombieHorde(number, "Roberto");

	zombie_horde[number / 2].setName("Annie");

	for (int i = 0; i < number; i++) {
		zombie_horde[i].announce();
	}

	delete[] zombie_horde;

	return (0);
}
