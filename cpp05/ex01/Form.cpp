#include "Form.hpp"

Form::Form() : name("Unnamed"), sign_grade(1), execute_grade(150), is_signed(false) {
}

Form::Form(const std::string &name, int sign_grade, int execute_grade)
: name(name), sign_grade(sign_grade), execute_grade(execute_grade), is_signed(false) {
}

Form::Form(const Form &other) : name(other.name), sign_grade(other.sign_grade), execute_grade(other.execute_grade) {
}

Form &Form::operator=(const Form &other) {
	if (this != &other) {
		return *this;
	}
	sign_grade = other.sign_grade;
	execute_grade = other.execute_grade;
	is_signed = other.is_signed;
	return *this;
}
