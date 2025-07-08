#pragma once

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
			Ice();
			Ice(const Ice& copy);
			Ice& operator=(const Ice& copy);
			~Ice();

			AMateria* clone() const;
			void use(ICharacter& target);
};