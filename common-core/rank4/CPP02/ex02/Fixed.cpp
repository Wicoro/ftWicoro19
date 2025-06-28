#include "include/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : val(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int intVal) {
	std::cout << "Int constructor called\n";
	val = intVal << fractional_bit;
}

Fixed::Fixed(const float floatVal) {
	std::cout << "Float constructor called\n";
	val = roundf(floatVal * (1 << fractional_bit));
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

float Fixed::toFloat(void) const {
	return static_cast<float>(val) / (1 << fractional_bit);
}

int Fixed::toInt(void) const {
	return val >> fractional_bit;
}

bool Fixed::operator>(const Fixed& other) const {
    return val > other.val;
}

bool Fixed::operator<(const Fixed& other) const {
    return val < other.val;
}

bool Fixed::operator>=(const Fixed& other) const {
    return val >= other.val;
}

bool Fixed::operator<=(const Fixed& other) const {
    return val <= other.val;
}

bool Fixed::operator==(const Fixed& other) const {
    return val == other.val;
}

bool Fixed::operator!=(const Fixed& other) const {
    return val != other.val;
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.val == 0) {
        std::cerr << "Division by zero error!" << std::endl;
        return Fixed();
    }
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    val += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    val -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --(*this);
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& value) {
	out << value.toFloat();
	return out;
}