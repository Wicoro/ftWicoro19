#include <iostream>
#include "include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("wronganimal") {
	std::cout << "Default constructor called, missing no (wrong) was created!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
	std::cout << "Copy constructor called for wronganimal" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		std::cout << "Copy assignment operator called for wronganimal" << std::endl;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor called : wronganimal was destroyed!" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (type);
}

void WrongAnimal::makeSound() const {
	std::cout << "Wronganimal make a wrong sound : irhgeroehg9e" << std::endl;
}

