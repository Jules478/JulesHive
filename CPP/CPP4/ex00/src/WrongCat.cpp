#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	std::cout << BLUE << "WrongCat" << RESET << " was adopted from the streets" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	this->_type = copy.getType();
	std::cout << BLUE << "WrongCat" << RESET << " made a kitten just like it" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& copy)
{
	if (this != &copy)
		this->_type = copy._type;
	std::cout << BLUE << "WrongCat" << RESET << " became another WrongCat (has science gone too far?)" << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << BLUE << "WrongCat" << RESET << " ran away" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << BLUE << "Meow!" << RESET << std::endl;
}