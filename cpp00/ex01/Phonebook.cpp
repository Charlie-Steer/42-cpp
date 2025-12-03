#include "Phonebook.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>

void Phonebook::add_contact() {
	std::cout << "\nNEW CONTACT\n";
	std::cout << "First Name: ";
	std::getline(std::cin, contacts[new_contact_index].first_name);
	std::cout << "Last Name: ";
	std::getline(std::cin, contacts[new_contact_index].last_name);
	std::cout << "Nickname: ";
	std::getline(std::cin, contacts[new_contact_index].nickname);
	std::cout << "Phone Number: ";
	std::getline(std::cin, contacts[new_contact_index].phone_number);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, contacts[new_contact_index].darkest_secret);
	if (current_max_index < NUM_CONTACTS) {
		++current_max_index;
	}
	new_contact_index = (new_contact_index + 1) % NUM_CONTACTS;
	std::cout << "CONTACT SAVED.\n\n";
}

std::string Phonebook::format_table_field(std::string field) {
	if (field.length() > 10) {
		return field.substr(0, 9) + '.';
	} else {
		return std::string(10 - field.length(), ' ') + field;
	}
}

void Phonebook::search_contact() {
	std::printf("┏━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━┓\n"
				"┃  Index   ┃First Name┃Last Name ┃ Nickname ┃\n"
				"┣━━━━━━━━━━╇━━━━━━━━━━╇━━━━━━━━━━╇━━━━━━━━━━┫\n");

	for (int i = 0; i <= current_max_index; ++i) {
		std::printf("┃%10d", i);
		std::cout << "│" << format_table_field(contacts[i].first_name).c_str();
		std::cout << "│" << format_table_field(contacts[i].last_name).c_str();
		std::cout << "│" << format_table_field(contacts[i].nickname).c_str() << "┃\n";
		if (i < current_max_index) {
			std::printf("┠──────────┼──────────┼──────────┼──────────┨\n");
		}
	}
	std::printf("┗━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━━━┛\n");

	std::cout << "Contact Index: ";
	int requested_index = 0;

	std::string requested_index_string;
	std::getline(std::cin, requested_index_string);

	char *endptr = 0x00;
	requested_index = std::strtol(requested_index_string.c_str(), &endptr, 10);
	if (*endptr != '\0' || (requested_index < 0 || requested_index > current_max_index)) {
		std::cout << "ERROR: Invalid Index.\n";
	} else {
		Contact *contact = &contacts[requested_index];
		std::printf("Index: %d\n"
					"First Name: %s\n"
					"Last Name: %s\n"
					"Nickname: %s\n"
					"Phone Number: %s\n"
					"Darkest Secret: %s\n",
					requested_index, contact->first_name.c_str(), contact->last_name.c_str(), contact->nickname.c_str(),
					contact->phone_number.c_str(), contact->darkest_secret.c_str());
	}
	std::cout << "\n";
}
