#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

HumanA::HumanA(const HumanA& other) : name(other.name), weapon(other.weapon) {
	std::cout << "Copy constructor called for " << other.name << std::endl;
}

HumanA& HumanA::operator=(const HumanA& other) {
	if (this != &other) {
		name = other.name;
		std::cout << "Copy assignment operator called for " << other.name << std::endl;
	}
	return *this;
}

HumanA::~HumanA() {
	std::cout << name << " is behind peashotted away\n";
}

void HumanA::attack() {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}