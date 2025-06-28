#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon() : type("Mace") {}

Weapon::Weapon(std::string name) : type(name) {}

Weapon::Weapon(const Weapon& other) : type(other.type) {
	std::cout << "Copy constructor called for " << other.type << std::endl;
}

Weapon& Weapon::operator=(const Weapon& other) {
	if (this != &other) {
		type = other.type;
		std::cout << "Copy assignment operator called for " << other.type << std::endl;
	}
	return *this;
}

Weapon::~Weapon() {
	std::cout << type << " is behind peashotted away\n";
}

void Weapon::setType(std::string type)
{
	this->type = type;
}

std::string Weapon::getType()
{
	return this->type;
}