#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
private:
	std::string name;
	Weapon& weapon;

public:
	HumanA(std::string name, Weapon& weapon);

	HumanA(const HumanA& other);
	HumanA& operator=(const HumanA& other);
	~HumanA();

	void attack();
};

#endif
