#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Unnamed"), sign_grade(1), execute_grade(150), is_signed(false), target("") {}

AForm::AForm(const std::string &name, int sign_grade, int execute_grade, std::string target)
: name(name), sign_grade(sign_grade), execute_grade(execute_grade), is_signed(false), target(target) {
	if (sign_grade > 150 || execute_grade > 150) {
		throw GradeTooLowException();
	} else if (sign_grade < 1 || execute_grade < 1) {
		throw GradeTooHighException();
	}
}

AForm::AForm(const AForm &other) : name(other.name), sign_grade(other.sign_grade), execute_grade(other.execute_grade), is_signed(false), target(other.target) {}

AForm &AForm::operator=(const AForm &other) {
	if (this == &other) {
		return *this;
	}
	is_signed = other.is_signed;
	target = other.target;
	return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const {
	return name;
}

int AForm::getSignGrade() const {
	return sign_grade;
}

int AForm::getExecuteGrade() const {
	return execute_grade;
}

bool AForm::getIsSigned() const {
	return is_signed;
}

std::string AForm::getTarget() const {
	return target;
}


void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (!is_signed) {
		if (bureaucrat.getGrade() <= sign_grade) {
			is_signed = true;
		} else {
			throw GradeTooLowException();
		}
	}
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Attempt to assign a grade too high. Valid range (1, 150). 1 is highest.";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Attempt to sign/execute a form with a bureaucrat with too low of a grade or attempt to assign a grade too low. Valid range (1, 150). 150 is lowest.";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Attempt to execute an unsigned form.";
}

void AForm::execute(Bureaucrat &executor) const {
	if (!is_signed) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > execute_grade) {
		throw GradeTooLowException();
	}
	performExecution();
}

void AForm::performExecution() const {}


std::ostream &operator<<(std::ostream &ostream, const AForm &form) {
	ostream << "Form " << form.getName() << " (" << form.getTarget() << ") " << " with sign_grade " << form.getSignGrade() << ", execute_grade " << form.getExecuteGrade() << " is ";
	if (form.getIsSigned()) {
		ostream << "SIGNED.";
	} else {
		ostream << "NOT SIGNED.";
	}
	ostream << std::endl;
	return ostream;
}
