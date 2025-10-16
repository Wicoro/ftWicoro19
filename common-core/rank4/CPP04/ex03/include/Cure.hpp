#ifndef CURE_HPP
#define CURE_HPP

#include <string>
#include "AMateria.hpp"

class Cure : public AMateria {
	protected:
		std::string type;

	public:
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		virtual ~Cure();

		std::string getType() const;

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif