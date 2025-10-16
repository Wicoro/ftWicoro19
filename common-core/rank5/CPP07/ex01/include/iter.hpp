#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void printType(const T &x) {
	std::cout << x << std::endl;
}

template <typename T>
void increment(T &x) {
	x++;
}

// previously 'void (*func)(T const &)' but so I can have T& const and T& for func
template <typename T, typename Func>
void iter(T arr[], int length, Func func) {
	for (int i = 0; i < length; ++i) {
		func(arr[i]);
	}
}

#endif
