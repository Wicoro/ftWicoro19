#include <iostream>
#include "include/Animal.hpp"

Animal::Animal() : type("Missing no") {
	std::cout << "Default constructor called, missing no was created!" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "Copy constructor called for missing no" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		std::cout << "Copy assignment operator called for missing no" << std::endl;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Destructor called : missing no was destroyed!" << std::endl;
}

std::string Animal::getType() const {
	return (type);
}

void Animal::makeSound() const {
	std::cout << "Missing no make a sound : ..." << std::endl;
}

