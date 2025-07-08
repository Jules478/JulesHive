#include "../inc/Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure& copy) : AMateria(copy)
{
}

Cure& Cure::operator=(const Cure& copy)
{
	if (this != &copy)
		this->_type = copy.getType();
	return *this;
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "*" << GREEN << " heals " << PURPLE << target.getName() << RESET << "'s wounds *" << std::endl;
}