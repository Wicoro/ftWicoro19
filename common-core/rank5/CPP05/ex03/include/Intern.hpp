#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "exceptions/FormNotFound.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern;

struct Dictionnary {
	const char* name;
	AForm* (Intern::*create)(const std::string& target);
};

class Intern {
public:
    Intern();
    Intern(const Intern&);
    Intern& operator=(const Intern&);
    ~Intern();

	AForm* makeForm(std::string formName, std::string target);
	AForm* createShrubbery(const std::string& target);
	AForm* createRobotomy(const std::string& target);
	AForm* createPresidential(const std::string& target);
};

#endif
