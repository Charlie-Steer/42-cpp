#include "Zombie.hpp"
#include <string>

void randomChump(std::string name) {
	Zombie random_chump(name);

	random_chump.announce();
}
