#include "include/Cat.hpp"
#include <iostream>

Cat::Cat() {
	type = "cat";
	brain = new Brain;
	std::cout << "Default constructor called, cat was created!" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	type = other.type;
	brain = new Brain(*other.brain);
	std::cout << "Copy constructor called for cat" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
		std::cout << "Copy assignment operator called for cat" << std::endl;
	}
	return *this;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Destructor called : cat was destroyed!" << std::endl;
}

std::string Cat::getType() const {
	return (type);
}

void Cat::makeSound() const {
	std::cout << "Cat make a sound : meeeeeeoooow" << std::endl;
}

int Cat::addIdea(std::string str) {
	return brain->addIdea(str);
}

void Cat::forgetIdea(int i) {
	brain->forgetIdea(i);
}

std::string Cat::getIdea(int i) const {
	return brain->getIdea(i);
}