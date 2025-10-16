#ifndef GRADE_TOO_HIGH_EXCEPTION_HPP
#define GRADE_TOO_HIGH_EXCEPTION_HPP

#include <exception>
#include <string>

class GradeTooHighException : public std::exception {
private:
	std::string msg_;

public:
	GradeTooHighException(const std::string& message) : msg_(message) {}
	virtual ~GradeTooHighException() throw() {}
	
	virtual const char* what() const throw() {
		return msg_.c_str();
	}
};

#endif
