#pragma once

#include <iostream>
#include "AMateria.hpp"

typedef std::string str;

class IMateriaSource
{
	protected:
			str _type;

	public:
			virtual ~IMateriaSource() {}

			virtual void learnMateria(AMateria*) = 0;
			virtual AMateria* createMateria(str const & type) = 0;
};