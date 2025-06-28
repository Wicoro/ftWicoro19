#include "include/FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    this->hp = 100;
    this->stamina = 100;
    this->ad = 30;
    
    std::cout << "FragTrap " << this->name << " is born!" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->name << " is destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    std::cout << "FragTrap " << this->name << " attacks " << target
              << ", causing " << this->ad << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->name << " requests a high five!" << std::endl;
}