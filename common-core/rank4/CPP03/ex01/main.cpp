#include "ScavTrap.hpp"
#include <iostream>

int main() {
	std::cout << "=== Creating ScavTrap ===\n";
	ScavTrap scav("Jack");

	std::cout << "\n=== Performing Actions ===\n";
	scav.attack("Bandit");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();

	std::cout << "\n=== Exiting Program ===\n";
	return 0;
}