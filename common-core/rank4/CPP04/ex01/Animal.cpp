#include <iostream>
#include "include/Animal.hpp"

Animal::Animal() : type("Missing no") {
	std::cout << "Default constructor called, animal was created!" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "Copy constructor called for animal" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		type = other.type;
		std::cout << "Copy assignment operator called for animal" << std::endl;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Destructor called : animal was destroyed!" << std::endl;
}

std::string Animal::getType() const {
	return (type);
}

void Animal::makeSound() const {
	std::cout << "Missing no make a sound : ..." << std::endl;
}

