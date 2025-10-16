#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain* brain;

public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	virtual ~Dog();

	void makeSound() const;
	std::string getType() const;

	int addIdea(std::string str);
	void forgetIdea(int i);
	std::string getIdea(int i) const;
};

#endif