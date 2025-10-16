#ifndef FORM_NOT_SIGNED_HPP
#define FORM_NOT_SIGNED_HPP

#include <exception>
#include <string>

class FormNotSigned : public std::exception {
private:
	std::string msg_;

public:
	FormNotSigned(const std::string& message) : msg_(message) {}
	virtual ~FormNotSigned() throw() {}
	
	virtual const char* what() const throw() {
		return msg_.c_str();
	}
};

#endif
