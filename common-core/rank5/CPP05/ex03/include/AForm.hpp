#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"
#include "exceptions/GradeTooHighException.hpp"
#include "exceptions/GradeTooLowException.hpp"
#include "exceptions/FormAlreadySigned.hpp"
#include "exceptions/FormNotSigned.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string name;
	bool sign;
	const int grade_sign;
	const int grade_exec;

public:
	AForm(std::string name, int grade_s, int grade_e);
	AForm(const AForm&);
	AForm& operator=(const AForm&);
	virtual ~AForm();

	void beSigned(const Bureaucrat& b);
	void checkExec(const Bureaucrat& b) const;
	virtual void execImplement() const = 0;
	void execute(const Bureaucrat & b) const;

	std::string getName() const;
	bool getSigned() const;
	int getGrade_sign() const;
	int getGrade_exec() const;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif