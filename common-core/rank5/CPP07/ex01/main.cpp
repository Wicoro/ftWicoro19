#include "iter.hpp"

int main() {
	int int_arr[] = {1, 2, 3, 4, 5, 6, 7};
	int length = sizeof(int_arr) / sizeof(int_arr[0]);
	iter(int_arr, length, printType<int>);
	std::cout << "======\n";
	iter(int_arr, length, increment<int>);
	iter(int_arr, length, printType<int>);
	std::cout << "======\n";

	std::string str_arr[] = {"hello", "my name", "is nicolas", "and I love", "video games"};
	length = sizeof(str_arr) / sizeof(str_arr[0]);
	iter(str_arr, length, printType<std::string>);

	return 0;
}
