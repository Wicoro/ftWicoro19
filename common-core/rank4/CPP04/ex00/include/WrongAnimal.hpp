#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);
	virtual ~WrongAnimal();

	virtual void makeSound() const;
	virtual std::string getType() const;
};

#endif