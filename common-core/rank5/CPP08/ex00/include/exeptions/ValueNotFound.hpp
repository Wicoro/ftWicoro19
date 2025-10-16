#ifndef VALUE_NOT_FOUND_HPP
#define VALUE_NOT_FOUND_HPP

#include <exception>
#include <string>

class ValueNotFound : public std::exception {
private:
	std::string msg_;

public:
	ValueNotFound() : msg_("ValueNotFound") {}
	ValueNotFound(const std::string& message) : msg_(message) {}
	virtual ~ValueNotFound() throw() {}
	
	virtual const char* what() const throw() {
		return msg_.c_str();
	}
};

#endif
