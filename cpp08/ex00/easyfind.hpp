#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>

class ValueNotFoundException : public std::exception {
	public:
		const char * what() const throw() {
			return "Error: There wasn't a match for the provided value.";
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator iterator = std::find(container.begin(), container.end(), value);
	if (iterator == container.end()) {
		throw ValueNotFoundException();
	}
	return iterator;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int value) {
	typename T::const_iterator iterator = std::find(container.begin(), container.end(), value);
	if (iterator == container.end()) {
		throw ValueNotFoundException();
	}
	return iterator;
}

#endif
