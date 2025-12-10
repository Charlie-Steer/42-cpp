#include "Zombie.hpp"
#include <string>

Zombie *zombieHorde(int N, std::string name) {
	if (N <= 0) {
		return NULL;
	}

	Zombie *zombie_horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		zombie_horde[i].setName(name);
	}

	return zombie_horde;
}
