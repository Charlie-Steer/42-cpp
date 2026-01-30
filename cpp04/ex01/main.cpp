#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

#define ANIMAL_COUNT 10

int main() {
	Animal *animals[ANIMAL_COUNT];
	for (int animal_idx = 0; animal_idx < ANIMAL_COUNT; animal_idx++) {
		std::cout << "Animal #" << animal_idx + 1 << "\n";
		if (animal_idx % 2 == 0) {
			animals[animal_idx] = new Dog();
		} else {
			animals[animal_idx] = new Cat();
		}
		std::cout << "\n";
	}

	std::cout << "\n";

	for (int animal_idx = 0; animal_idx < ANIMAL_COUNT; animal_idx++) {
		std::cout << "Animal #" << animal_idx + 1 << "\n";
		delete animals[animal_idx];
		std::cout << "\n";
	}

	Cat cat1;
	Brain &cat1_brain = cat1.getBrain();
	std::cout << "CAT1 IDEA: " << *cat1_brain.getIdea(0) << "\n";
	cat1_brain.setIdea(0, "Potato");
	std::cout << "CAT1 IDEA: " << *cat1_brain.getIdea(0) << "\n";

	Cat cat2(cat1);
	Brain &cat2_brain = cat2.getBrain();
	std::cout << "CAT2 IDEA: " << *cat2_brain.getIdea(0) << "\n";

	cat1_brain.setIdea(0, "Salmon");
	std::cout << "CAT1 IDEA: " << *cat1_brain.getIdea(0) << "\n";
	std::cout << "CAT2 IDEA: " << *cat2_brain.getIdea(0) << "\n";
}
