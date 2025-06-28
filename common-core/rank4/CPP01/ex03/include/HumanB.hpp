#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
private:
	std::string name;
	Weapon* weapon;

public:
	HumanB();
	HumanB(std::string name);
	HumanB(std::string name, Weapon& weapon);

	HumanB(const HumanB& other);
	HumanB& operator=(const HumanB& other);
	~HumanB();

	void setWeapon(Weapon& weapon);
	void attack();
};

#endif
