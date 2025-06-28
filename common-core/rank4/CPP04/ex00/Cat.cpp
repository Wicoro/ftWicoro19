#include "include/Cat.hpp"
#include <iostream>

Cat::Cat() {
	type = "cat";
	std::cout << "Default constructor called, cat was created!" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	type = other.type;
	std::cout << "Copy constructor called for cat" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		std::cout << "Copy assignment operator called for cat" << std::endl;
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Destructor called : cat was destroyed!" << std::endl;
}

std::string Cat::getType() const {
	return (type);
}

void Cat::makeSound() const {
	std::cout << "Cat make a sound : meeeeeeoooow" << std::endl;
}