#include "Phonebook.hpp"
#include <iostream>
#include <string>

int main(void) {
	Phonebook phonebook = Phonebook();
	phonebook.current_max_index = -1;
	std::string user_prompt;
	while (true) {
		std::getline(std::cin, user_prompt);
		if (user_prompt == "ADD") {
			phonebook.add_contact();
		} else if (user_prompt == "SEARCH") {
			phonebook.search_contact();
		} else if (user_prompt == "EXIT") {
			std::cout << "Exiting Phonebook...\n";
			return 0;
		} else {
			std::cout << "Command not found.\n\n";
		}
	}
}
