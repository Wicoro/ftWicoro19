#ifndef FORM_NOT_FOUND_HPP
#define FORM_NOT_FOUND_HPP

#include <exception>
#include <string>

class FormNotFound : public std::exception {
private:
	std::string msg_;

public:
	FormNotFound(const std::string& message) : msg_(message) {}
	virtual ~FormNotFound() throw() {}
	
	virtual const char* what() const throw() {
		return msg_.c_str();
	}
};

#endif
