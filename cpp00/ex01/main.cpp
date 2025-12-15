#include "Phonebook.hpp"
#include <iostream>
#include <string>

int main(void) {
	Phonebook phonebook = Phonebook();
	phonebook.current_max_index = -1;

	std::cout << "CHARLIE'S PHONEBOOK\n\n";
	std::cout << "Commands:\n";
	std::cout << "ADD: Add new contact.\n";
	std::cout << "SEARCH: Display contacts and show chosen contact's info.\n";
	std::cout << "EXIT: Close program.\n\n";

	std::string user_prompt;
	while (true) {
		if (user_prompt == "EXIT" || !std::getline(std::cin, user_prompt)) {
			std::cout << "Exiting Phonebook...\n";
			return (0);
		} else if (user_prompt == "ADD") {
			phonebook.add_contact();
		} else if (user_prompt == "SEARCH") {
			phonebook.search_contact();
		} else {
			std::cout << "Command not found.\n\n";
		}
	}
}
