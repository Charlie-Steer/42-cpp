#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>
// #include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string name;
		const int sign_grade;
		const int execute_grade;
		bool is_signed;

    public:
        Form();
        Form(const std::string &name, int sign_grade, int execute_grade);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

		const std::string &getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool getIsSigned() const;

		void beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &stream, const Form &form);

#endif
