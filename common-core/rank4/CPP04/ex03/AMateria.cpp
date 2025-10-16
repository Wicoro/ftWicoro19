#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria& other) : type(other.type) {}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

AMateria::~AMateria() {
	std::cout << "Destroying AMateria " << this->getType() << std::endl; 
}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
}
