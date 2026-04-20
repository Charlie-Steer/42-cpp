#include "Span.hpp"
#include <algorithm>
#include <numeric>

Span::Span() : length(0) {}

Span::Span(unsigned int n) : length(n) {}

Span::Span(const Span &other) {
	*this = other;
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		this->length = other.length;
		this->data = other.data;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (data.size() >= length)
		throw FullSpanException();
	data.push_back(number);
}

long Span::longestSpan() const {
	if (data.size() < 2)
		throw NoSpanException();

	int min = *std::min_element(data.begin(), data.end());
	int max = *std::max_element(data.begin(), data.end());

	return static_cast<long>(max) - static_cast<long>(min);
}

long Span::shortestSpan() const {
	if (data.size() < 2)
		throw NoSpanException();

	std::vector<int> tmp = data;
	std::sort(tmp.begin(), tmp.end());

	std::vector<long> diffs(tmp.size());
	std::adjacent_difference(tmp.begin(), tmp.end(), diffs.begin());
	return *std::min_element(diffs.begin() + 1, diffs.end());
}
