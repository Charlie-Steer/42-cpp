#include "PmergeMe.hpp"
#include <climits>
#include <iostream>
#include <cstdlib>
#include <algorithm>

PmergeMe::PmergeMe(void) {}

PmergeMe::~PmergeMe(void) {}

std::vector<int> const&	PmergeMe::get_vector(void) const {
	return (this->_vector);
}

std::deque<int> const&	PmergeMe::get_deque(void) const {
	return (this->_deque);
}



// VECTOR VERSION

void PmergeMe::parse_input_vector(char** input) {
	char*	endptr = NULL;
	long	temp;
	int		number;

	while (*input && **input) {
		temp = strtol(*input, &endptr, 10);
		if (*endptr) {
			throw std::invalid_argument("Error: not a number.");
		} if (temp <= 0) {
			throw std::invalid_argument("Error: accepts only strictly positive numbers.");
		} if (temp > INT_MAX) {
			throw std::invalid_argument("Error: int overflow.");
		}
		number = static_cast<int>(temp);
		this->_vector.push_back(number);
		++input;
	}
	if (this->_vector.size() == 0) {
		throw std::invalid_argument("Error: empty sequence.");
	}

	return;
}

void PmergeMe::print_vector(std::vector<int> const& v) {
	std::vector<int>::const_iterator it;
	for (it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return;
}

void PmergeMe::sort_vector(void) {
	// Copy vector.
	std::vector<int> v = this->_vector;
	// Not useful at first. Only recursively.
	std::vector<int> indexes;

	// Recursively sort copy.
	PmergeMe::_recursively_sort_vector(v, indexes);
	// Replace original.
	this->_vector = v;

	return;
}

void PmergeMe::_recursively_sort_vector(std::vector<int>& v, std::vector<int>& indexes)
{
	bool is_first_call = indexes.empty();

	// Base case.
	if (v.size() == 1) {
		return;
	}

	/* 	Virtually split into two equal-length segments (odd element unused if any)
		Virtually pair i-th element of each segment and make comparison
		Swap to have elements in first segment >= corresponding elements in second segment */
	
	std::vector<int>::iterator	it1 = v.begin(); // Points to beginning of first segment.
	std::vector<int>::iterator	it2 = it1 + v.size() / 2; // Points to beginning of second segment.
	std::vector<int>::iterator	itInd1; // Same for index sequence.
	std::vector<int>::iterator	itInd2;
	if (!is_first_call) {
		itInd1 = indexes.begin(); // Same for index sequence.
		itInd2 = itInd1 + v.size() / 2;
	}
	
	for (unsigned long j = 0; j < v.size() / 2; ++j) {
		if (*it2 > *it1) {
			std::iter_swap(it1, it2);
			if (!is_first_call)
				std::iter_swap(itInd1, itInd2);
		}
		++it1;
		++it2;
		if (!is_first_call) {
			++itInd1;
			++itInd2;
		}
	}
	
	// Split main and pending parts for both vec and Indexes
	std::vector<int> vector_main(v.begin(), v.begin() + v.size() / 2);
	std::vector<int> vector_pending(v.begin() + v.size() / 2, v.end());
	std::vector<int> index_main;
	std::vector<int> index_pending;

	if (!is_first_call) {
		index_main.insert(index_main.end(), indexes.begin(), indexes.begin() + v.size() / 2);
		index_pending.insert(index_pending.end(), indexes.begin() + v.size() / 2, indexes.end());
	}
	
	if (DEBUG && is_first_call) {
		std::cout << "Split vector into main chain and pending chain + pair swap:" << std::endl;
		PmergeMe::print_vector(vector_main);
		PmergeMe::print_vector(vector_pending);
	}

	std::vector<int> subIndexes;
	for (unsigned long i = 0; i < vector_main.size(); i++) {
		subIndexes.push_back(i);
	}

	PmergeMe::_recursively_sort_vector(vector_main, subIndexes);
	PmergeMe::_rearrange_vector(vector_pending, subIndexes);
	if (!is_first_call) {
		PmergeMe::_rearrange_vector(index_main, subIndexes);
		PmergeMe::_rearrange_vector(index_pending, subIndexes);
	}

	// DEBUG
	if (DEBUG && is_first_call) {
		std::cout << "\nMain and pending vectors after recursive sort:" << std::endl;
		PmergeMe::print_vector(vector_main);
		PmergeMe::print_vector(vector_pending);
	}
	PmergeMe::_binary_search_insert_vector(vector_main, vector_pending, index_main, index_pending);
	v = vector_main;
	indexes = index_main;

	return;
}

void PmergeMe::_rearrange_vector(std::vector<int>& v, std::vector<int>& indexes) {
	std::vector<int> v_copy = v;
	for (unsigned long i = 0; i < indexes.size(); i++) {
		v[i] = v_copy[indexes[i]];
	}

	return;
}

// Binary insert with jacobsthal sequence
void PmergeMe::_binary_search_insert_vector(std::vector<int>& vector_main, std::vector<int>& vector_pending, std::vector<int>& index_main, std::vector<int>& index_pending) {
	bool is_first_call = index_main.empty();

	std::vector<unsigned long>	jacobstal_sequence;
	std::vector<long>			max_chain_size; // to insert into
	unsigned long				previous_jacobstal = 1;
	long						insert_size; // size of chain to insert into
	std::vector<int>::iterator	it; // position before which to insert
	
	jacobstal_sequence.push_back(1);
	max_chain_size.push_back(1);
	// Generate needed Jacobsthal sequence and maxChainSize
	while (jacobstal_sequence.back() < vector_pending.size())
	{
		jacobstal_sequence.push_back(jacobstal_sequence.back() + 2 * previous_jacobstal);
		previous_jacobstal = *(jacobstal_sequence.end() - 2);
		max_chain_size.push_back((max_chain_size.back() + 1) * 2 - 1); //2^n - 1
	}

	for (unsigned long j = 0; j < jacobstal_sequence.size(); j++)
	{
		previous_jacobstal = (jacobstal_sequence[j] == 1) ? 0 : jacobstal_sequence[j - 1];
		for (unsigned long i = jacobstal_sequence[j]; i > previous_jacobstal; i--) {
			if (i > vector_pending.size()) {
				continue;
			}
			
			insert_size = std::min(vector_main.end() - vector_main.begin(), max_chain_size[j]);
			if (DEBUG && is_first_call) {
				std::cout << "\nInserting pend element " <<  vector_pending[i - 1] << " into sub main chain of length " << insert_size << ":" << std::endl;
			}
			
			// First insert needs no comparison.
			if (i == 1) {
				it = vector_main.begin();	
			} else {
				// lower_bound performs binary search. 
				// need second iterator to pass bound.
				it = std::lower_bound(vector_main.begin(), vector_main.begin() + insert_size, vector_pending[i - 1]);
			}

			if (!is_first_call) {
				index_main.insert(index_main.begin() + std::distance(vector_main.begin(), it), index_pending[i - 1]);
			}
			vector_main.insert(it, vector_pending[i - 1]);
			
			if (DEBUG && is_first_call) {
				PmergeMe::print_vector(vector_main);
				PmergeMe::print_vector(vector_pending);
			}
		}
	}
	return;
}



// DEQUE VERSION

void PmergeMe::parse_input_deque(char** input) {
	char*	endptr = NULL;
	long	temp;
	int		number;

	while (*input && **input) {
		temp = strtol(*input, &endptr, 10);
		if (*endptr) {
			throw std::invalid_argument("Error: not a number.");
		}
		if (temp <= 0) {
			throw std::invalid_argument("Error: accepts only strictly positive numbers.");
		}
		if (temp > INT_MAX) {
			throw std::invalid_argument("Error: int overflow.");
		}
		number = static_cast<int>(temp);
		this->_deque.push_back(number);
		++input;
	}
	if (this->_deque.size() == 0) {
		throw std::invalid_argument("Error: empty sequence.");
	}

	return;
}

void PmergeMe::print_deque(std::deque<int> const& d) {
	std::deque<int>::const_iterator	it;
	for (it = d.begin(); it != d.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return;
}

void PmergeMe::sort_deque(void) {
	std::deque<int> d = this->_deque; // create copy
	std::deque<int> indexes; // not useful in 1st call but needed in recurrence 

	PmergeMe::_recursively_sort_vector(d, indexes); // recursively sort copy
	this->_deque = d; // replace original
	return;
}

void PmergeMe::_recursively_sort_vector(std::deque<int>& d, std::deque<int>& indexes) {
	bool is_first_call = indexes.empty();

	if (d.size() == 1) {
		return;
	}

	/* 	Virtually split into two equal-length segments (odd element unused if any)
		Virtually pair i-th element of each segment and make comparison
		Swap to have elements in first segment >= corresponding elements in second segment */
	
	std::deque<int>::iterator it1 = d.begin(); // Points to beginning of first segment.
	std::deque<int>::iterator it2 = it1 + d.size() / 2; // Point to beginning of second segment.
	std::deque<int>::iterator itInd1; // Same for index sequence.
	std::deque<int>::iterator itInd2;
	if (!is_first_call) {
		itInd1 = indexes.begin(); // Same for index sequence.
		itInd2 = itInd1 + d.size() / 2;
	}
	
	for (unsigned long j = 0; j < d.size() / 2; ++j) {
		if (*it2 > *it1) {
			std::iter_swap(it1, it2);
			if (!is_first_call) {
				std::iter_swap(itInd1, itInd2);
			}
		}
		++it1;
		++it2;
		if (!is_first_call) {
			++itInd1;
			++itInd2;
		}
	}
	
	// Split main and pending parts for both deque and indexes.
	std::deque<int> deque_main(d.begin(), d.begin() + d.size() / 2);
	std::deque<int> deque_pending(d.begin() + d.size() / 2, d.end());
	std::deque<int> indexes_main;
	std::deque<int> indexes_pending;

	if (!is_first_call) {
		indexes_main.insert(indexes_main.end(), indexes.begin(), indexes.begin() + d.size() / 2);
		indexes_pending.insert(indexes_pending.end(), indexes.begin() + d.size() / 2, indexes.end());
	}
	
	if (DEBUG && is_first_call) {
		std::cout << "Split deque into main chain and pending chain + pair swap:" << std::endl;
		PmergeMe::print_deque(deque_main);
		PmergeMe::print_deque(deque_pending);
	}

	std::deque<int> subIndexes;
	for (unsigned long i = 0; i < deque_main.size(); i++) {
		subIndexes.push_back(i);
	}
	PmergeMe::_recursively_sort_vector(deque_main, subIndexes);
	PmergeMe::_rearrange_deque(deque_pending, subIndexes);
	if (!is_first_call) {
		PmergeMe::_rearrange_deque(indexes_main, subIndexes);
		PmergeMe::_rearrange_deque(indexes_pending, subIndexes);
	}

	if (DEBUG && is_first_call) {
		std::cout << "\nMain and pend and after recursive sort:" << std::endl;
		PmergeMe::print_deque(deque_main);
		PmergeMe::print_deque(deque_pending);
	}
	PmergeMe::_binary_search_insert_deque(deque_main, deque_pending, indexes_main, indexes_pending);
	d = deque_main;
	indexes = indexes_main;

	return;
}

void PmergeMe::_rearrange_deque(std::deque<int>& deque, std::deque<int>& indexes) {
	std::deque<int> deque_copy = deque;
	for (unsigned long i = 0; i < indexes.size(); i++) {
		deque[i] = deque_copy[indexes[i]];
	}
	return;
}

// Binary insert with jacobsthal sequence
void PmergeMe::_binary_search_insert_deque(std::deque<int>& deque_main, std::deque<int>& deque_pending, std::deque<int>& index_main, std::deque<int>& index_pending) {
	bool is_first_call = index_main.empty();

	std::deque<unsigned long>	jacobsthal_sequence;
	std::deque<long>			max_chain_size; // To insert into.
	unsigned long				previous_jacobsthal = 1;
	long						insert_size; // Size of chain to insert into.
	std::deque<int>::iterator	it; // Position before which to insert.
	
	jacobsthal_sequence.push_back(1);
	max_chain_size.push_back(1);
	// Generate needed Jacobsthal sequence and maxChainSize.
	while (jacobsthal_sequence.back() < deque_pending.size()) {
		jacobsthal_sequence.push_back(jacobsthal_sequence.back() + 2 * previous_jacobsthal);
		previous_jacobsthal = *(jacobsthal_sequence.end() - 2);
		max_chain_size.push_back((max_chain_size.back() + 1) * 2 - 1); //2^n - 1
	}

	for (unsigned long j = 0; j < jacobsthal_sequence.size(); ++j) {
		previous_jacobsthal = (jacobsthal_sequence[j] == 1) ? 0 : jacobsthal_sequence[j - 1];
		for (unsigned long i = jacobsthal_sequence[j]; i > previous_jacobsthal; i--) {
			if (i > deque_pending.size()) {
				continue;
			}
			
			insert_size = std::min(deque_main.end() - deque_main.begin(), max_chain_size[j]);
			if (DEBUG && is_first_call) {
				std::cout << "\nInserting pend element " <<  deque_pending[i - 1] << " into sub main chain of length " << insert_size << ":" << std::endl;
			}
			
			// Very first insert need no comparison
			if (i == 1) {
				it = deque_main.begin();	
			}
			else {
				// Lower_bound performs binary search
				// need 2nd it to pass bound
				it = std::lower_bound(deque_main.begin(), deque_main.begin() + insert_size, deque_pending[i - 1]);
			}

			if (!is_first_call) {
				index_main.insert(index_main.begin() + std::distance(deque_main.begin(), it), index_pending[i - 1]);
			}
			deque_main.insert(it, deque_pending[i - 1]);
			
			if (DEBUG && is_first_call) {
				PmergeMe::print_deque(deque_main);
				PmergeMe::print_deque(deque_pending);
			}
		}
	}

	return;
}

