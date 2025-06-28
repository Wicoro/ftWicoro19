#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"
#include "include/FragTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== TESTING CLAPTRAP ===" << std::endl;
    
    ClapTrap clap("ClapTrap1");
    clap.attack("Target1");
    clap.takeDamage(20);
    clap.beRepaired(10);

    std::cout << "\n=== TESTING SCAVTRAP ===" << std::endl;
    
    ScavTrap scav("ScavTrap1");
    scav.attack("Target2");
    scav.takeDamage(50);
    scav.beRepaired(20);
    scav.guardGate();

    std::cout << "\n=== TESTING FRAGTRAP ===" << std::endl;
    
    FragTrap frag("FragTrap1");
    frag.attack("Target3");
    frag.takeDamage(30);
    frag.beRepaired(15);
    frag.highFivesGuys();
    
    std::cout << "\n=== TESTING FRAGTRAP MULTIPLE INSTANCES ===" << std::endl;
    
    FragTrap frag2("FragTrap2");
    frag2.attack("Target4");
    frag2.takeDamage(50);
    frag2.beRepaired(25);
    frag2.highFivesGuys();

    std::cout << "\n=== END OF TESTING ===" << std::endl;

    return 0;
}