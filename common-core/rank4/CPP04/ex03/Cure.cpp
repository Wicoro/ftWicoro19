#include "include/Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
	type = "cure";
}

Cure::Cure(const Cure& other) : AMateria("cure") {
	type = other.type;
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other) {
		Cure::operator=(other);
		type = other.type;
	}
	return *this;
}

Cure::~Cure() {
	std::cout << "Destroying Cure Materia" << std::endl; 
}

std::string Cure::getType() const {
	return type;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}