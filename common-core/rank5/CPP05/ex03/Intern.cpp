#include "include/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) {
	Dictionnary pairs[] = {
		{"shrubbery creation",  &Intern::createShrubbery},
		{"robotomy request",    &Intern::createRobotomy},
		{"presidential pardon", &Intern::createPresidential}
	};

	for (int i = 0; i < 3; ++i) {
		if (formName == pairs[i].name) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*pairs[i].create)(target);
		}
	}
	throw FormNotFound("Form not found");
}
