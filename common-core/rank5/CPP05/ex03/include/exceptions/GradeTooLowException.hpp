#ifndef GRADE_TOO_LOW_EXCEPTION_HPP
#define GRADE_TOO_LOW_EXCEPTION_HPP

#include <exception>
#include <string>

class GradeTooLowException : public std::exception {
private:
	std::string msg_;

public:
	GradeTooLowException(const std::string& message) : msg_(message) {}
	virtual ~GradeTooLowException() throw() {}
	
	virtual const char* what() const throw() {
		return msg_.c_str();
	}
};

#endif
