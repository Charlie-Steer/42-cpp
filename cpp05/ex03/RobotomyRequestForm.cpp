#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45, "") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("Robotomy Request Form", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm(other) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this == &other) {
		return *this;
	}

	AForm::operator=(other);
	return *this;
}

void RobotomyRequestForm::performExecution() const {
	std::cout << "brrrr BRRRRR BZZZZZ bzzz...\n";

	int result = rand() % 2;
	if (result == 0) {
		std::cout << getTarget() << "'s robotomization FAILED.\n";
	} else {
		std::cout << getTarget() << " has been robotomized.\n";
	}
}
