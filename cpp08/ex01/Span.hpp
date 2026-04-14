#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iterator>
#include <exception>

class Span {
	private:
		unsigned int length;
		std::vector<int> data;
		
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int number);
		long shortestSpan() const;
		long longestSpan() const;

		template <typename Iterator>
		void addNumber(Iterator begin, Iterator end) {
			if (std::distance(begin, end) + data.size() > length) {
				throw FullSpanException();
			}
			data.insert(data.end(), begin, end);
		}

		class FullSpanException : public std::exception {
			virtual const char* what() const throw() {
				return "The span is full.";
			}
		};

		class NoSpanException : public std::exception {
			virtual const char* what() const throw() {
				return "The backing container must contain at least two numbers to find a span.";
			}
		};
};

#endif
