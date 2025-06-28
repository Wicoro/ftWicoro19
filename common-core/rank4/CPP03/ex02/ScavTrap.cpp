#include "include/ScavTrap.hpp"
#include "iostream"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	hp = 100;
	stamina = 50;
	ad = 20;
	std::cout << "ScavTrap " << name << " constructed.\n";
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " destroyed.\n";
}

void ScavTrap::attack(const std::string& target) {
	if (stamina > 0 && hp > 0) {
		std::cout << "ScavTrap " << name << " fiercely attacks " << target
		          << ", dealing " << ad << " points of damage!\n";
		stamina--;
	} else {
		std::cout << "ScavTrap " << name << " is too weak to attack.\n";
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in Gate Keeper mode.\n";
}