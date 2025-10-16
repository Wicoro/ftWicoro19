#ifndef ICE_HPP
#define ICE_HPP

#include <string>
#include "AMateria.hpp"

class Ice : public AMateria {
	protected:
		std::string type;

	public:
		Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		virtual ~Ice();

		std::string getType() const;

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif