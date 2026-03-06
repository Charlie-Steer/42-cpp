#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

		AForm *makeForm(const std::string &name, const std::string &target);

	private:
		AForm* createShrubbery(std::string target);
		AForm* createRobotomy(std::string target);
		AForm* createPardon(std::string target);
};

#endif
