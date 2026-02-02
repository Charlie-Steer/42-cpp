#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class AAnimal {
  protected:
	std::string type;

  public:
	AAnimal();
	AAnimal(const std::string &type);
	AAnimal(const AAnimal &other);
	AAnimal &operator=(const AAnimal &other);
	virtual ~AAnimal();

	virtual void makeSound() const = 0;
	const std::string &getType(void) const;
};

#endif
