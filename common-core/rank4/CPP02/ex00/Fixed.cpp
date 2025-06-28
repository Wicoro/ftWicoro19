#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : val(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other) : val(other.val) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		std::cout << "Copy assignment operator called" << std::endl;
		val = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (val);
}

void Fixed::setRawBits(const int val) {
	this->val = val;
}