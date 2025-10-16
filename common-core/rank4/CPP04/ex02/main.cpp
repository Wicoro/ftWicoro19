#include <iostream>
#include "include/Cat.hpp"
#include "include/Dog.hpp"


int main() {
    const int SIZE = 4;
    Animal* animals[SIZE];
	//Animal a; //Check for ex02

    for (int i = 0; i < SIZE; ++i) {
        if (i % 2 == 0)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }

    std::cout << "\n--- Animals make sounds ---\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << animals[i]->getType() << " says: ";
        animals[i]->makeSound();
    }

    Cat* catPtr = dynamic_cast<Cat*>(animals[0]);
    Dog* dogPtr = dynamic_cast<Dog*>(animals[1]);

    if (catPtr) {
        catPtr->addIdea("Catch the mouse");
        catPtr->addIdea("Sleep all day");
        std::cout << "Cat idea 0: " << catPtr->getIdea(0) << std::endl;
        std::cout << "Cat idea 1: " << catPtr->getIdea(1) << std::endl;
    }

    if (dogPtr) {
        dogPtr->addIdea("Bark loudly");
        dogPtr->addIdea("Chase the ball");
        std::cout << "Dog idea 0: " << dogPtr->getIdea(0) << std::endl;
        std::cout << "Dog idea 1: " << dogPtr->getIdea(1) << std::endl;
    }

    // Test deep copy
    std::cout << "\n--- Testing copy constructor and assignment ---\n";
    Cat* catCopy = new Cat(*catPtr);
    Dog dogCopy;
    dogCopy = *dogPtr;

    std::cout << "Copied Cat idea 0: " << catCopy->getIdea(0) << std::endl;
    std::cout << "Copied Dog idea 0: " << dogCopy.getIdea(0) << std::endl;
	delete catCopy;

	for (int i = 0; i < SIZE; ++i) {
        delete animals[i];
    }

    return 0;
}