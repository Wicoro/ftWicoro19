#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria* inv[4];

		AMateria* floor[100];
		int floorCount;

		void dropMateria(AMateria *m);

	public:
		Character();
		Character(std::string n);
		Character(const Character& other);
		Character& operator=(const Character& other);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif