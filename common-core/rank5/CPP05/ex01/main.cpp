#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat b("Michael", 0);
	} catch (const std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Jim", 151);
	} catch (const std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n";

	try {
		Form f("google", 0, 31);
	} catch (const std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}
	
	try {
		Form f("microsoft", 51, 151);
	} catch (const std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n";

	try {
		Form f("yahoo", 23, 56);
		std::cout << f << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n";

	try {
		Form f("yahoo", 23, 56);
		Bureaucrat b("Pam", 29);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
		b.signForm(f);
	} catch (const std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n";

	try {
		Form f("yahoo", 23, 56);
		Bureaucrat b("Pam", 6);
		std::cout << b << std::endl;
		b.signForm(f);
		b.signForm(f);
	} catch (const std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}
}
