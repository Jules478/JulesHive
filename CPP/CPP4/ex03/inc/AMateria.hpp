#pragma once

#include <iostream>
#include "ICharacter.hpp"

# define RED "\e[0;31m"
# define BLUE "\e[0;34m"
# define GREEN "\e[0;32m"
# define PURPLE "\e[0;35m"
# define YELLOW "\e[0;33m"
# define RESET "\e[0m"

typedef std::string str;

class AMateria
{
	protected:
			str _type;

	public:
			AMateria();
			AMateria(str const &type);
			AMateria(const AMateria& copy);
			AMateria& operator=(const AMateria& copy);
			virtual ~AMateria();

			str const &getType() const;
			virtual AMateria* clone() const = 0;
			virtual void use(ICharacter& target);
};