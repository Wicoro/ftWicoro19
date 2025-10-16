#include <iostream>
#include "include/Span.hpp"
#include <cstdlib>
#include <ctime> 

int main(void) {
	try {
		Span s(30000);
		std::srand(std::time(0));

		for (int i = 0; i < 30000; ++i) {
			s.addNumber(std::rand());
		}
		std::cout << "Shortest span = " << s.shortestSpan() << std::endl;
		std::cout << "Longuest span = " << s.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exeption caught : " << e.what() << std::endl;
	}

	try {
		Span s(10000);
		std::vector<int> randomValues;
		randomValues.reserve(10000);
		std::srand(std::time(0));

		for (int i = 0; i < 10000; ++i) {
			randomValues.push_back(std::rand());
		}

		s.addVector(randomValues);
		std::cout << "Shortest span = " << s.shortestSpan() << std::endl;
		std::cout << "Longuest span = " << s.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exeption caught : " << e.what() << std::endl;
	}
}