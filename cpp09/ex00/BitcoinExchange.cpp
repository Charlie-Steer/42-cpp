#include <algorithm>
#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

void print_error(const char *error_message) {
	std::cerr << error_message << std::endl;
}

void print_error_and_exit(const char *error_message) {
	print_error(error_message);
	exit(1);
}

typedef struct request_entry {
	int year;
	int month;
	int day;
	int bitcoin_amount;
} t_request_entry;

typedef struct token {
	
} t_token;

// Returns false if a parsing error occurred.
bool parse_input_line(std::string line, t_request_entry *request_entry) {
	size_t separator_index = line.find('|');
	if (separator_index == std::string::npos) {
		print_error("Error: Incorrect line format. Missing '|' separator in input.");
		return false;
	}

	std::string date_str = line.substr(0, separator_index);
	std::string bitcoin_amount_str = line.substr(separator_index + 1);

	date_str = date_str.substr(0, date_str.find_last_not_of(" ") + 1);
	bitcoin_amount_str = date_str.substr(0, date_str.find_first_not_of(" "));

	size_t dash_1 = date_str.find('-');
	if (dash_1 == std::string::npos) {
		print_error("Error: Incorrect line format. Missing '-' separator in input.");
		return false;
	}

	size_t dash_2 = date_str.find('-', dash_1 + 1);
	if (dash_1 == std::string::npos) {
		print_error("Error: Incorrect line format. Missing '-' separator in input.");
		return false;
	}

	std::string year_str = date_str.substr(0, dash_1);
	std::string month_str = date_str.substr(dash_1 + 1, dash_2 - dash_1 - 1);
	std::string day_str = date_str.substr(dash_2 + 1);


	request_entry->year = std::atoi(year_str.c_str());
	request_entry->month = std::atoi(month_str.c_str());
	request_entry->day = std::atoi(day_str.c_str());
	request_entry->bitcoin_amount = std::atoi(bitcoin_amount_str.c_str());

	return true;
}

// NOTE: Use map!
int main(int argc, char *argv[]) {
	if (argc != 2) {
		print_error_and_exit("Error: Wrong number of arguments. Required format: btc FILE");
	}

	std::ifstream input_file(argv[1]);
	if (!input_file.is_open()) {
		print_error_and_exit("Error: Couln't open file.");
	}

	std::string line;
	while (std::getline(input_file, line)) {
		t_request_entry request_entry = {0};
		if (parse_input_line(line, &request_entry)) {
			// TODO:
		}
	}

}
