#include "include/Dog.hpp"
#include <iostream>

Dog::Dog() {
	type = "dog";
	std::cout << "Default constructor called, dog was created!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	type = other.type;
	std::cout << "Copy constructor called for dog" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		std::cout << "Copy assignment operator called for dog" << std::endl;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Destructor called : dog was destroyed!" << std::endl;
}

std::string Dog::getType() const {
	return (type);
}

void Dog::makeSound() const {
	std::cout << "Dog make a sound : meeeeeeoooow" << std::endl;
}