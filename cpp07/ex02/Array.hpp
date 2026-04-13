#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>

template <typename T>
class Array {
	private:
		T *data;
		unsigned int length;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;

		class IndexOutOfRangeException : public std::exception {
			const char * what() const throw();
		};

		unsigned int size() const;
};

template <typename T>
Array<T>::Array() : data(NULL), length(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), length(n) {}

template <typename T>
Array<T>::Array(const Array &other) : data(NULL), length(0) {
	*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
	if (this == &other) {
		return *this;
	}

	delete[] data;
	length = other.length;
	if (length == 0) {
		data = NULL;
	} else {
		data = new T[length]();
		for (unsigned int i = 0; i < length; i++) {
			data[i] = other.data[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] data;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= length) {
		throw IndexOutOfRangeException();
	} else {
		return data[index];
	}
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
	if (index >= length) {
		throw IndexOutOfRangeException();
	} else {
		return data[index];
	}
}

template <typename T>
const char *Array<T>::IndexOutOfRangeException::what() const throw() {
	return "Attempt to access array value out of bounds.";
}

template <typename T>
unsigned int Array<T>::size() const {
	return length;
}

#endif
