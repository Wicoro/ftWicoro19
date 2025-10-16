#ifndef FORM_ALREADY_SIGNED_HPP
#define FORM_ALREADY_SIGNED_HPP

#include <exception>
#include <string>

class FormAlreadySigned : public std::exception {
private:
	std::string msg_;

public:
	FormAlreadySigned(const std::string& message) : msg_(message) {}
	virtual ~FormAlreadySigned() throw() {}
	
	virtual const char* what() const throw() {
		return msg_.c_str();
	}
};

#endif
