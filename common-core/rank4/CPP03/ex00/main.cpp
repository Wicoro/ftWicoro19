#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap a("alpha");
	ClapTrap b("beta");
	ClapTrap c("gamma");

	a.attack("target 1");
	b.attack("target 2");
	c.takeDamage(9);
	c.beRepaired(3);
}