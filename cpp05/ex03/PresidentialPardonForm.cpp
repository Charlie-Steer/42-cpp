#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5, "") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("Presidential Pardon Form", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm(other) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this == &other) {
		return *this;
	}

	AForm::operator=(other);
	return *this;
}

void PresidentialPardonForm::performExecution() const {
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}
