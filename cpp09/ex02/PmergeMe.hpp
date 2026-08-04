#ifndef PMERGEME_H
#define PMERGEME_H

#include <vector>
#include <deque>

#define DEBUG 0

class PmergeMe {
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const&);
		PmergeMe& operator=(PmergeMe const&);
		~PmergeMe(void);

		void parse_input_vector(char** input);
		void sort_vector(void);
		std::vector<int> const&	get_vector(void) const; 
		static void print_vector(std::vector<int> const&);

		void parse_input_deque(char** input);
		void sort_deque(void);
		std::deque<int> const& get_deque(void) const; 
		static void	print_deque(std::deque<int> const&);
	
	private:
		static void _recursively_sort_vector(std::vector<int>& vec, std::vector<int>& indexes);
		static void _rearrange_vector(std::vector<int>& vec, std::vector<int>& indexes);
		static void _binary_search_insert_vector(std::vector<int>& vecMain, std::vector<int>& vecPend, std::vector<int>& indMain, std::vector<int>& indPend);
		
		static void _recursively_sort_vector(std::deque<int>& deq, std::deque<int>& indexes);
		static void _rearrange_deque(std::deque<int>& deq, std::deque<int>& indexes);
		static void _binary_search_insert_deque(std::deque<int>& deqMain, std::deque<int>& deqPend, std::deque<int>& indMain, std::deque<int>& indPend);

		std::vector<int> _vector;
		std::deque<int> _deque;
};

#endif
