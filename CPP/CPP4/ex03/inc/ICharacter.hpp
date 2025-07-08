#pragma once

#include <iostream>
#include "AMateria.hpp"

typedef std::string str;

class AMateria;

class ICharacter
{
	public:
			virtual ~ICharacter() {}
			
			virtual str const &getName() const = 0;
			virtual void equip(AMateria* m) = 0;
			virtual void unequip(int idx) = 0;
			virtual void use(int idx, ICharacter& target) = 0;
			virtual AMateria* getMateria(int idx) const = 0;
};