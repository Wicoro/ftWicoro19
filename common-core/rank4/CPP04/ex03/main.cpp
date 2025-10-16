#include <iostream>
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
    std::cout << "== Creating MateriaSource ==" << std::endl;
    MateriaSource* source = new MateriaSource();

    std::cout << "\n== Learning Materias ==" << std::endl;
	Ice *ice = new Ice();
	Cure *cure = new Cure();
    source->learnMateria(ice);
    source->learnMateria(cure);
	delete(ice);
	delete(cure);

    std::cout << "\n== Creating Materias by type ==" << std::endl;
    AMateria* tmp1 = source->createMateria("ice");
    AMateria* tmp2 = source->createMateria("cure");
    AMateria* tmp3 = source->createMateria("fire");  // Should return 0

    if (!tmp3)
        std::cout << "Fire materia not found (as expected)." << std::endl;

    std::cout << "\n== Creating Character 'Cloud' ==" << std::endl;
    Character* cloud = new Character("Cloud");

    std::cout << "\n== Equipping Materias ==" << std::endl;
    cloud->equip(tmp1);
    cloud->equip(tmp2);

    std::cout << "\n== Using Materias ==" << std::endl;
    cloud->use(0, *cloud);
    cloud->use(1, *cloud);
    cloud->use(2, *cloud);

    std::cout << "\n== Unequipping slot 0 (Ice) ==" << std::endl;
    cloud->unequip(0);
    cloud->use(0, *cloud);

    std::cout << "\n== Re-equipping new Ice ==" << std::endl;
    AMateria* newIce = source->createMateria("ice");
    cloud->equip(newIce);
    cloud->use(0, *cloud);

    std::cout << "\n== Cleaning up ==" << std::endl;
    delete source;
    delete cloud;

    return 0;
}
