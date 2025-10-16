#include "include/Animal.hpp"
#include "include/WrongAnimal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const WrongCat* i = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	return 0;
}