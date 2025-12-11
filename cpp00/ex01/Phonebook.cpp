#include "Phonebook.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

bool is_number(const std::string &s) {
	if (s.empty()) {
		return false;
	}

	for (int i = 0; s[i] != '\0'; i++) {
		if (!std::isdigit(static_cast<unsigned char>(s[i]))) {
			return false;
		}
	}
	return true;
}

void Phonebook::request_field(const std::string &prompt, std::string &field, enum field_type type) {
	while (field.empty()) {
		std::cout << prompt;
		if (!std::getline(std::cin, field)) {
			exit(1);
		}
		if (field.empty()) {
			std::cout << "Error: No fields can be left empty.\n";
		} else if (type == NUMBER && !is_number(field)) {
			std::cout << "Error: Not a valid phone number.\n";
			field.clear();
		}
	}

	for (unsigned long i = 0; i < field.length(); i++) {
		if (field[i] == '\t') {
			field[i] = ' ';
		}
	}
}

void Phonebook::add_contact() {
	Contact contact = Contact();
	request_field("First Name: ", contact.first_name, TEXT);
	request_field("Last Name: ", contact.last_name, TEXT);
	request_field("Nickname: ", contact.nickname, TEXT);
	request_field("Phone Number: ", contact.phone_number, NUMBER);
	request_field("Darkest Secret: ", contact.darkest_secret, TEXT);
	contacts[new_contact_index] = contact;
	if (current_max_index < (NUM_CONTACTS - 1)) {
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

std::string itoa(int value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

void Phonebook::search_contact() {
	std::cout << "┏━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━┓\n"
				 "┃  Index   ┃First Name┃Last Name ┃ Nickname ┃\n"
				 "┣━━━━━━━━━━╇━━━━━━━━━━╇━━━━━━━━━━╇━━━━━━━━━━┫\n";

	for (int i = 0; i <= current_max_index; ++i) {
		std::cout << "┃" << format_table_field(itoa(i)).c_str();
		std::cout << "│" << format_table_field(contacts[i].first_name).c_str();
		std::cout << "│" << format_table_field(contacts[i].last_name).c_str();
		std::cout << "│" << format_table_field(contacts[i].nickname).c_str() << "┃\n";
		if (i < current_max_index) {
			std::cout << "┠──────────┼──────────┼──────────┼──────────┨\n";
		}
	}
	std::cout << "┗━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━━━┛\n";

	if (current_max_index < 0) {
		std::cout << "No entries available.\n\n";
		return;
	}

	std::cout << "Contact Index: ";
	int requested_index = 0;

	std::string requested_index_string;
	if (!std::getline(std::cin, requested_index_string)) {
		exit(1);
	}

	if (requested_index_string.empty()) {
		std::cout << "ERROR: Invalid Index.\n";
		return;
	}

	char *endptr = 0x00;
	requested_index = std::strtol(requested_index_string.c_str(), &endptr, 10);
	if (*endptr != '\0' || (requested_index < 0 || requested_index > current_max_index)) {
		std::cout << "ERROR: Invalid Index.\n";
	} else {
		Contact *contact = &contacts[requested_index];
		std::cout << "First Name: " << contact->first_name.c_str() << '\n';
		std::cout << "Last Name: " << contact->last_name.c_str() << '\n';
		std::cout << "Nickname: " << contact->nickname.c_str() << '\n';
		std::cout << "Phone Number: " << contact->phone_number.c_str() << '\n';
		std::cout << "Darkest Secret: " << contact->darkest_secret.c_str() << '\n';
	}
	std::cout << "\n";
}
