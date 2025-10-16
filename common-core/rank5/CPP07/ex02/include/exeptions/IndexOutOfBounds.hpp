#ifndef INDEX_OUT_OF_BOUNDS_HPP
#define INDEX_OUT_OF_BOUNDS_HPP

#include <exception>
#include <string>

class IndexOutOfBounds : public std::exception {
private:
	std::string msg_;

public:
	IndexOutOfBounds() : msg_("IndexOutOfBounds") {}
	IndexOutOfBounds(const std::string& message) : msg_(message) {}
	virtual ~IndexOutOfBounds() throw() {}
	
	virtual const char* what() const throw() {
		return msg_.c_str();
	}
};

#endif
