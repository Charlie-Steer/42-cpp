#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "common.hpp"

class Phonebook {
  public:
	Phonebook();
	Contact contacts[NUM_CONTACTS];
	void add_contact();
	void search_contact();

  private:
	int current_max_index;
	int new_contact_index;
	std::string format_table_field(std::string field);
	std::string request_field(const std::string &prompt, enum field_type type);
};

#endif
