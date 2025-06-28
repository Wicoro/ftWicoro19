#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
	std::string type;

public:
   Weapon();
   Weapon(std::string type);

   Weapon(const Weapon& other);
   Weapon& operator=(const Weapon& other);
   ~Weapon();

   void setType(std::string type);
   std::string getType();
};

#endif
