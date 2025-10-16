#include "./include/Array.hpp"

int main(void) {
	try {
		Array<int> a(4);
		a[0] = 1;
		a[1] = 2;
		a[2] = 3;
		a[3] = 4;
		std::cout << a[1] << std::endl;
		Array<std::string> b(4);
		b[0] = "n";
		b[1] = "j";
		b[2] = "a";
		b[3] = "o";
		std::cout << b[3] << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exeption : " << e.what() << std::endl;
	}
}