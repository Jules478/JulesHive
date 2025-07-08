#include "../inc/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice& copy) : AMateria(copy)
{
}

Ice& Ice::operator=(const Ice& copy)
{
	if (this != &copy)
		this->_type = copy.getType();
	return *this;
}

Ice::~Ice()
{
}

AMateria* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an " << BLUE << "ice bolt" << RESET << " at " << PURPLE << target.getName() << RESET << " *" << std::endl;
}