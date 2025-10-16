#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Form.hpp"
#include "exceptions/GradeTooHighException.hpp"
#include "exceptions/GradeTooLowException.hpp"

class Form;

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(std::string name);
    Bureaucrat(int grade);
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
	void signForm(Form& f);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);


#endif
