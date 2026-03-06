#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
    // std::cout << "Interns default constructor called." << std::endl;
}

Intern::Intern(const Intern& other) {
    // std::cout << "Interns copy constructor called." << std::endl;
	(void)other;
}

// Warning: "name" cannot be assigned to.
Intern& Intern::operator=(const Intern& other) {
    // std::cout << "Interns copy assignment operator called." << std::endl;
    if (this == &other) {
		return *this;
    }
    return *this;
}

Intern::~Intern() {
    // std::cout << "Interns destructor called." << std::endl;
}

AForm* Intern::createShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) {
	std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
	};

	AForm *(Intern::*formCreators[])(std::string) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPardon,
	};

	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			std::cout << "Intern creates " << name << "." <<std::endl;
			return (this->*formCreators[i])(target);
		}
	}

	std::cerr << "Error: \"" << name <<"\" doesn't match any valid possible names." << std::endl;
	return NULL;
}
