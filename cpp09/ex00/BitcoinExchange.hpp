#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

typedef struct request_entry {
	int year;
	int month;
	int day;
	double bitcoin_amount;
	std::string date_str;
} t_request_entry;

class BitcoinExchange {
	private:
		static const int days_by_month[12];
		static const char *month_names[12];
		std::map<std::string, float> database_map;

		int parse_database(std::ifstream &database);
		int parse_input_line(std::string &line, t_request_entry *request_entry);
		int parse_input_and_print_request_results(std::ifstream &input_file);
		static bool is_leap_year(int year);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		int get_number_of_days_in_month(int month_number);
		const char *get_month_name(int month_number);
		int load_database(std::string &filename);
		int process_input(std::string &filename);
};

#endif
