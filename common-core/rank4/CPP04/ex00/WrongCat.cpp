#include "include/WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() {
	type = "wrongcat";
	std::cout << "Default constructor called, wrongcat was created!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	type = other.type;
	std::cout << "Copy constructor called for wrongcat" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
		type = other.type;
		std::cout << "Copy assignment operator called for wrongcat" << std::endl;
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "Destructor called : wrongcat was destroyed!" << std::endl;
}

std::string WrongCat::getType() const {
	return (type);
}

void WrongCat::makeSound() const {
	std::cout << "wrongcat make a sound : meeeeeeuh" << std::endl;
}