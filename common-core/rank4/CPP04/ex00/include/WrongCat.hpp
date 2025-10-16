#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	WrongCat(const WrongCat& other);
	WrongCat& operator=(const WrongCat& other);
	virtual ~WrongCat();

	void makeSound() const;
	std::string getType() const;
};

#endif