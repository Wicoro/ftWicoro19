#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
	Brain* brain;

public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	virtual ~Cat();

	void makeSound() const;
	std::string getType() const;

	int addIdea(std::string str);
	void forgetIdea(int i);
	std::string getIdea(int i) const;
};

#endif