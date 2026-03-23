#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T, typename F>
void iter(T *array, size_t length, F function) {
	if (!array || !function) {
		return;
	}
	for (size_t idx = 0; idx < length; idx++) {
		function(array[idx]);
	}
}

// A simple function to print an element
template <typename T>
void printElement(T &item) {
    std::cout << item << " ";
}

#endif
