#include "Phonebook.hpp"
#include <iostream>
#include <string>

int main(void) {
	Phonebook phonebook = Phonebook();
	phonebook.current_max_index = -1;
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
