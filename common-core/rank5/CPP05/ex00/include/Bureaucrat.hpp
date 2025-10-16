#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

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

	//Exceptions
	class GradeTooHighException : public std::exception {
	private:
		std::string msg_;
	public:
		GradeTooHighException(const std::string& msg) : msg_(msg) {}
		virtual ~GradeTooHighException() throw() {}
		virtual const char* what() const throw() { return msg_.c_str(); }
	};

	class GradeTooLowException : public std::exception {
	private:
		std::string msg_;
	public:
		GradeTooLowException(const std::string& msg) : msg_(msg) {}
		virtual ~GradeTooLowException() throw() {}
		virtual const char* what() const throw() { return msg_.c_str(); }
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);


#endif
