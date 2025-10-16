#include "include/Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {
	type = "ice";
}

Ice::Ice(const Ice& other) : AMateria("ice") {
	type = other.type;
}

Ice& Ice::operator=(const Ice& other) {
	if (this != &other) {
		Ice::operator=(other);
		type = other.type;
	}
	return *this;
}

Ice::~Ice() {
	std::cout << "Destroying Ice Materia" << std::endl; 
}

std::string Ice::getType() const {
	return type;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}