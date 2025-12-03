#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include "common.hpp"

class Phonebook {
  public:
	Contact contacts[NUM_CONTACTS];
	int new_contact_index;
	int current_max_index;
	void add_contact();
	void search_contact();

  private:
	std::string format_table_field(std::string field);
};

#endif
