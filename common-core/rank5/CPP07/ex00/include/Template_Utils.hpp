#ifndef TEMPLATE_UTILS_HPP
#define TEMPLATE_UTILS_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T& a, T& b) {
	T tmp = b;
	b = a;
	a = tmp;
}

template <typename T>
T min(T const &a, T const &b) {
	if (b <= a)
		return b;
	return a;
}

template <typename T>
T max(T const &a, T const &b) {
	if (b >= a)
		return b;
	return a;
}

#endif