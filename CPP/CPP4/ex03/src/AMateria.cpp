#include "../inc/AMateria.hpp"

AMateria::AMateria() : _type("Default Materia")
{
}

AMateria::AMateria(str const &type) : _type(type)
{
}

AMateria::AMateria(const AMateria& copy) : _type(copy.getType())
{
}

AMateria& AMateria::operator=(const AMateria& copy)
{
	if (this != &copy)
		this->_type = copy.getType();
	return *this;
}

AMateria::~AMateria()
{
}

str const& AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << YELLOW << "Default attack" << RESET << " on " << PURPLE << target.getName() << RESET << std::endl;
}
