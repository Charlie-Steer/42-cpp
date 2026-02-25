#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Unnamed"), grade(150) {
    // std::cout << "Bureaucrats default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade) {
    // std::cout << "Bureaucrats parametric constructor called." << std::endl;

	if (grade > 150) {
		throw GradeTooLowException();
	}
	if (grade < 1) {
		throw GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
    // std::cout << "Bureaucrats copy constructor called." << std::endl;
}

// Warning: "name" cannot be assigned to.
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    // std::cout << "Bureaucrats copy assignment operator called." << std::endl;
    if (this == &other) {
		return *this;
    }
	grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    // std::cout << "Bureaucrats destructor called." << std::endl;
}

const std::string &Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	if (grade <= 1) {
		throw GradeTooHighException();
	}
	--grade;
}

void Bureaucrat::decrementGrade() {
	if (grade >= 150) {
		throw GradeTooLowException();
	}
	++grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Attempt to assign a grade too high. Valid range (1, 150). 1 is highest.\n";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Attempt to assign a grade too low. Valid range (1, 150). 150 is lowest.\n";
}


void Bureaucrat::signForm(AForm &form) const {
	if (!form.getIsSigned()) {
		try {
			form.beSigned(*this);
			std::cout << name << " signed " << form.getName() << ".\n";
		} catch (const std::exception &e) {
			std::cout << name << " couldn't sign " << form.getName() << " because: " << e.what() << std::endl;
		}
	}
}


std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat) {
	ostream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return ostream;
}
