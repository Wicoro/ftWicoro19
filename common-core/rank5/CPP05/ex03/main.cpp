#include "include/Intern.hpp"
#include "include/Bureaucrat.hpp"
#include <iostream>

int main() {
	Intern someRandomIntern;

	try {
		AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "home");
		std::cout << *shrubbery << std::endl;

		Bureaucrat b("Dwight", 100);
		b.signForm(*shrubbery);
		b.executeForm(*shrubbery);
		delete shrubbery;
	} catch (const std::exception& e) {
		std::cerr << "Shrubbery test failed: " << e.what() << std::endl;
	}

	std::cout << "-------------------------------------\n";

	try {
		AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *robotomy << std::endl;

		Bureaucrat b("Angela", 45);
		b.signForm(*robotomy);
		b.executeForm(*robotomy);
		delete robotomy;
	} catch (const std::exception& e) {
		std::cerr << "Robotomy test failed: " << e.what() << std::endl;
	}

	std::cout << "-------------------------------------\n";

	try {
		AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Michael");
		std::cout << *pardon << std::endl;

		Bureaucrat b("Oscar", 1);
		b.signForm(*pardon);
		b.executeForm(*pardon);
		delete pardon;
	} catch (const std::exception& e) {
		std::cerr << "Pardon test failed: " << e.what() << std::endl;
	}

	std::cout << "-------------------------------------\n";

	// ❌ Invalid form test
	try {
		AForm* invalid = someRandomIntern.makeForm("coffee request", "Kitchen");
		std::cout << *invalid << std::endl;
		delete invalid;
	} catch (const std::exception& e) {
		std::cerr << "Expected error on invalid form: " << e.what() << std::endl;
	}

	return 0;
}
