#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

class ValueNotFoundException : public std::exception {
	public:
		const char * what() const throw() {
			return "Error: There wasn't a match for the provided value.";
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	for (typename T::iterator iterator = container.begin(); iterator != container.end(); ++iterator) {
		if (*iterator == value) {
			return iterator;
		}
	}

	throw ValueNotFoundException();
}

#endif
