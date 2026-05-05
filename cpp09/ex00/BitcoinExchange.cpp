#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include "BitcoinExchange.hpp"

static void print_error(const char *error_message) {
	std::cerr << error_message << std::endl;
}

bool BitcoinExchange::is_leap_year(int year) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				return true;
			} else {
				return false;
			}
		} else {
			return true;
		}
	} else {
		return false;
	}
}

const int BitcoinExchange::days_by_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char *BitcoinExchange::month_names[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		this->database_map = other.database_map;
	}
	return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange::~BitcoinExchange() {}


int BitcoinExchange::get_number_of_days_in_month(int month_number) {
	return days_by_month[month_number - 1];
}

int BitcoinExchange::parse_database(std::ifstream &database) {
	std::string line;
	if (!std::getline(database, line)) {
		if (database.eof()) {
			print_error("Error: The database is empty.");
			return 1;
		} else {
			print_error("Error: Couldn't read from database file.");
			return 1;
		}
	}

	while (std::getline(database, line)) {
		size_t separator_index = line.find(',');
		std::string date_str = line.substr(0, separator_index);
		std::string exchange_rate_str = line.substr(separator_index + 1);
		float exchange_rate = atof(exchange_rate_str.c_str());
		database_map.insert(std::make_pair(date_str, exchange_rate));
	}
	return 0;
}

int BitcoinExchange::load_database(std::string &filename) {
	std::ifstream database_file(filename.c_str());
	if (!database_file.is_open()) {
		print_error("Error: Couldn't open database file. Must be named \"data.csv\".");
		return 1;
	}

	return parse_database(database_file);
}

int BitcoinExchange::parse_input_line(std::string &line, t_request_entry *request_entry) {
	size_t separator_index = line.find('|');
	if (separator_index == std::string::npos) {
		std::cerr << "Error: Incorrect line format. Missing '|' separator in input.";
		std::cerr << " Line: \"" << line << "\"" <<std::endl;
		return 1;
	}

	std::string date_str = line.substr(0, separator_index);
	std::string bitcoin_amount_str = line.substr(separator_index + 1);

	date_str = date_str.substr(0, date_str.find_last_not_of(" ") + 1);
	bitcoin_amount_str = bitcoin_amount_str.substr(bitcoin_amount_str.find_first_not_of(" "));

	size_t dash_1 = date_str.find('-');
	if (dash_1 == std::string::npos) {
		print_error("Error: Incorrect line format. Missing '-' separator in input.");
		std::cerr << " Line: \"" << line << "\"" <<std::endl;
		return 1;
	}

	size_t dash_2 = date_str.find('-', dash_1 + 1);
	if (dash_2 == std::string::npos) {
		print_error("Error: Incorrect line format. Missing '-' separator in input.");
		std::cerr << " Line: \"" << line << "\"" <<std::endl;
		return 1;
	}

	std::string year_str = date_str.substr(0, dash_1);
	std::string month_str = date_str.substr(dash_1 + 1, dash_2 - dash_1 - 1);
	std::string day_str = date_str.substr(dash_2 + 1);

	int year = std::atoi(year_str.c_str());
	int month = std::atoi(month_str.c_str());
	int day = std::atoi(day_str.c_str());
	double bitcoin_amount = std::atof(bitcoin_amount_str.c_str());

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
	} else if (day > get_number_of_days_in_month(month) && !(month == 2 && day == 29)) {
		std::cerr << "Error: " << day << " is an invalid day value for month " << month << ". " << month_names[month - 1] << " has " << days_by_month[month - 1] << " days." << std::endl;
		return 1;
	} else if (!BitcoinExchange::is_leap_year(year) && month == 2 && day == 29) {
		std::cerr << "Error: " << year << " is not a leap year. 29 is an invalid day for February." << std::endl;
		return 1;
	} else if (bitcoin_amount < 0 || bitcoin_amount > 1000) {
		std::cerr << "Error: " << bitcoin_amount << " is an invalid bitcoin amount. Range: (0, 1000)." << std::endl;
		return 1;
	}

	request_entry->date_str = date_str;
	request_entry->year = year;
	request_entry->month = month;
	request_entry->day = day;
	request_entry->bitcoin_amount = bitcoin_amount;

	return 0;
}

int BitcoinExchange::parse_input_and_print_request_results(std::ifstream &input_file) {
	std::string line;
	// Discard header line.
	if (!std::getline(input_file, line)) {
		if (input_file.eof()) {
			print_error("Error: The input file is empty.");
			return 1;
		} else {
			print_error("Error: Couldn't read from input file.");
			return 1;
		}
	}
	while (std::getline(input_file, line)) {
		t_request_entry request_entry = {0, 0, 0, 0.0, ""};
		if (parse_input_line(line, &request_entry) == 0) {
			//std::map<std::string, float>::iterator database_entry_match = database_map.find(request_entry.date_str);
			std::map<std::string, float>::iterator it = database_map.upper_bound(request_entry.date_str);
			if (it != database_map.begin()) {
				--it;
				std::cout << request_entry.date_str << " => " << request_entry.bitcoin_amount << " = " << (request_entry.bitcoin_amount * it->second) << std::endl;
			} else {
				std::cerr << "Error: Date couldn't be matched to an exact or earlier date." << std::endl;
			}
		}
	}
	return 0;
}

int BitcoinExchange::process_input(std::string &filename) {
	std::ifstream input_file(filename.c_str());
	if (!input_file.is_open()) {
		print_error("Error: Couldn't open file.");
		return 1;
	}

	return parse_input_and_print_request_results(input_file);
}
