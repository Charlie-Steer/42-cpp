#include "Harl.hpp"
#include <cctype>
#include <iostream>
#include <string>

#define MESSAGE_TYPE_COUNT 4

static void log(std::string message) {
	std::cerr << message << std::endl;
}

void Harl::debug(void) {
	log("This is a DEBUG message.");
}

void Harl::info(void) {
	log("This is an INFO message.");
}

void Harl::warning(void) {
	log("This is a WARNING message.");
}

void Harl::error(void) {
	log("This is an ERROR message.");
}

void make_string_lowercase(std::string &s) {
	for (std::string::size_type i = 0; i < s.length(); i++) {
		s[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(s[i])));
	}
}

void Harl::complain(std::string level) {
	make_string_lowercase(level);

	std::string level_types[] = {"debug", "info", "warning", "error"};
	void (Harl::*message_func[MESSAGE_TYPE_COUNT])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < MESSAGE_TYPE_COUNT; i++) {
		if (level_types[i] == level) {
			(this->*message_func[i])();
			return;
		}
	}

	std::cerr << "Error: Not a valid message type. Try one of the following: ";

	for (int i = 0; i < MESSAGE_TYPE_COUNT; i++) {
		std::cerr << level_types[i];
		if (i < MESSAGE_TYPE_COUNT - 1) {
			std::cerr << ", ";
		} else {
			std::cerr << ".\n";
		}
	}
}
