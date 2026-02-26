#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Unnamed", 145, 137, "") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target)
: AForm(name, 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this == &other) {
		return *this;
	}

	AForm::operator=(other);
	return *this;
}

void ShrubberyCreationForm::performExecution() const {
}
