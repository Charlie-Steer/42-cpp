#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	Dog dog;
	dog.makeSound();

	Cat cat;
	cat.makeSound();

	AAnimal *polymorphic_dog = new Dog;
	polymorphic_dog->makeSound();

	AAnimal *polymorphic_cat = new Cat;
	polymorphic_cat->makeSound();

	// These lines don't compile due to Animal being abstract.
	// Animal animal;
	// animal.makeSound();

	delete polymorphic_cat;
	delete polymorphic_dog;
}
