#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>
// #include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string name;
		const int sign_grade;
		const int execute_grade;
		bool is_signed;

		std::string target;

    public:
        AForm();
        AForm(const std::string &name, int sign_grade, int execute_grade, std::string target);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        ~AForm();

		const std::string &getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool getIsSigned() const;
		std::string getTarget() const;

		virtual void beSigned(const Bureaucrat &bureaucrat) = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};

		void execute(Bureaucrat &executor) const;
		virtual void performExecution() const = 0;
};

std::ostream &operator<<(std::ostream &stream, const AForm &form);

#endif
