#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"
#include "exceptions/GradeTooHighException.hpp"
#include "exceptions/GradeTooLowException.hpp"
#include "exceptions/FormAlreadySigned.hpp"

class Bureaucrat;

class Form {
private:
	const std::string name;
	bool sign;
	const int grade_sign;
	const int grade_exec;

public:
	Form(std::string name, int grade_s, int grade_e);
	Form(const Form&);
	Form& operator=(const Form&);
	~Form();

	void beSigned(const Bureaucrat& b);

	std::string getName() const;
	bool getSigned() const;
	int getGrade_sign() const;
	int getGrade_exec() const;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
