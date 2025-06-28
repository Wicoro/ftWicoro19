#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	return new Zombie(name);
}

void randomChump(std::string name) {
	Zombie zombie(name);
	zombie.announce();
}

int	main()
{
	Zombie* zombie1 = newZombie("Foo");
	zombie1->announce();

	randomChump("Bar");

	Zombie zombie2 = *zombie1;
	zombie2.announce();

	Zombie zombie3("Temp");
	zombie3 = *zombie1;
	zombie3.announce();

	delete(zombie1);

	return (0);
}