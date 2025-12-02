// #include "Contact.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

#define NUM_CONTACTS 8

class Contact {
  public:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

class Phonebook {
  public:
	Contact contacts[NUM_CONTACTS];
	int new_contact_index;
	void add_contact();
	void search_contact();
};

int main(void) {
	Phonebook phonebook = Phonebook();
	std::string user_prompt;
	while (true) {
		std::getline(std::cin, user_prompt);
		if (user_prompt == "ADD") {
			// std::cout << "Command: ADD.\n";
			std::cout << "\nNEW CONTACT\n";
			phonebook.new_contact_index = (phonebook.new_contact_index + 1) % NUM_CONTACTS;
			std::cout << "First Name: ";
			std::getline(std::cin, phonebook.contacts[phonebook.new_contact_index].first_name);
			std::cout << "Last Name: ";
			std::getline(std::cin, phonebook.contacts[phonebook.new_contact_index].last_name);
			std::cout << "Nickname: ";
			std::getline(std::cin, phonebook.contacts[phonebook.new_contact_index].nickname);
			std::cout << "Phone Number: ";
			std::getline(std::cin, phonebook.contacts[phonebook.new_contact_index].phone_number);
			std::cout << "Darkest Secret: ";
			std::getline(std::cin, phonebook.contacts[phonebook.new_contact_index].darkest_secret);
		} else if (user_prompt == "SEARCH") {
			// std::cout << "Command: SEARCH.\n";
			// NOTE: This is not the required format.
			std::cout << "Contact Index: ";
			int requested_index = 0;

			std::string requested_index_string;
			std::getline(std::cin, requested_index_string);

			char *endptr = 0x00;
			requested_index = std::strtol(requested_index_string.c_str(), &endptr, 10);
			if (*endptr != '\0' || (requested_index < 0 || requested_index >= NUM_CONTACTS)) {
				std::cout << "ERROR: Invalid Index.\n";
			} else {
				Contact *contact = &phonebook.contacts[requested_index];
				std::printf("Index: %d\n"
							"First Name: %s\n"
							"Last Name: %s\n"
							"Nickname: %s\n",
							requested_index, contact->first_name.c_str(), contact->last_name.c_str(),
							contact->nickname.c_str());
			}
		} else if (user_prompt == "EXIT") {
			std::cout << "Exiting Phonebook...\n";
			return 0;
		} else {
			std::cout << "Command not found.\n";
		}
		// std::cout << user_prompt;
	}
}
