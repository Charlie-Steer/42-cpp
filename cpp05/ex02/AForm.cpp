#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Unnamed"), sign_grade(1), execute_grade(150), is_signed(false) {}

Form::Form(const std::string &name, int sign_grade, int execute_grade)
: name(name), sign_grade(sign_grade), execute_grade(execute_grade), is_signed(false) {
	if (sign_grade > 150 || execute_grade > 150) {
		throw GradeTooLowException();
	} else if (sign_grade < 1 || execute_grade < 1) {
		throw GradeTooHighException();
	}
}

Form::Form(const Form &other) : name(other.name), sign_grade(other.sign_grade), execute_grade(other.execute_grade), is_signed(false) {}

Form &Form::operator=(const Form &other) {
	if (this == &other) {
		return *this;
	}
	is_signed = other.is_signed;
	return *this;
}

Form::~Form() {}

const std::string &Form::getName() const {
	return name;
}

int Form::getSignGrade() const {
	return sign_grade;
}

int Form::getExecuteGrade() const {
	return execute_grade;
}

bool Form::getIsSigned() const {
	return is_signed;
}


void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (!is_signed) {
		if (bureaucrat.getGrade() <= sign_grade) {
			is_signed = true;
		} else {
			throw GradeTooLowException();
		}
	}
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Attempt to assign a grade too high. Valid range (1, 150). 1 is highest.";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Attempt to sign a form with a bureaucrat with too low of a grade or attempt to assign a grade too low. Valid range (1, 150). 150 is lowest.";
}


std::ostream &operator<<(std::ostream &ostream, const Form &form) {
	ostream << "Form " << form.getName() << " with sign_grade " << form.getSignGrade() << " and execute_grade " << form.getExecuteGrade() << " is ";
	if (form.getIsSigned()) {
		ostream << "SIGNED.";
	} else {
		ostream << "NOT SIGNED.";
	}
	ostream << std::endl;
	return ostream;
}
