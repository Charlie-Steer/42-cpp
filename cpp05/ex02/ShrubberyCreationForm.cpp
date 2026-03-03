#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137, "") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("Shrubbery Creation Form", 145, 137, target) {}

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
	std::ofstream file((getTarget() + "_shrubbery").c_str());

	file <<
		"     \\\n"
		"  \\   \\/\n"
		"  o\\/ /o\n"
		"   o\\/\n"
		"     \\_/o\n"
		"    _/\n"
		"     \\\n"
		"    _/\\_=_\n"
		;
}
