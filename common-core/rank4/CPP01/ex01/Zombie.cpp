#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("My jungler") {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::Zombie(const Zombie& other) : name(other.name) {
	std::cout << "Copy constructor called for " << other.name << std::endl;
}

Zombie& Zombie::operator=(const Zombie& other) {
	if (this != &other) { // Check for self-assignment
		name = other.name;
		std::cout << "Copy assignment operator called for " << other.name << std::endl;
	}
	return *this;
}

Zombie::~Zombie() {
	std::cout << name << " is behind peashotted away\n";
}

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0)
		return NULL;

	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; ++i) {
		horde[i].setName(name);
	}

	return horde;
}