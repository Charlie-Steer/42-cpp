#include "PmergeMe.hpp"

#include <iostream>
#include <exception>
#include <ctime>
#include <cstdlib>

#define ERROR(message) std::cerr << "Error: " message << std::endl

int main(int argc, char** argv) {
	if (argc <= 1) {
		ERROR("No arguments provided");
		exit(EXIT_FAILURE);
	}
	try {
		PmergeMe sorter;
		
		clock_t beginVec = std::clock();
		sorter.parse_input_vector(++argv);
		std::cout << "Before:	";
		PmergeMe::print_vector(sorter.get_vector());
		sorter.sort_vector();
		std::cout << "After:	";
		PmergeMe::print_vector(sorter.get_vector());
  		clock_t endVec = clock();
  		double elapsed_usecs = double(endVec - beginVec) / CLOCKS_PER_SEC * 1000000;
		std::cout << "Time to process a range of " << argc - 1 
		<< " elements with std::vector: " << elapsed_usecs << " us" << std::endl;
	
		clock_t beginDeq = std::clock();
		sorter.parse_input_deque(argv);
		//std::cout << "Before: ";
		//PmergeMe::printDeq(pme.getDeq());
		sorter.sort_deque();
		//std::cout << "After: ";
		//PmergeMe::printDeq(pme.getDeq());
  		clock_t endDeq = clock();
  		elapsed_usecs = double(endDeq - beginDeq) / CLOCKS_PER_SEC * 1000000;
		std::cout << "Time to process a range of " << argc - 1 
		<< " elements with std::deque: " << elapsed_usecs << " us" << std::endl;
	} catch (std::exception const& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
