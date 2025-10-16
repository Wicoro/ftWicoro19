#include <iostream>
#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"

int main() {
	std::cout << "=== FORM EXECUTION TESTS ===\n" << std::endl;

	// ✅ Shrubbery: Success
	std::cout << "[✅ Shrubbery: Sign & Execute Successfully]" << std::endl;
	try {
		Bureaucrat signer("Bob", 140);
		Bureaucrat executor("Alice", 130);
		ShrubberyCreationForm shrub("garden");

		signer.signForm(shrub);
		executor.executeForm(shrub);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// ❌ Shrubbery: Fail to execute (form not signed)
	std::cout << "\n[❌ Shrubbery: Try to Execute Without Signing]" << std::endl;
	try {
		Bureaucrat executor("Charlie", 130);
		ShrubberyCreationForm shrub("forest");

		executor.executeForm(shrub); // should fail
	} catch (std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	// ❌ Shrubbery: Sign too low
	std::cout << "\n[❌ Shrubbery: Sign Attempt by Low-Level Bureaucrat]" << std::endl;
	try {
		Bureaucrat lowSigner("Dan", 146); // Grade too low to sign
		ShrubberyCreationForm shrub("yard");

		lowSigner.signForm(shrub); // should fail
	} catch (std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	// ❌ Shrubbery: Execute too low
	std::cout << "\n[❌ Shrubbery: Execute Attempt by Low-Level Bureaucrat]" << std::endl;
	try {
		Bureaucrat signer("Eve", 140);
		Bureaucrat lowExec("Frank", 145); // Too low to execute
		ShrubberyCreationForm shrub("lawn");

		signer.signForm(shrub); // Should succeed
		lowExec.executeForm(shrub); // Should fail
	} catch (std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	// ✅ Robotomy: Random success/failure
	std::cout << "\n[✅ Robotomy: Execute with 50% Chance]" << std::endl;
	try {
		Bureaucrat rick("Rick", 72);
		Bureaucrat morty("Morty", 45);
		RobotomyRequestForm rform("Bender");

		rick.signForm(rform);
		morty.executeForm(rform);
	} catch (std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	// ❌ Presidential: Sign or execute too low
	std::cout << "\n[❌ Presidential: Insufficient Permissions]" << std::endl;
	try {
		Bureaucrat intern("Intern", 50);
		PresidentialPardonForm pform("Ford");

		intern.signForm(pform); // too low (needs <= 25)
		intern.executeForm(pform); // should also fail
	} catch (std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	// ✅ Presidential: Success
	std::cout << "\n[✅ Presidential: Sign & Execute Successfully]" << std::endl;
	try {
		Bureaucrat prez("Zaphod", 1);
		PresidentialPardonForm pform("Trillian");

		prez.signForm(pform);
		prez.executeForm(pform);
	} catch (std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== END OF TESTS ===" << std::endl;
	return 0;
}
