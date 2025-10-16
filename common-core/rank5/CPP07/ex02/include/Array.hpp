#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string.h>
#include <iostream>

#include "exeptions/IndexOutOfBounds.hpp"

template <typename T>
class Array {
	private:
		T				*_array;
		unsigned int	_a_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array&);
		Array& operator=(const Array&);
		~Array();

		T& operator[](const unsigned int i);
		unsigned int size() const;
};

template <typename T>
Array<T>::Array(void) : _array(NULL), _a_size(0) {};

template <typename T>
Array<T>::Array(const unsigned int i) : _array(NULL), _a_size(i) {
	_array = new T[_a_size];
}

template <typename T>
Array<T>::Array(const Array& other) : _array(NULL), _a_size(other._a_size) {
	_array = new T[_a_size];
	for (unsigned int i = 0; i < _a_size; i++) {
		_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>::~Array() {
    delete[] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this == &other)
		return *this;
	delete[] _array;
	_a_size = other._a_size;
	_array = new T[_a_size];
	for (unsigned int i = 0; i < _a_size; i++) {
		_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
unsigned int Array<T>::size() const {
	return (_a_size);
}


template <typename T>
T& Array<T>::operator[](const unsigned int i) {
    if (i < _a_size)
        return _array[i];
    throw IndexOutOfBounds();
}


#endif