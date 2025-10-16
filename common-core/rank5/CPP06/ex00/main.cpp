#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	std::string str;

	if (argc != 2) {
		std::cout << "Invalid arg count, only use 1 argument" << std::endl;
		return (0);
	}
	str = argv[1];
	ScalarConverter::convert(str);
}