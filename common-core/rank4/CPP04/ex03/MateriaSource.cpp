#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; ++i)
		learned[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; ++i) {
		if (other.learned[i])
			learned[i] = other.learned[i]->clone();
		else
			learned[i] = 0;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; ++i) {
			delete learned[i];
			if (other.learned[i])
				learned[i] = other.learned[i]->clone();
			else
				learned[i] = 0;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i)
		delete learned[i];
	std::cout << "Destroying Materia source" << std::endl; 
}


void MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < 4; ++i)
	{
		if (!learned[i])
		{
			learned[i] = materia->clone();
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; ++i)
	{
		if (learned[i] && learned[i]->getType() == type)
		{
			return learned[i]->clone();
		}
	}
	return NULL;
}
