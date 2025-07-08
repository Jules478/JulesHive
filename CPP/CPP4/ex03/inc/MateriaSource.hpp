#pragma once

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

typedef std::string str;

class MateriaSource : public IMateriaSource
{
	protected:
			str _type;
			AMateria* _inv[4];

	public:
			MateriaSource();
			MateriaSource(str const & type);
			MateriaSource(const MateriaSource& copy);
			MateriaSource& operator=(const MateriaSource& copy);
			~MateriaSource();

			void learnMateria(AMateria* m);
			AMateria* createMateria(str const & type);
};