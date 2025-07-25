#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "../include/ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap(const std::string& name);
	~FragTrap();

	void attack(const std::string& target);
	void highFivesGuys(void);
};

#endif