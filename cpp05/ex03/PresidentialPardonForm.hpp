#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	private:
		void performExecution() const;
};

#endif
