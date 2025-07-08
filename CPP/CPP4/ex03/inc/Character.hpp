#pragma once

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
			str _name;
			AMateria* _inv[4];

	public:
			Character();
			Character(str name);
			Character(const Character& copy);
			Character& operator=(const Character& copy);
			~Character();

			void equip(AMateria* m);
			void unequip(int idx);
			void use(int idx, ICharacter& target);

			const str& getName() const;
			AMateria* getMateria(int idx) const;
};