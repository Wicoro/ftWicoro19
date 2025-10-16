#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character() : name("Unnamed"), floorCount(0) {
    for (int i = 0; i < 4; ++i) {
        inv[i] = 0;
	}
	for (int i = 0; i < 100; ++i) {
    	floor[i] = 0;
	}

}

Character::Character(std::string n) : name(n), floorCount(0) {
    for (int i = 0; i < 4; ++i) {
        inv[i] = 0;
	}
	for (int i = 0; i < 100; ++i) {
    	floor[i] = 0;
	}
}

Character::Character(const Character& other) : name(other.name), floorCount(other.floorCount) {
    for (int i = 0; i < 4; ++i) {
        if (other.inv[i])
            inv[i] = other.inv[i]->clone();
        else
            inv[i] = 0;
    }
	for (int i = 0; i < 100; ++i) {
        if (other.floor[i])
            floor[i] = other.floor[i]->clone();
        else
            floor[i] = 0;
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
		floorCount = other.floorCount;
        for (int i = 0; i < 4; ++i) {
            delete inv[i];
            if (other.inv[i])
                inv[i] = other.inv[i]->clone();
            else
                inv[i] = 0;
        }
		for (int i = 0; i < 100; ++i) {
        if (other.floor[i])
            floor[i] = other.floor[i]->clone();
        else
            floor[i] = 0;
    	}
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; ++i) {
        delete inv[i];
	}
	for (int i = 0; i < floorCount; ++i) {
        delete floor[i];
	}
	std::cout << "Destroying Character " << this->getName() << std::endl; 
}

std::string const & Character::getName() const {
    return name;
}

void Character::dropMateria(AMateria* m) {
    if (!m || floorCount >= 100)
        return;

    floor[floorCount++] = m;
}

void Character::equip(AMateria* m) {
	 for (int i = 0; i < 4; ++i) {
		if (inv[i] == 0) {
			inv[i] = m;
			return ;
		}
	 }
	 dropMateria(m);
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && inv[idx]) {
		AMateria *ref = inv[idx];
		dropMateria(ref);
        inv[idx] = 0;
    }

}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && inv[idx]) {
		AMateria *ref = inv[idx];
		ref->use(target);
		delete(ref);
		inv[idx] = 0;
	}
}


