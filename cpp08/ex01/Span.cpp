#include "Span.hpp"
#include <algorithm>

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

	long min_diff = -1;
	for (size_t i = 0; i < tmp.size() - 1; ++i) {
		long diff = static_cast<long>(tmp[i + 1]) - static_cast<long>(tmp[i]);
		if (min_diff == -1 || diff < min_diff) {
			min_diff = diff;
		}
	}

	return min_diff;
}
