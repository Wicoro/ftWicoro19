#include "include/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string name) : name(name), hp(10), stamina(10), ad(0) {
	std::cout << "Default constructor called " << name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name) {
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called : " << name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (hp > 0 && stamina > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << ad << " points of damage!" << std::endl;
		stamina--;
	}
	else if (hp <= 0)
		std::cout << "ClapTrap " << name << " do not have any HP left" << std::endl;
	else if (stamina <= 0)
		std::cout << "ClapTrap " << name << " do not have any stamina left" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hp < 0)
		std::cout << "ClapTrap " << name << " is already at 0HP" << std::endl;
	hp -= amount;
	if (hp < 0)
		hp = 0;
	std::cout << "ClapTrap " << name << " took " << amount << " damage and now has " << hp << "HP" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hp > 0 && stamina > 0)
	{
		hp += amount; 
		std::cout << "ClapTrap " << name << " repair itself for " << amount << "HP, and now has " << hp << "HP!" << std::endl;
		stamina--;
	}
	else if (hp <= 0)
		std::cout << "ClapTrap " << name << " do not have any HP left" << std::endl;
	else if (stamina <= 0)
		std::cout << "ClapTrap " << name << " do not have any stamina left" << std::endl;
}