#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
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

int days_by_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char *month_names[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// WARNING: I THINK THIS HAS TO GO ON HPP FILE BECAUSE IT USES A TEMPLATE.
std::map<std::string, float> *parse_database(std::ifstream &database) {
	std::string line;
	if (!std::getline(database, line)) {
		if (database.eof()) {
			print_error_and_exit("Error: The database is empty.");
		} else {
			print_error_and_exit("Error: Couldn't read from database file.");
		}
	}

	std::map<std::string, float> *database_map = new std::map<std::string, float>();
	while (std::getline(database, line)) {
		size_t separator_index = line.find(',');
		std::string date_str = line.substr(0, separator_index);
		std::string exchange_rate_str = line.substr(separator_index + 1);
		float exchange_rate = atof(exchange_rate_str.c_str());
		database_map->insert(std::make_pair(date_str, exchange_rate));
	}
	return database_map;
}

// Returns 1 if a parsing error occurred.
int parse_input_line(std::string &line, t_request_entry *request_entry) {
	size_t separator_index = line.find('|');
	if (separator_index == std::string::npos) {
		print_error("Error: Incorrect line format. Missing '|' separator in input.");
		return 1;
	}

	std::string date_str = line.substr(0, separator_index);
	std::string bitcoin_amount_str = line.substr(separator_index + 1);

	date_str = date_str.substr(0, date_str.find_last_not_of(" ") + 1);
	bitcoin_amount_str = date_str.substr(0, date_str.find_first_not_of(" "));

	size_t dash_1 = date_str.find('-');
	if (dash_1 == std::string::npos) {
		print_error("Error: Incorrect line format. Missing '-' separator in input.");
		return 1;
	}

	size_t dash_2 = date_str.find('-', dash_1 + 1);
	if (dash_1 == std::string::npos) {
		print_error("Error: Incorrect line format. Missing '-' separator in input.");
		return 1;
	}

	std::string year_str = date_str.substr(0, dash_1);
	std::string month_str = date_str.substr(dash_1 + 1, dash_2 - dash_1 - 1);
	std::string day_str = date_str.substr(dash_2 + 1);

	int year = std::atoi(year_str.c_str());
	int month = std::atoi(month_str.c_str());
	int day = std::atoi(day_str.c_str());
	int bitcoin_amount = std::atoi(bitcoin_amount_str.c_str());

	if (year <= 1000) {
		std::cerr << "Error: " << year << " is an invalid year value. Records start on 2009." << std::endl;
		return 1;
	} else if (year >= 3000) {
		std::cerr << "Error: " << year << " is an invalid year value." << std::endl;
		return 1;
	} else if (month < 1 || month > 12) {
		std::cerr << "Error: " << month << " is an invalid month value." << std::endl;
		return 1;
	} else if (day < 1 || day > 31) {
		std::cerr << "Error: " << day << " is an invalid day value." << std::endl;
		return 1;
	} else if (day > days_by_month[month - 1]) {
		std::cerr << "Error: " << day << " is an invalid day value for month " << month << ". " << month_names[month] << " has " << days_by_month[month] << "days." << std::endl;
		return 1;
	} else if (year % 4 != 0 && month == 2 && day == 29) {
		std::cerr << "Error: " << year << " is not a leap year. 29 is an invalid day." << std::endl;
		return 1;
	}

	request_entry->year = year;
	request_entry->month = month;
	request_entry->day = day;
	request_entry->bitcoin_amount = bitcoin_amount;

	return true;
}

void parse_input_and_print_request_results(std::ifstream &input_file) {
	std::string line;
	// Discard header line.
	if (!std::getline(input_file, line)) {
		if (input_file.eof()) {
			print_error_and_exit("Error: The input file is empty.");
		} else {
			print_error_and_exit("Error: Couldn't read from input file.");
		}
	}
	while (std::getline(input_file, line)) {
		t_request_entry request_entry = {0};
		if (parse_input_line(line, &request_entry) != 1) {
			// TODO: Search in map for date as key.
		}
	}
}

// NOTE: Use map!
int main(int argc, char *argv[]) {
	if (argc != 2) {
		print_error_and_exit("Error: Wrong number of arguments. Required format: btc FILE");
	}

	std::ifstream input_file(argv[1]);
	if (!input_file.is_open()) {
		print_error_and_exit("Error: Couldn't open file.");
	}

	std::ifstream database_file("data.csv");
	if (!database_file.is_open()) {
		print_error_and_exit("Error: Couldn't open database file. Must be named \"data.csv\".");
	}

	std::map<std::string, float> *database_map = parse_database(database_file);
	parse_input_and_print_request_results(input_file);
}
