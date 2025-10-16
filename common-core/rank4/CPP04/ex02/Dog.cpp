#include "include/Dog.hpp"
#include <iostream>

Dog::Dog() {
	type = "dog";
	brain = new Brain;
	std::cout << "Default constructor called, dog was created!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	type = other.type;
	brain = new Brain(*other.brain);
	std::cout << "Copy constructor called for dog" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
		std::cout << "Copy assignment operator called for dog" << std::endl;

	}
	return *this;
}


Dog::~Dog() {
	delete brain;
	std::cout << "Destructor called : dog was destroyed!" << std::endl;
}

std::string Dog::getType() const {
	return (type);
}

void Dog::makeSound() const {
	std::cout << "Dog make a sound : woof woof" << std::endl;
}

int Dog::addIdea(std::string str) {
	return brain->addIdea(str);
}

void Dog::forgetIdea(int i) {
	brain->forgetIdea(i);
}

std::string Dog::getIdea(int i) const {
	return brain->getIdea(i);
}