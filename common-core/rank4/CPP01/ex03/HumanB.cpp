#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB() : name("Unnamed"), weapon(NULL) {}

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

HumanB::HumanB(std::string name, Weapon& weapon) : name(name), weapon(&weapon) {}

HumanB::HumanB(const HumanB& other) : name(other.name), weapon(other.weapon) {
	std::cout << "Copy constructor called for " << other.name << std::endl;
}

HumanB& HumanB::operator=(const HumanB& other) {
	if (this != &other) {
		name = other.name;
		std::cout << "Copy assignment operator called for " << other.name << std::endl;
	}
	return *this;
}

HumanB::~HumanB() {
	std::cout << name << " is behind peashotted away\n";
}

void HumanB::setWeapon(Weapon& newWeapon) {
	weapon = &newWeapon;
}

void HumanB::attack() {
	if (&weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon to attack with!" << std::endl;
}