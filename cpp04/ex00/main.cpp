#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

void print_new_line(void) {
	std::cout << "\n";
}

int main() {
	std::cout << "# Polymorphic approach.\n\n";
	const Animal *animal = new Animal();
	const Animal *cat = new Cat();
	const Animal *dog = new Dog();

	print_new_line();

	std::cout << animal->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;

	print_new_line();

	animal->makeSound();
	cat->makeSound();
	dog->makeSound();

	print_new_line();

	delete animal;
	delete cat;
	delete dog;

	std::cout << "\n\n# No virtual dispatch.\n\n";
	const WrongAnimal *wrong_animal = new WrongAnimal();
	const WrongAnimal *wrong_cat = new WrongCat();

	print_new_line();

	std::cout << wrong_animal->getType() << std::endl;
	std::cout << wrong_cat->getType() << std::endl;

	print_new_line();

	wrong_animal->makeSound();
	wrong_cat->makeSound();

	print_new_line();

	delete wrong_animal;
	delete wrong_cat;
	return 0;
}
